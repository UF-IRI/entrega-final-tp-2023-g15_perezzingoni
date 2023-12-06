#include "summary1.h"

eResultados AgregarCliente(sClientes &Clientela, sCliente Cliente){
    if(Clientela.misClientes==nullptr)
        return eResultados::ErrEspacio;

    eResultados verificar;
    verificar=BuscarCliente(Clientela,Cliente.nombre,Cliente.apellido,Cliente);
    if(verificar!=Exito)
        return eResultados::ErrExiste;

    if(Clientela.CantClientes==Clientela.CantMaxima){
        verificar = resizeClientes(Clientela,Clientela.CantClientes,Clientela.CantClientes+5);
        if (verificar!= Exito)
            return eResultados::ErrEspacio;
    }

    Clientela.misClientes[Clientela.CantClientes]=Cliente;
    return eResultados::Exito;
}

eResultados resizeClientes(sClientes &Clientela, uint tam, uint nuevoTam){
    if(Clientela.misClientes==nullptr)
        return eResultados::ErrEspacio;

    sCliente * aux=new sCliente[nuevoTam];
    int longitud = (tam < nuevoTam) ? tam: nuevoTam;

    for(int i=0;i<longitud;i++)
        aux[i] =Clientela.misClientes[i];
    delete[] Clientela.misClientes;
    Clientela.misClientes = aux;
    Clientela.CantMaxima=nuevoTam;
    return eResultados::Exito;
}

eResultados BuscarCliente(sClientes &Clientela, uint idCliente, sCliente& Cliente){
    if(Clientela.misClientes==nullptr)
        return eResultados::ErrEspacio;

    for (int i=0; i<Clientela.CantClientes;i++){
        if(Clientela.misClientes[i].idCliente==idCliente){
            Cliente=Clientela.misClientes[i];
            return eResultados::Exito;
        }
    }

    return eResultados::ErrNoExiste;
}

eResultados BuscarCliente(sClientes &Clientela, str Email, sCliente& Cliente){
    if(Clientela.misClientes==nullptr)
        return eResultados::ErrEspacio;

    for (int i=0; i<Clientela.CantClientes;i++){
        if(Clientela.misClientes[i].email==Email){
            Cliente=Clientela.misClientes[i];
            return eResultados::Exito;
        }
    }

    return eResultados::ErrNoExiste;
}

eResultados BuscarCliente(sClientes &Clientela, str Nombre, str Apellido, sCliente& Cliente){
    if(Clientela.misClientes==nullptr)
        return eResultados::ErrEspacio;

    for (int i=0; i<Clientela.CantClientes;i++){
        if(Clientela.misClientes[i].nombre==Nombre && Clientela.misClientes[i].apellido==Apellido){
            Cliente=Clientela.misClientes[i];
            return eResultados::Exito;
        }
    }

    return eResultados::ErrNoExiste;
}

eResultados ActualizarCliente(sClientes &Clientela, sCliente ClienteActualizado, sCliente Cliente){
    if(Clientela.misClientes==nullptr)
        return eResultados::ErrEspacio;

    eResultados verificar;
    verificar= BuscarCliente(Clientela,Cliente.idCliente,Cliente);
    if(verificar!=Exito)
        return eResultados::ErrNoExiste;

    for(int i=0;i<Clientela.CantClientes;i++){
        if(Clientela.misClientes[i].idCliente==Cliente.idCliente){
            Clientela.misClientes[i]=ClienteActualizado;
            return eResultados::Exito;
        }

    }

    return eResultados::Error;
}

eResultados CancelarClase(sCliente Cliente, sClase Clase, sAsistencias &misInscriptos, sClase *misClases){
    if(misClases==nullptr)
        return eResultados::ErrEspacio;
    for (int i=0;i<60;i++){
        if(Clase.idClase==misClases[i].idClase)
            ModificarCupos(misClases,1, Clase.idClase);
    }
    for(uint j=0;j<misInscriptos.cantAsistencias;j++){
        if(Cliente.idCliente==misInscriptos.misAsistencias[j].idCliente){
            for(uint k=0;k<misInscriptos.misAsistencias[j].cantInscriptos; k++){
                if(misInscriptos.misAsistencias[j].CursosInscriptos[k].idCurso==Clase.idClase){
                    for(uint a=k;a<misInscriptos.misAsistencias[j].cantInscriptos; a++){
                        misInscriptos.misAsistencias[j].CursosInscriptos[a]=misInscriptos.misAsistencias[j].CursosInscriptos[a+1];
                    }
                    misInscriptos.misAsistencias[j].cantInscriptos--;
                    return eResultados::Exito;
                }
            }
        }
    }
    return eResultados::Error;
}

eResultados ModificarCupos(sClase *misClases, int cambio, uint idClase){
    if(misClases==nullptr)
        return eResultados::ErrEspacio;
    for (int i=0;i< 60;i++){
        if(misClases[i].idClase==idClase){
            misClases[i].CupoDisponible= misClases[i].CupoDisponible+cambio;
            return eResultados::Exito;
        }
    }
    return eResultados::ErrNoExiste;
}

