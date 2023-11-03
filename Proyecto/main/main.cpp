#include <clientes.cpp>
#include <clases.cpp>
#include <libreria.cpp>
#include <archivos.cpp>
#include <iostream>

using namespace std;

//convertir de time a estructura?
int main() {
    //string nombrearch="asistencia_"/*+string(time(NULL))*/+".dat";
    ifstream infile("..\\..\\Proyecto\\Dataset TP\\asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) {
        cout << "Error opening binary file" << endl;
        return 1;
    }
    infile.close();
    return 0;
}
