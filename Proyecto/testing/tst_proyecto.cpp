#include <catch2/catch.hpp>
#include "summary1.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

TEST_CASE("Leer archivos")
{

    SECTION("Archivo Clientes") {

        sCliente ClientePrueba;

        ClientePrueba.idCliente = 206;
        ClientePrueba.apellido = "Torres";
        ClientePrueba.email = "MateoTorres@bolandia.iri";
        ClientePrueba.estado = 0;
        ClientePrueba.fechaNac= "08-01-1995";
        ClientePrueba.nombre = "Mateo";
        ClientePrueba.telefono = "844-131-1318";

        sClientes Clientela;
        sCliente *misClientes=new sCliente[1];
        Clientela.misClientes=misClientes;
        ifstream miArchivo2;
        miArchivo2.open("iriClientesGYM.csv");

        eResultados lecturaCliente;
        lecturaCliente = LeerArchivoClientes (miArchivo2, Clientela);

        miArchivo2.close();

        REQUIRE(lecturaCliente == Exito);
        REQUIRE(Clientela.CantClientes == 250);
        REQUIRE(Clientela.misClientes[205].apellido == ClientePrueba.apellido);
        REQUIRE(Clientela.misClientes[205].idCliente == ClientePrueba.idCliente);
        REQUIRE(Clientela.misClientes[205].email == ClientePrueba.email);
        REQUIRE(Clientela.misClientes[205].estado == ClientePrueba.estado);
        REQUIRE(Clientela.misClientes[205].fechaNac == ClientePrueba.fechaNac);
        REQUIRE(Clientela.misClientes[205].nombre == ClientePrueba.nombre);
        REQUIRE(Clientela.misClientes[205].telefono == ClientePrueba.telefono);

        delete []misClientes;
    }

    SECTION("Archivo Clases") {

        sClase ClasePrueba;

        ClasePrueba.idClase = 9;
        ClasePrueba.nombre = "Yoga";
        ClasePrueba.horario = 15;
        ClasePrueba.CupoMax = 25;

        sClase *misClases= new sClase [1];
        ifstream miArchivo1;
        miArchivo1.open("iriClasesGYM.csv");

        eResultados lecturaClase;

        lecturaClase = LeerArchivoClases(miArchivo1, &misClases);
        miArchivo1.close();

        REQUIRE(lecturaClase == Exito);
        REQUIRE(misClases[8].idClase == ClasePrueba.idClase);
        REQUIRE(misClases[8].nombre == ClasePrueba.nombre);
        REQUIRE(misClases[8].horario == ClasePrueba.horario);
        REQUIRE(misClases[8].CupoMax == ClasePrueba.CupoMax);

        delete []misClases;
    }

    SECTION("Archivo Aistencia") {
        sAsistencias Asistencias;
        Asistencia *misAsistencias=new Asistencia[1];
        Asistencias.misAsistencias=misAsistencias;
        ifstream infile("asistencias_1697673600000.dat", ios::binary);
        eResultados lecturaAsistencias;
        lecturaAsistencias= LeerArchivoAsistencias(infile, Asistencias);
        infile.close();

        REQUIRE(lecturaAsistencias== Exito);

        delete[] Asistencias.misAsistencias;

    }

}

TEST_CASE("Funciones Importantes"){

    SECTION ("Buscar Cliente"){
        sCliente *Cliente= new sCliente[4];

        Cliente[0].idCliente= 1;
        Cliente[0].nombre= "Agustín";
        Cliente[0].apellido= "Guerra";
        Cliente[0].email="AgustínGuerra@bolandia.iri";
        Cliente[0].telefono= "462-285-2783";
        Cliente[0].fechaNac= "10-12-1966";
        Cliente[0].estado= 0;

        Cliente[1].idCliente= 2;
        Cliente[1].nombre= "Emilio";
        Cliente[1].apellido= "Romero";
        Cliente[1].email="EmilioRomer@bolandia.iri";
        Cliente[1].telefono= "317-427-6829";
        Cliente[1].fechaNac= "14-08-1998";
        Cliente[1].estado= -3241;

        Cliente[2].idCliente= 3;
        Cliente[2].nombre= "Tomás";
        Cliente[2].apellido= "Lanaro";
        Cliente[2].email="TomásLanaro@bolandia.iri";
        Cliente[2].telefono= "426-646-4494";
        Cliente[2].fechaNac= "19-02-1996";
        Cliente[2].estado= 8313;

        Cliente[3].idCliente= 4;
        Cliente[3].nombre= "Gabriel";
        Cliente[3].apellido= "Hernández";
        Cliente[3].email="GabrielHernández@bolandia.iri";
        Cliente[3].telefono= "527-298-4006";
        Cliente[3].fechaNac= "02-05-1990";
        Cliente[3].estado= 0;

        sClientes Clientela;
        Clientela.CantClientes=4;
        Clientela.CantMaxima=4;
        Clientela.misClientes=Cliente;

        eResultados verificar;
        sCliente Buscar;

        //BUSCAR CLIENTE EXISTENTE
        verificar=BuscarCliente(Clientela,1,Buscar);
        REQUIRE(verificar==Exito);
        CHECK(Buscar.idCliente==Cliente[0].idCliente);
        CHECK(Buscar.apellido==Cliente[0].apellido);
        CHECK(Buscar.nombre==Cliente[0].nombre);

        //BUSCAR CLIENTE NO EXISTENTE
        verificar=BuscarCliente(Clientela,5,Buscar);
        REQUIRE(verificar==ErrNoExiste);

        delete[] Cliente;
    }

    SECTION ("Buscar Clase"){
        sClase *misClases=new sClase[3];

        misClases[0].CupoDisponible=45;
        misClases[0].CupoMax=45;
        misClases[0].idClase=1;
        misClases[0].nombre= "Spinning";
        misClases[0].horario= 8;

        misClases[1].CupoDisponible=25;
        misClases[1].CupoMax=25;
        misClases[1].idClase=6;
        misClases[1].nombre="Yoga";
        misClases[1].horario=9;

        misClases[2].CupoDisponible=15;
        misClases[2].CupoMax=15;
        misClases[2].idClase=12;
        misClases[2].nombre= "Pilates";
        misClases[2].horario= 8;

        sClase Clase;
        eResultados verificar;

        //BUSCAR CLASE EXISTENTE
        verificar=BuscarClase(misClases,"Yoga",9,Clase, 3);
        REQUIRE(verificar==Exito);
        CHECK(Clase.idClase==misClases[1].idClase);
        CHECK(Clase.horario==misClases[1].horario);
        CHECK(Clase.nombre==misClases[1].nombre);
        CHECK(Clase.CupoDisponible==misClases[1].CupoDisponible);
        CHECK(Clase.CupoMax==misClases[1].CupoMax);

        //BUSCAR CLASE NO EXISTENTE
        verificar=BuscarClase(misClases,0,Clase, 3);
        REQUIRE(verificar==ErrNoExiste);
        delete[] misClases;

    }

}

