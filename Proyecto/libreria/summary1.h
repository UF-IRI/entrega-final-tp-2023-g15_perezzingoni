#ifndef ENCABEZADOS_H
#define ENCABEZADOS_H

#include <string>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

typedef std::string str;
typedef unsigned int u_int;

typedef std::string str;
using namespace std;
typedef unsigned int uint;


//***ESTRUCTURAS***

//ASISTENCIAS
struct Inscripcion{
    uint idCurso;
    time_t fechaInscripcion;
}; typedef struct Inscripcion Inscripcion;

struct Asistencia{
    uint idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
}; typedef struct Asistencia Asistencia;

struct sAsistencias{
    Asistencia *misAsistencias;
    uint cantAsistencias;
    uint cantMax;
}; typedef struct sAsistencias sAsistencias;


//CLIENTES
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


//CLASES
struct Clase {
    uint idClase;
    str nombre;
    float horario;
    uint CupoDisponible;
    uint CupoMax;
}; typedef struct Clase sClase;


//***ENUMS***

enum eResultados {Error=-4 ,ErrNoExiste=-3, ErrExiste=-2, ErrEspacio=-1, Exito=1};


//***FUNCIONES***
// Agregar cliente
eResultados AgregarCliente(sClientes& Clientela, sCliente Cliente);
eResultados resizeClientes(sClientes& Clientela, uint tam, uint nuevoTam);

//Buscar cliente
eResultados BuscarCliente(sClientes &Clientela, str Nombre, str Apellido, sCliente& Cliente);
eResultados BuscarCliente(sClientes &Clientela, uint idCliente, sCliente& Cliente);
eResultados BuscarCliente(sClientes &Clientela, str Email, sCliente& Cliente);

//Modificar cliente
eResultados ActualizarCliente(sClientes &Clientela, sCliente ClienteActualizado, sCliente Cliente);

//Eliminar cliente
eResultados RemoverCliente(sClientes &Clientela, sCliente Cliente, sAsistencias *misInscriptos);

//Eliminar de Asistencia
eResultados EliminarAsistencias(Asistencia *misAsistencias, sCliente Cliente);

//Anotarse a clase
eResultados AnotarseClase(sCliente Cliente, unsigned int idClase, Asistencia *misAsistencias, sClase *laClase);

//Cancelar clase
eResultados CancelarClase(sCliente Cliente, sClase _Clase, Asistencia &misInscriptos, sClase *misClases);

//Modificar cupos (sumar o restar)
eResultados ModificarCupos(sClase *misClases, int cambio, uint idClase);

//Buscar clase
sClase BuscarClase(sClase *misClases, str Nombre, double Hora);
sClase BuscarClase(sClase *misClases, uint idClase);

//Lectura de Archivos
eResultados LeerArchivoClases (ifstream &miArchivo, sClase **misClases);
eResultados LeerArchivoClientes (ifstream &miArchivo, sClientes &Clientela);
eResultados LeerArchivoAsistencias(ifstream &miArchivo, sAsistencias &Asistencias);
void resizeAsistencias(sAsistencias &misAsistencias, uint tam, uint nuevoTam);
void filtrosBinario(sAsistencias &Asistencias);

//Cupos


//Filtros del binario



//Escritura de Archivos




#endif // ENCABEZADOS_H
