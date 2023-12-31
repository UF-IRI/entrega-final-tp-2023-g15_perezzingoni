#include "summary1.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {

    //APERTURA DE ARCHIVOS
    //Apertura de Archivos para Lectura
    sClase *misClases= new sClase [1];
    ifstream miArchivo1;
    miArchivo1.open("iriClasesGYM.csv");
    if (!miArchivo1.is_open()){
        cout << "Error opening csv file" << endl;
        delete[] misClases;
        return 1;
    }
    eResultados lecturaClase;
    lecturaClase = LeerArchivoClases(miArchivo1, &misClases);
    if(lecturaClase==ErrEspacio)
        return -1;
    miArchivo1.close();
    inicializarCupos(misClases);
    cout<< misClases[1].CupoDisponible;

    sClientes Clientela;
    sCliente *misClientes=new sCliente[1];
    Clientela.misClientes=misClientes;
    ifstream miArchivo2;
    miArchivo2.open("iriClientesGYM.csv");
    if (!miArchivo2.is_open()){
        cout << "Error opening csv2 file" << endl;
        delete[] misClientes;
        return 1;
    }
    eResultados lecturaCliente;
    lecturaCliente = LeerArchivoClientes (miArchivo2, Clientela);
    if(lecturaCliente ==ErrEspacio)
        return -1;
    miArchivo2.close();

    sAsistencias Asistencias;
    Asistencia *misAsistencias=new Asistencia[1];
    Asistencias.misAsistencias=misAsistencias;
    ifstream infile("asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) {
        cout << "Error opening binary file" << endl;
        delete[] misAsistencias;
        return 1;
    }
    eResultados lecturaAsistencias;
    lecturaAsistencias= LeerArchivoAsistencias(infile, Asistencias);
    if(lecturaAsistencias==ErrEspacio)
        return -1;
    infile.close();
    cout<<Asistencias.cantAsistencias;
    inicializarCuposConAsist(misClases, Asistencias);

    //SIMULACIÓN <3
    int variable=0;
    while(variable!=5){
        cout<< endl<<"Ingrese (con un numero) lo que desea hacer"<< endl << "1. Agregar un Cliente"<< endl << "2. Modificar un Cliente"<< endl;
        cout<< "3. Reservar una Clase" << endl << "4. Desanotarse de una Clase" << endl << "5. Finlaizar" << endl;
        cin>>variable;
        if(variable==1){//Agregar nuevo Cliente
            sCliente nuevo;
            cout<<"Ingrese su nombre";
            cin>>nuevo.nombre;
            cout<<"Ingrese su apellido";
            cin>>nuevo.apellido;
            cout<<"Ingrese su email";
            cin>>nuevo.email;
            cout<<"Ingrese su telefono";
            cin>>nuevo.telefono;
            cout<<"Ingrese su fecha de nacimiento";
            cin>>nuevo.fechaNac;
            nuevo.idCliente=Clientela.CantClientes+1;
            nuevo.estado=0;
            eResultados verificar;
            verificar= AgregarCliente(Clientela, nuevo);
            if(verificar==Exito){
                cout<< "La operacion se realizó correctamente"<< endl;
            }else {
                if(verificar==ErrExiste){
                    cout<<"El cliente ya exite"<<endl;
                }else cout<< "Hubo un problema en el sistema. Disculpe las molestias. Intente nuevamente"<<endl;
            }
        }

        if(variable==2) {//Modificar un Cliente
            int IdCliente;
            sCliente Cliente;
            srand (time(NULL));
            IdCliente= rand() % Clientela.CantClientes + 1;
            BuscarCliente(Clientela, IdCliente, Cliente);
            sCliente modificado;
            cout<<"Ingrese los datos modificados para el cliente (El id se va a mantener igual)"<<endl;
            cout<<"Ingrese su nombre";
            cin>>modificado.nombre;
            cout<<"Ingrese su apellido";
            cin>>modificado.apellido;
            cout<<"Ingrese su email";
            cin>>modificado.email;
            cout<<"Ingrese su telefono";
            cin>>modificado.telefono;
            cout<<"Ingrese su fecha de nacimiento";
            cin>>modificado.fechaNac;
            cout<<"Ingrese su estado";
            cin>>modificado.estado;
            modificado.idCliente=Cliente.idCliente;
            eResultados verificar;
            verificar=ActualizarCliente(Clientela,modificado,Cliente);
            if(verificar==Exito)
                cout<<"Se realizó con exito la operacion"<<endl;
                    else
                    if(verificar==ErrNoExiste)
                    cout<<"El cliente que quiere actualizar no se encuentra en el sistema. Intentelo nuevamente o ingrese un nuevo cliente"<<endl;
            else
                cout<<"Hubo un problema en el sistema. Disculpe las molestias. Intente nuevamente"<<endl;
        }

        if(variable==3){//Reservar una Clase
            int IdCliente;
            sCliente Cliente;
            srand (time(NULL));
            IdCliente= rand() % Clientela.CantClientes + 1;
            BuscarCliente(Clientela, IdCliente, Cliente);
            int IdClase;
            cout<<Cliente.nombre<< "  ";
            cout<<Cliente.idCliente<<endl;
            IdClase= rand() % 60 + 1;
            eResultados verSiClase, verSiCupos;
            sClase Clase;
            verSiClase=BuscarClase(misClases,IdClase,Clase,60);
            cout<< Clase.idClase<<"-";
            cout<< Clase.CupoDisponible<<"-";
            cout<< Clase.nombre;
            if(verSiClase==ErrNoExiste)
                cout<<"No tenemos ese deporte en ese horario. Intente con otro"<<endl;
            else {
                verSiCupos=AnotarseClase(Cliente,Clase.idClase,Asistencias,misClases);
                if (verSiCupos==ErrorNoHayCupos)
                    cout<<"No hay cupos disponibles para esta clase. Intente en otro horario  ;)"<<endl;
                else{
                    if(verSiCupos==ErrExiste)
                        cout<<"Ya se encuentra anotado a esa Clase"<<endl;
                    else{
                        if(verSiCupos==Exito)
                            cout<<"Se realizo correctamente la operacion"<<endl;
                    }
                }
            }
        }

        if(variable==4){//Desaanotarse de Clase
            int IdCliente;
            sCliente Cliente;
            srand (time(NULL));
            IdCliente= rand() % Clientela.CantClientes + 1;
            BuscarCliente(Clientela, IdCliente, Cliente);
            int IdClase;
            IdClase= rand() % 60 + 1;
            eResultados verSiClase, verificar;
            sClase Clase;
            verSiClase=BuscarClase(misClases,IdClase,Clase,60);
            if(verSiClase==ErrNoExiste)
                cout<<"No tenemos ese deporte en ese horario. Intente nuevamente"<<endl;
            else {
                verificar=CancelarClase(Cliente,Clase,Asistencias,misClases);
                if(verificar==Exito)
                    cout<<"Se realizo la operacion"<<endl;
                else
                    cout<<"Hubo un problema. Puede que no estuviera anotado a esta clase o hubo otro error del sistema"<<endl;
            }
        }
    }


    ofstream archibinwr("asistencias_1697673600000.dat", ios::binary);
    if (archibinwr.is_open()) {
        for (uint i=0; i<Asistencias.cantAsistencias; i++) {
            archibinwr.write((char*)&Asistencias.misAsistencias[i].idCliente, sizeof(uint));
            archibinwr.write((char*)&Asistencias.misAsistencias[i].cantInscriptos, sizeof(uint));
            for(uint j = 0; j < Asistencias.misAsistencias[i].cantInscriptos; j++) {
                archibinwr.write((char*)&Asistencias.misAsistencias[i].CursosInscriptos[j],sizeof(Inscripcion));
            }
        }
    }
    archibinwr.close();
    return 0;
}

