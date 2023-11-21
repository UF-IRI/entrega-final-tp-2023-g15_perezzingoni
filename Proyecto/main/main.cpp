#include "summary1.h"
#include <iostream>

using namespace std;

int main() {

    //Apertura de Archivos para Lectura
    sClase *misClases;
    ifstream miArchivo1;
    miArchivo1.open("..\\..\\Proyecto\\Dataset TP\\iriClasesGYM.csv");
    if (!miArchivo1.is_open()){
        cout << "Error opening csv file" << endl;
        return 1;
    }
    eLeerArchivoClases lecturaClase;
    lecturaClase = LeerArchivoClases(miArchivo1, &misClases);
    if(lecturaClase==ErrLeerArchivoClases)
        return -1;
    miArchivo1.close();

    sClientes Clientela;
    ifstream miArchivo2;
    miArchivo2.open("..\\..\\Proyecto\\Dataset TP\\iriClientesGYM.csv");
    if (!miArchivo2.is_open()){
        cout << "Error opening csv file" << endl;
        return 1;
    }
    eLeerArchivoClientes lecturaCliente;
    lecturaCliente = LeerArchivoClientes (miArchivo2, Clientela);
    if(lecturaCliente ==ErrLeerArchivoClientes)
        return -1;
    miArchivo2.close();


    sAsistencias Asistencias;
    ifstream infile("..\\..\\Proyecto\\Dataset TP\\asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) {
        cout << "Error opening binary file" << endl;
        return 1;
    }
    eLeerArchivoAsistencias verificar;
    verificar= LeerArchivoAsistencias(infile, Asistencias);
    infile.close();

    //Apertura de Archivos para Escritura


    return 0;
}
