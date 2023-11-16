#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
#include <sstream>
#include "clientes.h"
#include "clases.h"

typedef struct {
    uint idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    uint idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

//enums para errores
enum eLeerArchivoClases {ErrLeerArchivoClases = -1, ExitoLeerArchivoClases = 1};
enum eLeerArchivoClientes {ErrLeerArchivoClientes = -1, ExitoLeerArchivoClientes = 1};

//Funciones para leer archivos
//clases
//clientes
//asitencias

//leer archivo clases
eLeerArchivoClases LeerArchivoClases (ifstream miArchivo, sClase *&misClases);

//Funciones para escribir los archivos
//clases
//clientes
//asitencias

#endif // ARCHIVOS_H
