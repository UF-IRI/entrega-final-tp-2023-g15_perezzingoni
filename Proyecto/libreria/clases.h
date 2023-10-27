#ifndef CLASES_H
#define CLASES_H
#include <archivos.h>
#include <clientes.h>
#include <libreria.h>
// structuras>

struct sClases {
    unsigned int idClases;
    str nombre;
    double hora;
};typedef struct sClases sClases;

// enums para errores
enum eSrchClase { ErrSrchClase = -1, ExitoSrchClase = 1 };

//contadores

//Funciones
bool VerificarCupos(sClases Clase);

#endif // CLASES_H