eResultados LeerArchivoClases(ifstream &miArchivo, sClase **misClases){
    if(!miArchivo.is_open()){
        return eResultados::ErrEspacio;
    }
    str auxidClase; //unsigned int
    str auxnombre;
    str auxhora; //double
    str auxcupoDisp; //unisgned int
    str auxcuposMax; //unsigned int

    //paso el encabezado
    str primerLinea;
    getline(miArchivo, primerLinea);

    //cuento la cantidad de líneas
    str linea;
    unsigned int longitud=0;
    int i=0;
    while(getline(miArchivo,linea))
        longitud++;

    //vuelvo al principio del archivo
    miArchivo.clear();
    miArchivo.seekg(ios::beg);
    getline(miArchivo, primerLinea);

    sClase* aux=new sClase[longitud];
    delete[] *misClases;
    *misClases=aux;

    while(getline(miArchivo, linea)){
        stringstream ss (linea);
        ss << linea;
        getline(ss,auxidClase, ',');
        aux[i].idClase=stoul(auxidClase);
        getline(ss,auxnombre, ',');
        aux[i].nombre=auxnombre;
        getline(ss,auxhora, ',');
        aux[i].horario=stod(auxhora);
        i++;
    }

    inicializarCupos(aux);

    return eResultados::Exito;
}

eResultados LeerArchivoClientes(ifstream &miArchivo, sClientes &Clientela){
    if(!miArchivo.is_open()){
        return eResultados::ErrEspacio;
    }
    str auxidCliente, auxnombre, auxapellido, auxemail, auxtelefono, auxfechaNac, auxestado;

    //paso el encabezado
    str primerLinea;
    getline(miArchivo, primerLinea);

    //cuento la cantidad de líneas
    str linea;
    unsigned int longitud=0;
    int i=0;
    while(getline(miArchivo,linea))
        longitud++;

    //vuelvo al principio del archivo
    miArchivo.seekg(ios::beg);
    getline(miArchivo, primerLinea);

    sCliente* aux=new sCliente[longitud];
    delete[] Clientela.misClientes;
    Clientela.misClientes=aux;

    while(getline(miArchivo, linea)){
        stringstream ss(linea);
        ss << linea;
        getline(ss,auxidCliente, ',');
        aux[i].idCliente=stoul(auxidCliente);
        getline(ss,auxnombre, ',');
        aux[i].nombre=auxnombre;
        getline(ss,auxapellido, ',');
        aux[i].apellido=auxapellido;
        getline(ss,auxemail, ',');
        aux[i].email=auxemail;
        getline(ss,auxtelefono, ',');
        aux[i].telefono=auxtelefono;
        getline(ss,auxfechaNac, ',');
        aux[i].fechaNac=auxfechaNac;
        getline(ss,auxestado, ',');
        aux[i].estado=stoi(auxestado);
        i++;
    }
    Clientela.CantClientes=longitud;
    Clientela.CantMaxima=longitud;

    return eResultados::Exito;
}

eResultados LeerArchivoAsistencias(ifstream &miArchivo, sAsistencias &Asistencias){
    if (!miArchivo.is_open())
        return eResultados::ErrEspacio;

    str linea;

    Asistencia *aux =new  Asistencia [250];
    delete[] Asistencias.misAsistencias;
    Asistencias.misAsistencias=aux;
    Asistencias.cantMax=250;
    Asistencias.cantAsistencias=0;

    uint aux2=0;
    while(!miArchivo.eof()){
        miArchivo.read((char *)&aux[Asistencias.cantAsistencias].idCliente, sizeof(uint));
        miArchivo.read((char *)&aux2, sizeof(uint));

        aux[Asistencias.cantAsistencias].cantInscriptos=aux2;
        Inscripcion *auxInscriptos = new Inscripcion[aux2];
        for (uint j = 0; j < aux2; j++) {
            miArchivo.read((char *)&auxInscriptos[j], sizeof(Inscripcion));
        }
        aux[Asistencias.cantAsistencias].CursosInscriptos = auxInscriptos;
        Asistencias.cantAsistencias++;
    }

    RepetidosAsist(Asistencias);

    return eResultados::Exito;
}

void RepetidosAsist(sAsistencias &Asistencias){
    for (uint i=0;i<Asistencias.cantAsistencias;i++){
        for(uint j=0; j<Asistencias.misAsistencias[i].cantInscriptos;j++){
            for(uint k=0;k<Asistencias.misAsistencias[i].cantInscriptos;k++){
                if(Asistencias.misAsistencias[j].CursosInscriptos->idCurso==Asistencias.misAsistencias[k].CursosInscriptos->idCurso){
                    Asistencias.misAsistencias[i].cantInscriptos--;
                    for(uint a=k;a<Asistencias.misAsistencias[i].cantInscriptos;a++)
                        Asistencias.misAsistencias->CursosInscriptos[a]=Asistencias.misAsistencias->CursosInscriptos[a+1];
                }
            }

        }
    }
}

