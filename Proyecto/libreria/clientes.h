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

struct Inscripcion{
    uint idCurso;
    time_t fechaInscripcion;
}; typedef struct Inscripcion Inscripcion;

struct Asistencia{
    uint idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
    uint cantClientesInscriptos;
}; typedef struct Asistencia Asistencia;


// enums para errores
enum eAgrClientes  { ErrAgrExiste= -2, ErrAgrEspacio = -1,  ExitoAgregar = 1 };
enum eUpdClientes  { ErrUpdClienteNoExiste= -2, ErrUpdCliente = -1,  ExitoUpdCliente = 1 };
enum eRmClientes   { ErrRmClienteNoExiste = -2, ErrRmCliente = -1, ExitoRmCliente = 1 };
enum eSrchClientes { ErrSrchNoExite = -2,ErrSrchCliente = -1, ExitoSrchCliente = 1 };
typedef enum {ErrAnClase = -1, ExitoAnClase = 1} eAnClase;
typedef enum {ErrCanClase = -1, ExitoCanClase = 1} eCanClase;
enum eRmAsistencias {ErrRmAsistenciasNoExiste=-2, ErrRmAsistencias = -1, ExitoRmAsistencias = 1};



//Funciones

// Agregar cliente
eAgrClientes AgregarCliente(sClientes *misClientes, sCliente Cliente, u_int cantClientes);
void resizeContactos(sClientes** miLista, u_int tam, u_int nuevoTam);

//Modificar cliente
eUpdClientes ActualizarCliente(sClientes *MisClientes, sCliente ClienteActualizado, sCliente Cliente);

//Eliminar cliente
eRmClientes RemoverCliente(sClientes *MisClientes, sCliente Cliente, Asistencia *misInscriptos);

//Buscar cliente
eSrchClientes BuscarCliente(sClientes *misClientes, str Nombre, str Apellido, sCliente& Cliente);
eSrchClientes BuscarCliente(sClientes *misClientes, unsigned int idCliente, sCliente& Cliente);
eSrchClientes BuscarCliente(sClientes *misClientes, str Email, sCliente& Cliente);

//Eliminar de Asistencia
eRmAsistencias EliminarAsistencias(Asistencia *misAsistencias, sCliente Cliente);

//Anotarse a clase
eAnClase AnotarseClase(sCliente Cliente, unsigned int idClase, Asistencia *misAsistencias, sClase *laClase);

//Cancelar clase
//eCanClase CancelarClase(sCliente Cliente, sClase _Clase, sAsistencias *misInscriptos, sClase *misClases);

#endif // CLIENTES_H
