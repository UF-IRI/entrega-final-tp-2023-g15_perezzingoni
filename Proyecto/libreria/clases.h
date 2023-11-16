#ifndef CLASES_H
#define CLASES_H
#include "libreria.h"
// structuras>

struct Clase {
    unsigned int idClase;
    str nombre;
    double hora;
    unsigned int CupoDisponible, CupoMax;
}; typedef struct Clase sClase;

// enums para errores
enum eSrchClase { ErrSrchClase = -1, ExitoSrchClase = 1 };

//contadores

//Funciones

//Buscar clase
sClase BuscarClase(sClase *misClases, str Nombre, double Hora);
sClase BuscarClase(sClase *misClases, uint idClase);

// Para el gym (si tenemos tiempo)

#endif // CLASES_H
