#include "summary1.h"
/*
// CLASES.CSV
            eLeerArchivoClases LeerArchivoClases(ifstream &miArchivo, sClase **misClases){
                if(!miArchivo.is_open()){
                    return ErrLeerArchivoClases;
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

                while(getline(miArchivo, linea)){
                    stringstream ss (linea);
                    ss << linea;
                    getline(ss,auxidClase, ',');
                    aux[i].idClase=stoul(auxidClase);
                    getline(ss,auxnombre, ',');
                    aux[i].nombre=auxnombre;
                    getline(ss,auxhora, ',');
                    aux[i].idClase=stod(auxhora);
                    i++;
                }
                delete[] misClases;
                *misClases=aux;

                return ExitoLeerArchivoClases;
            }


//CLIENTES.CSV
            eLeerArchivoClientes LeerArchivoClientes(ifstream &miArchivo, sClientes **misClientes){
                if(!miArchivo.is_open()){
                    return ErrLeerArchivoClientes;
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

                sClientes* aux=new sClientes[longitud];

                while(getline(miArchivo, linea)){
                    stringstream ss(linea);
                    ss << linea;
                    getline(ss,auxidCliente, ',');
                    aux[i].misClientes->idCliente=stoul(auxidCliente);
                    getline(ss,auxnombre, ',');
                    aux[i].misClientes->nombre=auxnombre;
                    getline(ss,auxapellido, ',');
                    aux[i].misClientes->apellido=auxapellido;
                    getline(ss,auxemail, ',');
                    aux[i].misClientes->email=auxemail;
                    getline(ss,auxtelefono, ',');
                    aux[i].misClientes->telefono=auxtelefono;
                    getline(ss,auxfechaNac, ',');
                    aux[i].misClientes->fechaNac=auxfechaNac;
                    getline(ss,auxestado, ',');
                    aux[i].misClientes->estado=stoi(auxestado);
                    i++;
                }
                aux->CantClientes=longitud;
                aux->CantClientes=longitud;
                delete[] misClientes;
                *misClientes=aux;

                return ExitoLeerArchivoClientes;
            }


//ASISTENCIAS.DAT
            eLeerArchivoAsistencias LeerArchivoAsistencias(ifstream &miArchivo, Asistencia **misAsistencias){
                if (!miArchivo.is_open())
                    return eLeerArchivoAsistencias::ErrLeerArchivoAsistencias;

                str linea;
                unsigned int longitud=1;
                int i=0;

                Asistencia *aux =new  Asistencia [longitud];

                while (!miArchivo.eof()) {
                    miArchivo.read((char *)&aux->idCliente, sizeof(uint));
                    miArchivo.read((char *)&aux->cantInscriptos, sizeof(uint));

                    Inscripcion *auxInscriptos = new Inscripcion[aux->cantInscriptos];
                    for (uint i = 0; i < aux->cantInscriptos; i++) {
                        miArchivo.read((char *)auxInscriptos, sizeof(Inscripcion));
                    }
                    aux[i].CursosInscriptos = auxInscriptos;

                    i++;
                }
                delete[] misAsistencias;
                *misAsistencias=aux;
                return eLeerArchivoAsistencias::ExitoLeerArchivoAsistencias;
            }


*/
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
