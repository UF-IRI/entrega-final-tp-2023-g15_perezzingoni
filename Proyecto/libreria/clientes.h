#ifndef CLIENTES_H
#define CLIENTES_H
#include "libreria_global.h"
#include "archivos.h"
#include "clases.h"
#include "libreria.h"
// strcturas
struct sClientes {
    unsigned int idCliente;
    str nombre;
    str apellido;
    str email;
    str telefono;
    str fechaNac;
    int estado;
};typedef struct sClientes sClientes;

// enums para errores


//Funciones

/* Agregar cliente
 * Eliminar cliente
 * Modificar cliente
 * Buscar cliente
 * Verificar estado
 * Anotarse a clase
 * Cancelar clase
*/

#endif // CLIENTES_H
