#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
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

//Funciones para leer archivos
//clases
//clientes
//asitencias


//Funciones para escribir los archivos
//clases
//clientes
//asitencias

#endif // ARCHIVOS_H
