#include "summary1.h"
#include <iostream>

using namespace std;

int main() {
    /*
    //Apertura de Archivos para Lectura
    sClase *misClases;
    ifstream miArchivo1("iriClasesGYM.csv");
    miArchivo1.open("iriClasesGYM.csv");
    if (!miArchivo1.is_open()){
        cout << "Error opening csv file" << endl;
        return 1;
    }
    eResultados lecturaClase;
    lecturaClase = LeerArchivoClases(miArchivo1, &misClases);
    if(lecturaClase==ErrEspacio)
        return -1;
    miArchivo1.close();

    sClientes Clientela;
    ifstream miArchivo2;
    miArchivo2.open("iriClientesGYM.csv");
    if (!miArchivo2.is_open()){
        cout << "Error opening csv2 file" << endl;
        return 1;
    }
    eResultados lecturaCliente;
    lecturaCliente = LeerArchivoClientes (miArchivo2, Clientela);
    if(lecturaCliente ==ErrEspacio)
        return -1;
    miArchivo2.close();

    sAsistencias Asistencias;
    ifstream infile("asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) {
        cout << "Error opening binary file" << endl;
        return 1;
    }
    eResultados lecturaAsistencias;
    lecturaAsistencias= LeerArchivoAsistencias(infile, Asistencias);
    if(lecturaAsistencias==ErrEspacio)
        return -1;
    infile.close();
*/
    sClientes Clientela;
    sClase *misClases;
    sAsistencias Asistencias;

    int variable=0;
    while(variable!=5){
        cout<< "Ingrese (con un número) lo que desea hacer"<< endl << "1. Agregar un Cliente"<< endl << "2. Modificar un Cliente"<< endl;
        cout<< "3. Reservar una clase" << endl << "4. Desanotarde de una clase" << endl << "5. Finlaizar" << endl;
        cin>>variable;
        if(variable < 5){
            switch(variable){
            case 1:
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
                if(verificar==Exito)
                    cout<< "La operacion se realizó correctamente"<< endl;
                        else {
                            if(verificar==ErrExiste)
                            cout<<"El cliente ya exite"<<endl;
            case 2:
            case 3:
            case 4:
            }
        }
    }

//    EscribirAsistencias(Asistencias);

    return 0;
}
