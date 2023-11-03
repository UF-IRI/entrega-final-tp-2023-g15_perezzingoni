#ifndef CLASES_H
#define CLASES_H
#include <archivos.h>
#include <clientes.h>
#include <libreria.h>
// structuras>

struct sClase {
    unsigned int idClase;
    str nombre;
    double hora;
};typedef struct sClase sClase;//esto nos pasa el usuario

struct sClases {
    unsigned int idClase;
    str nombre;
    double hora;
    int Cupos;
};typedef struct sClases sClases;//con este manipulamos los datos para poder tener los cupos

// enums para errores
enum eSrchClase { ErrSrchClase = -1, ExitoSrchClase = 1 };

//contadores

//Funciones

//Buscar clase
sClases BuscarClase(sClases *misClases, str Nombre, double Hora);
sClases BuscarClase(sClases *misClases, uint idClase);

// Para el gym (si tenemos tiempo)

#endif // CLASES_H
