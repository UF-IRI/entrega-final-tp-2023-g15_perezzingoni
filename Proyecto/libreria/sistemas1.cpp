#include "summary1.h"

eResultados AgregarCliente(sClientes &Clientela, sCliente Cliente){
    if(Clientela.misClientes==nullptr)
        return eResultados::ErrEspacio;

    eResultados verificar;
    verificar=BuscarCliente(Clientela,Cliente.idCliente,Cliente);
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
                        misInscriptos.misAsistencias[j].CursosInscriptos[a]=misInscriptos.misAsistencias[j].CursosInscriptos[a];
                    }
                    misInscriptos.misAsistencias[j].cantInscriptos--;
                }
            }
        }
    }
    return eResultados::Exito;
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
    unsigned int longitud=1;
    int i=0;

    Asistencia *aux =new  Asistencia [longitud];
    delete[] Asistencias.misAsistencias;
    Asistencias.misAsistencias=aux;

    while (!miArchivo.eof()) {
        miArchivo.read((char *)&aux->idCliente, sizeof(uint));
        miArchivo.read((char *)&aux->cantInscriptos, sizeof(uint));

        Inscripcion *auxInscriptos = new Inscripcion[aux->cantInscriptos];
        for (uint i = 0; i < aux->cantInscriptos; i++) {
            miArchivo.read((char *)auxInscriptos, sizeof(Inscripcion));
        }
        aux[i].CursosInscriptos = auxInscriptos;
        resizeAsistencias(Asistencias,longitud,longitud+1);
        longitud++;
        i++;


    }
    Asistencias.cantAsistencias=longitud;
    Asistencias.cantMax=longitud;
    filtrosBinario(Asistencias);

    return eResultados::Exito;
}

void resizeAsistencias(sAsistencias &misAsistencias, uint tam, uint nuevoTam){
    if(misAsistencias.misAsistencias==nullptr)
        return;

    Asistencia * aux=new Asistencia[nuevoTam];
    int longitud = (tam < nuevoTam) ? tam: nuevoTam;

    for(int i=0;i<longitud;i++)
        aux[i] =misAsistencias.misAsistencias[i];
    delete[] misAsistencias.misAsistencias;
    misAsistencias.misAsistencias = aux;
    misAsistencias.cantMax=nuevoTam;
    return;
}

void filtrosBinario(sAsistencias &Asistencias){
    for (uint i=0;i<Asistencias.cantAsistencias;i++){
        for(uint j=0; j<Asistencias.misAsistencias[i].cantInscriptos;j++){
            for(uint k=0;k<Asistencias.misAsistencias[i].cantInscriptos;k++){
                if(Asistencias.misAsistencias[j].CursosInscriptos->idCurso==Asistencias.misAsistencias[k].CursosInscriptos->idCurso){
                    Asistencias.misAsistencias[i].cantInscriptos--;
                    for(uint a=k;a<Asistencias.misAsistencias[i].cantInscriptos;k++)
                        Asistencias.misAsistencias->CursosInscriptos[a]=Asistencias.misAsistencias->CursosInscriptos[a+1];
                }
            }

        }
    }
}

/*void inicializarCupos(sClase *misClases){
    //inicializa todos los cupos de las distintas clases y musculacion
    if(misClases->nombre=='Spinning'){
        misClases->CupoDisponible=45;
        misClases->CupoMax=45;
    }
    if(misClases->nombre=='Yoga'){
        misClases->CupoDisponible=25;
        misClases->CupoMax=25;
    }
    if(misClases->nombre=='Pilates'){
        misClases->CupoDisponible=15;
        misClases->CupoMax=15;
    }
    if(misClases->nombre=='Stretching'){
        misClases->CupoDisponible=40;
        misClases->CupoMax=40;
    }
    if(misClases->nombre=='Zumba'){
        misClases->CupoDisponible=50;
        misClases->CupoMax=50;
    }
    if(misClases->nombre=='Boxeo'){
        misClases->CupoDisponible=30;
        misClases->CupoMax=30;
    }
    if(misClases->nombre=='Musculacion'){
        misClases->CupoDisponible=30;
        misClases->CupoMax=30;
    }
}
*/