void inicializarCuposConAsist(sClase *misClases, sAsistencias misAsistencias){
    for(uint i=0;i<misAsistencias.cantAsistencias;i++){
        for(uint j=0;j<misAsistencias.misAsistencias[i].cantInscriptos;j++){
            ModificarCupos(misClases,-1,misAsistencias.misAsistencias[i].CursosInscriptos[j].idCurso);
        }
    }
}

void inicializarCupos(sClase *misClases){
    //inicializa todos los cupos de las distintas clases y musculacion
    for(int i=0;i<60;i++){
        if(misClases[i].nombre=="Spinning"){
            misClases->CupoDisponible=45;
            misClases->CupoMax=45;
        }
        if(misClases[i].nombre=="Yoga"){
            misClases->CupoDisponible=25;
            misClases->CupoMax=25;
        }
        if(misClases[i].nombre=="Pilates"){
            misClases->CupoDisponible=15;
            misClases->CupoMax=15;
        }
        if(misClases[i].nombre=="Stretching"){
            misClases->CupoDisponible=40;
            misClases->CupoMax=40;
        }
        if(misClases[i].nombre=="Zumba"){
            misClases->CupoDisponible=50;
            misClases->CupoMax=50;
        }
        if(misClases[i].nombre=="Boxeo"){
            misClases->CupoDisponible=30;
            misClases->CupoMax=30;
        }
        if(misClases[i].nombre=="Musculacion"){
            misClases->CupoDisponible=30;
            misClases->CupoMax=30;
        }
    }
}

eResultados AnotarseClase(sCliente Cliente, uint idClase, sAsistencias &misAsistidos, sClase *misClases){
    if(misClases==nullptr)
        return eResultados::ErrEspacio;

    eResultados evitar;
    for(int i=0 ; i<60 ; i++){
        if(misClases[i].idClase==idClase){
            if(misClases[i].CupoDisponible==0)
                return eResultados::ErrorNoHayCupos;
            else{
                evitar= AgregarAsistencia(misAsistidos,Cliente.idCliente,idClase);
                if(evitar==Exito){
                    ModificarCupos(misClases,-1,misClases[i].idClase);
                    return eResultados::Exito;
                }else
                    return eResultados::ErrExiste;
            }
        }
    }
    return eResultados::ErrNoExiste;

}

eResultados AgregarAsistencia(sAsistencias &misAsistidos,uint idCliente,uint idClase){
    for (uint i=0;i<misAsistidos.cantAsistencias;i++){
        if(misAsistidos.misAsistencias[i].idCliente==idCliente){
            for(uint j = 0;j<misAsistidos.misAsistencias[i].cantInscriptos;j++){
                if(misAsistidos.misAsistencias[i].CursosInscriptos[j].idCurso==idClase){
                    return eResultados::ErrExiste;
                }
                misAsistidos.misAsistencias[i].cantInscriptos++;
                Inscripcion* aux=new Inscripcion[misAsistidos.misAsistencias[i].cantInscriptos];
                uint k;
                for (k=0; k<misAsistidos.misAsistencias[i].cantInscriptos-1;k++)
                    aux[k]=misAsistidos.misAsistencias[i].CursosInscriptos[k];
                aux[k].idCurso=idClase;
                aux[k].fechaInscripcion=time(0);
                delete[] misAsistidos.misAsistencias[i].CursosInscriptos;
                misAsistidos.misAsistencias[i].CursosInscriptos=aux;
                return eResultados::Exito;
            }

        }
    }
    return eResultados::ErrNoExiste;
}

eResultados EscribirAsistencias(sAsistencias misAsistencias){
    fstream archibinwr("asistencias_1697673600000.dat", ios::binary);
    archibinwr.seekg(ios::beg);
    if (archibinwr.is_open()) {
    for (uint i=0; i<misAsistencias.cantAsistencias; i++) {
        archibinwr.write((char*)&misAsistencias.misAsistencias[i].idCliente, sizeof(uint));
        archibinwr.write((char*)&misAsistencias.misAsistencias[i].cantInscriptos, sizeof(uint));
        for(uint j = 0; j < misAsistencias.misAsistencias[i].cantInscriptos; j++) {
            archibinwr.write((char*)&misAsistencias.misAsistencias[i].CursosInscriptos[j],sizeof(Inscripcion));
        }
    }
}
archibinwr.close();
return eResultados::Exito;
}

eResultados BuscarClase(sClase *misClases, str Nombre, double Hora, sClase &Clase, int CantClases){
for(int i=0;i<CantClases;i++){
    if(misClases[i].nombre==Nombre && misClases[i].horario==Hora){
        Clase=misClases[i];
        return eResultados::Exito;
    }
}
return eResultados::ErrNoExiste;
}

eResultados BuscarClase(sClase *misClases, uint idClase, sClase &Clase, int CantClases){
for(int i=0;i<CantClases;i++){
    if(misClases[i].idClase==idClase){
        Clase=misClases[i];
        return eResultados::Exito;
    }
}
return eResultados::ErrNoExiste;
}