//Main para un cliente -sin rand- :)
/*
//GENERICO PARA CLIENTE ?
    int variable=0;

    while(variable!=5){
        cout<<endl<< "Ingrese (con un numero) lo que desea hacer"<< endl << "1. Agregar un Cliente"<< endl << "2. Modificar un Cliente"<< endl;
        cout<< "3. Reservar una Clase" << endl << "4. Desanotarse de una Clase" << endl << "5. Finlaizar" << endl;
        cin>>variable;
        if(variable==1){//Agregar nuevo Cliente
            sCliente nuevo;
            cout<<"Ingrese su nombre";
            cin>>nuevo.nombre;
            cout<<"Ingrese su apellido";
            cin>>nuevo.apellido;
            cout<<"Ingrese su email";
            cin>>nuevo.email;
            cout<<"Ingrese su telefono";
            cin>>nuevo.telefono;
            cout<<"Ingrese su fecha de nacimiento";
            cin>>nuevo.fechaNac;
            nuevo.idCliente=Clientela.CantClientes+1;
            nuevo.estado=0;
            eResultados verificar;
            verificar= AgregarCliente(Clientela, nuevo);
            if(verificar==Exito){
                cout<< "La operacion se realizó correctamente"<< endl;
            }else {
                if(verificar==ErrExiste){
                    cout<<"El cliente ya exite"<<endl;
                }else cout<< "Hubo un problema en el sistema. Disculpe las molestias. Intente nuevamente"<<endl;
            }
        }

        if(variable==2) {//Modificar un Cliente
            int queQuiere;
            sCliente Cliente;
            cout<< "¿Cómo quiere buscar al cliente para modificarlo? (Ingrese un numero)"<<endl;
                    cout<< "1. Nombre y Apellido" <<endl << "2.El Id del cliente"<<endl <<"3.Email"<<endl;
            cin>> queQuiere;
            if(queQuiere==1){
                cout<<"Ingrese el nombre"<<endl;
                cin>>Cliente.nombre;
                cout<<"Ingrese el apellido"<<endl;
                cin>>Cliente.apellido;
                BuscarCliente(Clientela,Cliente.nombre,Cliente.apellido,Cliente);
            }
            if(queQuiere==2){
                cout<<"Ingrese el id del cliente"<<endl;
                cin>>Cliente.idCliente;
                BuscarCliente(Clientela,Cliente.idCliente, Cliente);
            }
            if(queQuiere==3){
                cout<<"Ingrese el email"<<endl;
                cin>>Cliente.email;
                BuscarCliente(Clientela,Cliente.email, Cliente);
            }
            sCliente modificado;
            cout<<"Ingrese los datos modificados para el cliente (El id se va a mantener igual)"<<endl;
            cout<<"Ingrese su nombre";
            cin>>modificado.nombre;
            cout<<"Ingrese su apellido";
            cin>>modificado.apellido;
            cout<<"Ingrese su email";
            cin>>modificado.email;
            cout<<"Ingrese su telefono";
            cin>>modificado.telefono;
            cout<<"Ingrese su fecha de nacimiento";
            cin>>modificado.fechaNac;
            cout<<"Ingrese su estado";
            cin>>modificado.estado;
            modificado.idCliente=Cliente.idCliente;
            eResultados verificar;
            verificar=ActualizarCliente(Clientela,modificado,Cliente);
            if(verificar==Exito)
                cout<<"Se realizó con exito la operacion"<<endl;
                    else
                    if(verificar==ErrNoExiste)
                    cout<<"El cliente que quiere actualizar no se encuentra en el sistema. Intentelo nuevamente o ingrese un nuevo cliente"<<endl;
            else
                cout<<"Hubo un problema en el sistema. Disculpe las molestias. Intente nuevamente"<<endl;
        }

        if(variable==3){//Reservar una Clase
            int queQuiere;
            sCliente Cliente;
            cout<< "Como quiere buscar al cliente para modificarlo? (Ingrese un numero)"<<endl;
                    cout<< "1. Nombre y Apellido" <<endl << "2.El Id del cliente"<<endl <<"3.Email"<<endl;
            cin>> queQuiere;
            if(queQuiere==1){
                cout<<"Ingrese el nombre"<<endl;
                cin>>Cliente.nombre;
                cout<<"Ingrese el apellido"<<endl;
                cin>>Cliente.apellido;
                BuscarCliente(Clientela,Cliente.nombre,Cliente.apellido,Cliente);
            }
            if(queQuiere==2){
                cout<<"Ingrese el id del cliente"<<endl;
                cin>>Cliente.idCliente;
                BuscarCliente(Clientela,Cliente.idCliente, Cliente);
            }
            if(queQuiere==3){
                cout<<"Ingrese el email"<<endl;
                cin>>Cliente.email;
                BuscarCliente(Clientela,Cliente.email, Cliente);
            }
            cout<<"Cliente="<<Cliente.nombre<<Cliente.apellido<<Cliente.fechaNac<<endl;
            str deporte;
            double hora;
            cout<<"A que deporte quiere anotarse?. Ej: Spinning, Boxeo"<<endl;
                cin>>deporte;
            cout<<"A que hora es la clase?. Ej: 10; 14; 9,5"<<endl;
                        cin>>hora;
            eResultados verSiClase, verSiCupos;
            sClase Clase;
            verSiClase=BuscarClase(misClases,deporte,hora,Clase, 60);
            if(verSiClase==ErrNoExiste)
                cout<<"No tenemos ese deporte en ese horario. Intente con otro"<<endl;
            else {
                verSiCupos=AnotarseClase(Cliente,Clase.idClase,Asistencias,misClases);
                if (verSiCupos==ErrorNoHayCupos)
                    cout<<"No hay cupos disponibles para esta clase. Intente en otro horario  ;)"<<endl;
                else{
                    if(verSiCupos==ErrExiste)
                        cout<<"Ya se encuentra anotado a esa Clase"<<endl;
                    else{
                        if(verSiCupos==Exito)
                            cout<<"Se realizo correctamente la operacion"<<endl;
                    }
                }
            }
            for(int i=0;i<3;i++){
                if(Clase.idClase==misClases[i].idClase)
                    cout<<"Cupos disponibles= "<<misClases[i].CupoDisponible<<endl;
            }
            for(int i=0;i<3;i++)
                if(Asistencias.misAsistencias[i].idCliente==Cliente.idCliente)
                    cout<<Asistencias.misAsistencias[i].cantInscriptos;
        }

        if(variable==4){//Desaanotarse de Clase
            int queQuiere;
            sCliente Cliente;
            cout<< "Como quiere buscar al cliente para modificarlo? (Ingrese un numero)"<<endl;
                    cout<< "1. Nombre y Apellido" <<endl << "2.El Id del cliente"<<endl <<"3.Email"<<endl;
            cin>> queQuiere;
            if(queQuiere==1){
                cout<<"Ingrese el nombre"<<endl;
                cin>>Cliente.nombre;
                cout<<"Ingrese el apellido"<<endl;
                cin>>Cliente.apellido;
                BuscarCliente(Clientela,Cliente.nombre,Cliente.apellido,Cliente);
            }
            if(queQuiere==2){
                cout<<"Ingrese el id del cliente"<<endl;
                cin>>Cliente.idCliente;
                BuscarCliente(Clientela,Cliente.idCliente, Cliente);
            }
            if(queQuiere==3){
                cout<<"Ingrese el email"<<endl;
                cin>>Cliente.email;
                BuscarCliente(Clientela,Cliente.email, Cliente);
            }
            str deporte;
            double hora;
            cout<<"A que deporte quiere desnotarse?. Ej: Spinning, Boxeo"<<endl;
                cin>>deporte;
            cout<<"A que hora es la clase?. Ej: 10; 14; 9,5"<<endl;
                        cin>>hora;
            eResultados verSiClase, verificar;
            sClase Clase;
            verSiClase=BuscarClase(misClases,deporte,hora,Clase, 60);
            if(verSiClase==ErrNoExiste)
                cout<<"No tenemos ese deporte en ese horario. Intente nuevamente"<<endl;
            else {
                verificar=CancelarClase(Cliente,Clase,Asistencias,misClases);
                if(verificar)
                    cout<<"Se realizo la operacion"<<endl;
                else
                    cout<<"Hubo un problema. Puede que no estuviera anotado a esta clase o hubo otro error del sistema"<<endl;
            }
            for(int i=0;i<3;i++){
                if(Clase.idClase==misClases[i].idClase)
                    cout<<"Cupos disponibles= "<<misClases[i].CupoDisponible<<endl;
            }
            for(int i=0;i<3;i++)
                if(Asistencias.misAsistencias[i].idCliente==Cliente.idCliente)
                    cout<<Asistencias.misAsistencias[i].cantInscriptos;
        }
    }

//    EscribirAsistencias(Asistencias);

    delete[] Clientela.misClientes;
    delete[] misClases;
    delete[] Asistencias.misAsistencias[0].CursosInscriptos;
    delete[] Asistencias.misAsistencias[1].CursosInscriptos;
    delete[] Asistencias.misAsistencias[2].CursosInscriptos;
    delete[] misAsistencias;
*/

