#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "libreria_global.h"

typedef struct {
    uint idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    uint idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

//Funciones para abrir los archivos



//Funciones para cerrar los archivos




#endif // ARCHIVOS_H
