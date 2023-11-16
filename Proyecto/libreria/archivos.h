#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
#include <sstream>
#include "clientes.h"

struct Inscripcion{
    uint idCurso;
    time_t fechaInscripcion;
}; typedef struct Inscripcion Inscripcion;

struct Asistencia{
    uint idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
}; typedef struct Asistencia Asistencia;

//enums para errores
enum eLeerArchivoClases {ErrLeerArchivoClases = -1, ExitoLeerArchivoClases = 1};
enum eLeerArchivoClientes {ErrLeerArchivoClientes = -1, ExitoLeerArchivoClientes = 1};
enum eLeerArchivoAsistencias {ErrLeerArchivoAsistencias = -1, ExitoLeerArchivoAsistencias = 1};

//Lectura de Archivos
eLeerArchivoClases LeerArchivoClases (ifstream &miArchivo, sClase **misClases);
eLeerArchivoClientes LeerArchivoClientes (ifstream &miArchivo, sCliente **misClientes);
eLeerArchivoAsistencias LeerArchivoAsistencias(ifstream &miArchivo, Asistencia **misAsistencias);

    //Funciones para escribir los archivos
//clases
//clientes
//asitencias

#endif // ARCHIVOS_H
