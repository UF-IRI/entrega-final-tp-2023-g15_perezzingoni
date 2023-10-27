#include "libreria_global.h"
#include "clientes.h"
#include "clases.h"
#include "libreria.h"
#include "archivos.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile("asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) {
        cout << "Error opening binary file" << endl;
        return 1;
    }
    infile.close();
    return 0;
}
