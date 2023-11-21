#ifndef SUMMARY_H
#define SUMMARY_H
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

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
        Asistencia misAsistencias;
        uint cantAsistencias;
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
        unsigned int idClase;
        str nombre;
        double hora;
        unsigned int CupoDisponible, CupoMax;
    }; typedef struct Clase sClase;


    //***ENUMS***
//ARCHIVOS
    enum eLeerArchivoClases {ErrLeerArchivoClases = -1, ExitoLeerArchivoClases = 1};
    enum eLeerArchivoClientes {ErrLeerArchivoClientes = -1, ExitoLeerArchivoClientes = 1};
    enum eLeerArchivoAsistencias {ErrLeerArchivoAsistencias = -1, ExitoLeerArchivoAsistencias = 1};

//ASISTENCIAS
    enum eAgrClientes  { ErrAgrExiste= -2, ErrAgrEspacio = -1,  ExitoAgregar = 1 };
    enum eUpdClientes  { ErrUpdClienteNoExiste= -2, ErrUpdCliente = -1,  ExitoUpdCliente = 1 };
    enum eRmClientes   { ErrRmClienteNoExiste = -2, ErrRmCliente = -1, ExitoRmCliente = 1 };
    enum eSrchClientes { ErrSrchNoExite = -2,ErrSrchCliente = -1, ExitoSrchCliente = 1 };
    typedef enum { ErrAnClase = -1, ExitoAnClase = 1} eAnClase;
    typedef enum { ErrCanClase = -1, ExitoCanClase = 1} eCanClase;
    enum eRmAsistencias { ErrRmAsistenciasNoExiste=-2, ErrRmAsistencias = -1, ExitoRmAsistencias = 1};
    enum eSrchClase { ErrSrchClase = -1, ExitoSrchClase = 1 };
    enum eCupos{ ErrCupos=-1, ExitoCupos=1};


    //***FUNCIONES***
// Agregar cliente
    eAgrClientes AgregarCliente(sClientes *Clientela, sCliente Cliente);
    void resizeClientes(sClientes* miLista, uint tam, uint nuevoTam);

//Modificar cliente
    eUpdClientes ActualizarCliente(sClientes *Clientela, sCliente ClienteActualizado, sCliente Cliente);

//Eliminar cliente
    eRmClientes RemoverCliente(sClientes *Clientela, sCliente Cliente, Asistencia *misInscriptos);

//Buscar cliente
    eSrchClientes BuscarCliente(sClientes *Clientela, str Nombre, str Apellido, sCliente& Cliente);
    eSrchClientes BuscarCliente(sClientes *Clientela, unsigned int idCliente, sCliente& Cliente);
    eSrchClientes BuscarCliente(sClientes *Clientela, str Email, sCliente& Cliente);

//Eliminar de Asistencia
    eRmAsistencias EliminarAsistencias(Asistencia *misAsistencias, sCliente Cliente);

//Anotarse a clase
    eAnClase AnotarseClase(sCliente Cliente, unsigned int idClase, Asistencia *misAsistencias, sClase *laClase);

//Cancelar clase
    eCanClase CancelarClase(sCliente Cliente, sClase _Clase, Asistencia *misInscriptos, sClase *misClases);

//Buscar clase
    sClase BuscarClase(sClase *misClases, str Nombre, double Hora);
    sClase BuscarClase(sClase *misClases, uint idClase);

    void inicializarCupos(sClase *misClases);

//Lectura de Archivos
    eLeerArchivoClases LeerArchivoClases (ifstream &miArchivo, sClase **misClases);
    eLeerArchivoClientes LeerArchivoClientes (ifstream &miArchivo, sClientes **misClientes);
    eLeerArchivoAsistencias LeerArchivoAsistencias(ifstream &miArchivo, Asistencia **misAsistencias);



#endif // SUMMARY_H
