#include "archivos.h"

eLeerArchivoClases LeerArchivoClases(std::fstream* miArchivo, sClase *&misClases){
    if(!miArchivo.is_open()){
        return ErrLeerArchivoClases;
    }
    stringstream ss;
    str auxidClase; //unsigned int
    str auxnombre;
    str auxhora; //double
    str auxcupoDisp; //unisgned int
    str auxcuposMax; //unsigned int
    char delimeter = ',';

    str primerLinea;
    getline(miArchivo, primerLinea);

    str linea;
    unsigned int longitud=0;
    int i=0;
    while(getline(miArchivo,linea))
        longitud++;

    miArchivo.seekg(ios::beg);

    sClase* misClases=new sClase[longitud];

    while(miArchivo.good){
        str linea;
        getline(miArchivo, linea);
        ss << linea;
        getline(ss,auxidClase, ',');
        misClases[i].idClase=stoul(auxidClase); //creo que ahi esta casteado
        getline(ss,auxnombre, ',');
        misClases[i].nombre=auxnombre;
        getline(ss,auxhora, ',');
        misClases[i].idClase=stod(auxhora); //creo que ahi esta casteado
        i++;
    }
    return ExitoLeerArchivoClases;
}
