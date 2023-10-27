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
enum eAgrClientes  { ErrAgrEspacio = -1,  ExitoAgregar = 1 };
enum eUpdClientes  { ErrUpdCliente = -1,  ExitoUpdCliente = 1 };
enum eRmClientes   { ErrRmCliente = -1, ExitoRmCliente = 1 };
enum eSrchClientes { ErrSrchCliente = -1, ExitoSrchCliente = 1 };
enum eAnClase {ErrAnClase = -1, ExitoAnClase = 1};
enum eCanClase {ErrCanClase = -1, ExitoCanClase = 1};


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
