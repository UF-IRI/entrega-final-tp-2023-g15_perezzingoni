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
        if(variable==1){//Agregar nuevo cliente
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
                    }else cout<< "Hubo un problema en el sistema. Disculpe las molestias. intente nuevamente"<<endl;
                    }
        }

        if(variable==2) {//Modificar un cliente
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

        }
    }

//    EscribirAsistencias(Asistencias);

    return 0;
}
