#include "summary1.h"
#include <iostream>

using namespace std;

int main() {

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
        cout << "Error opening csv file" << endl;
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
    eResultados verificar;
    verificar= LeerArchivoAsistencias(infile, Asistencias);
    if(verificar==ErrEspacio)
        return -1;
    infile.close();




    EscribirAsistencias(Asistencias);


    return 0;
}
