#include "archivos.h"
#include <iostream>

using namespace std;

//convertir de time a estructura?
int main() {
    sClase *misClases;

    fstream miArchivo;
    miArchivo.open("..\\..\\Proyecto\\Dataset TP\\iriClasesGYM.csv");
    if (!miArhivo.is_open()){
        cout << "Error opening csv file" << endl;
        return 1;
    }

    eLeerArchivoClases LeerArchivoClases(std::fstream* miArchivo, sClase *&misClases);

    //string nombrearch="asistencia_"/*+string(time(NULL))*/+".dat";
    ifstream infile("..\\..\\Proyecto\\Dataset TP\\asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) {
        cout << "Error opening binary file" << endl;
        return 1;
    }
    infile.close();
    return 0;
}
