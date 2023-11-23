#include <catch2/catch.hpp>
#include "summary1.h"

TEST_CASE("leer archivos")
{

    SECTION("Archivo Clientes") {

        u_int cantClientes;
        sCliente *Clientes, ClientePrueba;
        eResultados errArchivocliente;
        sClientes Clientela;
        Clientela.CantClientes=0;
        Clientela.CantMaxima=0;
        *Clientela.misClientes=*Clientes;

        ClientePrueba.idCliente = 206;
        ClientePrueba.apellido = "Torres";
        ClientePrueba.email = "MateoTorres@bolandia.iri";
        ClientePrueba.estado = 0;
        ClientePrueba.fechaNac= "08-01-1995";
        ClientePrueba.nombre = "Mateo";
        ClientePrueba.telefono = "844-131-1318";

        ifstream infileClientes("../iriClientesGYM.csv");

        errArchivocliente = LeerArchivoClientes(infileClientes,Clientela);

        REQUIRE(errArchivocliente == Exito);
        REQUIRE(cantClientes == 250);
        REQUIRE(Clientes[205].apellido == ClientePrueba.apellido);
        REQUIRE(Clientes[205].idCliente == ClientePrueba.idCliente);
        REQUIRE(Clientes[205].email == ClientePrueba.email);
        REQUIRE(Clientes[205].estado == ClientePrueba.estado);
        REQUIRE(Clientes[205].fechaNac == ClientePrueba.fechaNac);
        REQUIRE(Clientes[205].nombre == ClientePrueba.nombre);
        REQUIRE(Clientes[205].telefono == ClientePrueba.telefono);

        infileClientes.close();

        delete []Clientes;
    }

    SECTION("Archivo Clases") {

        u_int cantclases;
        sClase *Clases, ClasePrueba;
        eResultados errArchivoclase;

        ClasePrueba.idClase = 9;
        ClasePrueba.nombre = "Yoga";
        ClasePrueba.horario = 15;
        ClasePrueba.CupoMax = 25;

        ifstream infileClases("../iriClasesGYM.csv");

        errArchivoclase = LeerArchivoClases(infileClases, &Clases);

        REQUIRE(errArchivoclase == Exito);
        REQUIRE(cantclases == 60);
        REQUIRE(Clases[8].idClase == ClasePrueba.idClase);
        REQUIRE(Clases[8].nombre == ClasePrueba.nombre);
        REQUIRE(Clases[8].horario == ClasePrueba.horario);
        REQUIRE(Clases[8].CupoMax == ClasePrueba.CupoMax);

        infileClases.close();

        delete []Clases;
    }

    SECTION("Archivo Aistencia") {
        sAsistencias Asistencias;
        eResultados errBinario;

        ifstream archivobin("../asistencias_1697673600000.dat", ios::binary);

        errBinario = LeerArchivoAsistencias(archivobin, Asistencias);

        REQUIRE(errBinario == Exito);

        delete[] Asistencias.misAsistencias;

        archivobin.close();
    }

}