//Main para un cliente -con rad- :>
/*     while(variable!=5){
                cout<< "Ingrese (con un numero) lo que desea hacer"<< endl << "1. Agregar un Cliente"<< endl << "2. Modificar un Cliente"<< endl;
                cout<< "3. Reservar una Clase" << endl << "4. Desanotarse de una Clase" << endl << "5. Finlaizar" << endl;
                cin>>variable;
                if(variable==1){//Agregar nuevo Cliente
                sCliente nuevo;
                cout<<"Ingrese su nombre";
                cin>>nuevo.nombre;
                cout<<"Ingrese su apellido";
                cin>>nuevo.apellido;
                cout<<"Ingrese su email";
                cin>>nuevo.email;
                cout<<"Ingrese su telefono";
                cin>>nuevo.telefono;
                cout<<"Ingrese su fecha de nacimiento";
                cin>>nuevo.fechaNac;
                nuevo.idCliente=Clientela.CantClientes+1;
                nuevo.estado=0;
                eResultados verificar;
                verificar= AgregarCliente(Clientela, nuevo);
                if(verificar==Exito){
                cout<< "La operacion se realizó correctamente"<< endl;
                }else {
                if(verificar==ErrExiste){
                        cout<<"El cliente ya exite"<<endl;
                }else cout<< "Hubo un problema en el sistema. Disculpe las molestias. Intente nuevamente"<<endl;
                }
                }

                if(variable==2) {//Modificar un Cliente
                int IdCliente;
                sCliente Cliente;
                srand (time(NULL));
                IdCliente= rand() % Clientela.CantClientes + 1;
                BuscarCliente(Clientela, IdCliente, Cliente);
                sCliente modificado;
                cout<<"Ingrese los datos modificados para el cliente (El id se va a mantener igual)"<<endl;
                cout<<"Ingrese su nombre";
                cin>>modificado.nombre;
                cout<<"Ingrese su apellido";
                cin>>modificado.apellido;
                cout<<"Ingrese su email";
                cin>>modificado.email;
                cout<<"Ingrese su telefono";
                cin>>modificado.telefono;
                cout<<"Ingrese su fecha de nacimiento";
                cin>>modificado.fechaNac;
                cout<<"Ingrese su estado";
                cin>>modificado.estado;
                modificado.idCliente=Cliente.idCliente;
                eResultados verificar;
                verificar=ActualizarCliente(Clientela,modificado,Cliente);
                if(verificar==Exito)
                cout<<"Se realizó con exito la operacion"<<endl;
                    else
                    if(verificar==ErrNoExiste)
                    cout<<"El cliente que quiere actualizar no se encuentra en el sistema. Intentelo nuevamente o ingrese un nuevo cliente"<<endl;
                else
                cout<<"Hubo un problema en el sistema. Disculpe las molestias. Intente nuevamente"<<endl;
                }

                if(variable==3){//Reservar una Clase
                int IdCliente;
                sCliente Cliente;
                srand (time(NULL));
                IdCliente= rand() % Clientela.CantClientes + 1;
                BuscarCliente(Clientela, IdCliente, Cliente);
                int IdClase;
                IdClase= rand() % 60 + 1;
                eResultados verSiClase, verSiCupos;
                sClase Clase;
                verSiClase=BuscarClase(misClases,IdClase,Clase,60);
                if(verSiClase==ErrNoExiste)
                cout<<"No tenemos ese deporte en ese horario. Intente con otro"<<endl;
                else {
                verSiCupos=AnotarseClase(Cliente,Clase.idClase,Asistencias,misClases);
                if (verSiCupos==ErrorNoHayCupos)
                        cout<<"No hay cupos disponibles para esta clase. Intente en otro horario  ;)"<<endl;
                else{
                        if(verSiCupos==ErrExiste)
                            cout<<"Ya se encuentra anotado a esa Clase"<<endl;
                        else{
                            if(verSiCupos==Exito)
                                cout<<"Se realizo correctamente la operacion"<<endl;
                        }
                }
                }
                }

                if(variable==4){//Desaanotarse de Clase
                int IdCliente;
                sCliente Cliente;
                srand (time(NULL));
                IdCliente= rand() % Clientela.CantClientes + 1;
                BuscarCliente(Clientela, IdCliente, Cliente);
                int IdClase;
                IdClase= rand() % 60 + 1;
                eResultados verSiClase, verificar;
                sClase Clase;
                verSiClase=BuscarClase(misClases,IdClase,Clase,60);
                if(verSiClase==ErrNoExiste)
                cout<<"No tenemos ese deporte en ese horario. Intente nuevamente"<<endl;
                else {
                verificar=CancelarClase(Cliente,Clase,Asistencias,misClases);
                if(verificar==Exito)
                        cout<<"Se realizo la operacion"<<endl;
                else
                        cout<<"Hubo un problema. Puede que no estuviera anotado a esta clase o hubo otro error del sistema"<<endl;
                }
                }
    }
*/
