#ifndef CLIENTES_H
#define CLIENTES_H
#include "clases.h"
#include "libreria.h"

// strcturas
struct sCliente {
    unsigned int idCliente;
    str nombre;
    str apellido;
    str email;
    str telefono;
    str fechaNac;
    int estado;
};typedef struct sCliente sCliente;

struct sClientes{
    sCliente *misClientes;
    int CantClientes;
    int CantMaxima;
};typedef struct sClientes sClientes;

struct sInscripcion{
    uint idCurso;
    time_t fechaInscripcion;
}; typedef struct sInscripcion sInscripcion;

struct sAsistencia{
    uint idCliente, cantInscriptos;
    sInscripcion* CursosInscriptos;
};typedef struct sAsistencia sAsistencia;

struct sAsistencias{
    sAsistencia* Inscriptos;
    uint CantInscriptos;
    uint CantMaxInscriptos;
};typedef struct sAsistencias sAsistencias;

// enums para errores
enum eAgrClientes  { ErrAgrExiste= -2, ErrAgrEspacio = -1,  ExitoAgregar = 1 };
enum eUpdClientes  { ErrUpdCliente = -1,  ExitoUpdCliente = 1 };
enum eRmClientes   { ErrRmCliente = -1, ExitoRmCliente = 1 };
enum eSrchClientes { ErrSrchNoExite = -2,ErrSrchCliente = -1, ExitoSrchCliente = 1 };
typedef enum {ErrAnClase = -1, ExitoAnClase = 1} eAnClase;
typedef enum {ErrCanClase = -1, ExitoCanClase = 1} eCanClase;


//Funciones

// Agregar cliente
eAgrClientes AgregarCliente(sClientes *misClientes, sCliente Cliente, u_int cantClientes);
void resizeContactos(sClientes** miLista, u_int tam, u_int nuevoTam);

//Modificar cliente
eUpdClientes ActualizarCliente(sClientes *misClientes, sCliente Cliente);

//Eliminar cliente
eRmClientes RemoverCliente(sClientes *misClientes, sCliente Cliente, sAsistencias *misInscriptos);

//Buscar cliente
eSrchClientes BuscarCliente(sClientes *misClientes, str Nombre, str Apellido, sCliente& Cliente);
eSrchClientes BuscarCliente(sClientes *misClientes, unsigned int idCliente, sCliente& Cliente);
eSrchClientes BuscarCliente(sClientes *misClientes, str Email, sCliente& Cliente);

//Anotarse a clase
eAnClase AnotarseClase(sCliente Cliente, unsigned int idClase, sAsistencias *misInscriptos, sClase *laClase);

//Cancelar clase
//eCanClase CancelarClase(sCliente Cliente, sClases _Clase, sAsistencias *misInscriptos, sClases *misClases);

#endif // CLIENTES_H
