#include <catch2/catch.hpp>
#include "archivos.h"
#include <iostream>

TEST_CASE( "Agregar Cliente" ) {
    sClientes* MisClientes = new sClientes[1];
    REQUIRE(MisClientes != nullptr);

    MisClientes->CantMaxima = 1;
    MisClientes->CantClientes = 0;
    MisClientes->misClientes = new sCliente[MisClientes->CantMaxima];

    REQUIRE(MisClientes->misClientes != nullptr);

    sCliente Cliente1={1,".", ".", ".",".",".", 0 };
    sCliente Cliente2={2,".", ".", ".",".",".", 0 };
    sCliente Cliente3={3,".", ".", ".",".",".", 0 };
    eAgrClientes verificar;

    //Agrego dos clientes diferentes que tendrian que funcionar correctamente
    verificar= AgregarCliente(MisClientes, Cliente1, MisClientes->CantClientes);
    REQUIRE(verificar==ExitoAgregar);
    verificar= AgregarCliente(MisClientes, Cliente2, MisClientes->CantClientes);
    REQUIRE(verificar==ExitoAgregar);

    REQUIRE(MisClientes->CantClientes == 2);
    REQUIRE(MisClientes->CantMaxima == 5);

    //Casos que no tendrian que funcionar
    //cant negativa
    verificar= AgregarCliente(MisClientes, Cliente3, -1);
    REQUIRE(verificar==ErrAgrEspacio);

    //cliente ya existente
    verificar= AgregarCliente(MisClientes, Cliente2, 2);
    REQUIRE(verificar==ErrAgrExiste);
    //
    delete[] MisClientes->misClientes;
    delete MisClientes;
}

TEST_CASE("Modificar Cliente"){
    sClientes* MisClientes = new sClientes[3];
    REQUIRE(MisClientes != nullptr);

    MisClientes->CantMaxima = 5;
    MisClientes->CantClientes = 2;
    MisClientes->misClientes = new sCliente[MisClientes->CantMaxima];

    REQUIRE(MisClientes->misClientes != nullptr);

    sCliente Cliente1={1,"Cami", "Perez", "gmail.com","333","124", 0 };
    sCliente Cliente2={1,"Tini", "Zingoni", "yahoo.com","123","456", 0 };
    sCliente Cliente3={3,"Tomy", "Rodriguez", "hotmail.com","000","777", 0 };
    sCliente Cliente4={4,"Nico", "Gonzales", "hotmail.com","000","777", 0 };

    MisClientes->misClientes[0]=Cliente1;
    MisClientes->misClientes[1]=Cliente3;

    //caso verdadero
    eUpdClientes verificar;
    verificar=ActualizarCliente(MisClientes, Cliente1, Cliente2);
    REQUIRE(verificar==ExitoUpdCliente);

    //no existe el cliente en la lista
    verificar=ActualizarCliente(MisClientes,Cliente3,Cliente4);
    REQUIRE(verificar==ErrUpdClienteNoExiste);
    delete[] MisClientes->misClientes;
    delete MisClientes;
}

TEST_CASE("Buscar Cliente"){
    sClientes* MisClientes = new sClientes[3];
    REQUIRE(MisClientes != nullptr);

    MisClientes->CantMaxima = 5;
    MisClientes->CantClientes = 3;
    MisClientes->misClientes = new sCliente[MisClientes->CantMaxima];

    REQUIRE(MisClientes->misClientes != nullptr);

    sCliente Cliente1={1,"Cami", "Perez", "gmail.com","333","124", 0 };
    sCliente Cliente2={2,"Tini", "Zongoni", "yahoo.com","123","456", 0 };
    sCliente Cliente3={3,"Tomy", "Rodriguez", "hotmail.com","000","777", 0 };
    sCliente Busqueda;

    MisClientes->misClientes[0]=Cliente1;
    MisClientes->misClientes[1]=Cliente2;
    MisClientes->misClientes[2]=Cliente3;

    eSrchClientes verificar;

    //Si paso el Nombre y Apellido
    verificar=BuscarCliente(MisClientes, "Cami", "Perez", Busqueda);
    REQUIRE(Busqueda.idCliente==Cliente1.idCliente);
    REQUIRE(verificar== ExitoSrchCliente);

    //Si paso el id
    verificar=BuscarCliente(MisClientes,2,Busqueda);
    REQUIRE(Busqueda.idCliente==Cliente2.idCliente);
    REQUIRE(verificar== ExitoSrchCliente);

    //Si paso el email
    verificar=BuscarCliente(MisClientes, "hotmail.com", Busqueda);
    REQUIRE(Busqueda.idCliente==Cliente3.idCliente);
    REQUIRE(verificar== ExitoSrchCliente);

    //Paso un cliente que no existe
    verificar=BuscarCliente(MisClientes, 4, Busqueda);
    REQUIRE (verificar == ErrSrchNoExite);

    delete[] MisClientes->misClientes;
    delete MisClientes;
}

TEST_CASE("Echar Cliente"){
    sClientes* MisClientes = new sClientes[3];
    REQUIRE(MisClientes != nullptr);

    MisClientes->CantMaxima = 5;
    MisClientes->CantClientes = 3;
    MisClientes->misClientes = new sCliente[MisClientes->CantMaxima];

    REQUIRE(MisClientes->misClientes != nullptr);

    sCliente Cliente1={1,"Cami", "Perez", "gmail.com","333","124", 0 };
    sCliente Cliente2={2,"Tini", "Zongoni", "yahoo.com","123","456", 0 };
    sCliente Cliente3={3,"Tomy", "Rodriguez", "hotmail.com","000","777", 0 };

    MisClientes->misClientes[0]=Cliente1;
    MisClientes->misClientes[1]=Cliente2;
    MisClientes->misClientes[2]=Cliente3;

    Asistencia* MisAsistencias=new Asistencia[1];
    MisAsistencias->cantClientesInscriptos=1;
    MisAsistencias->cantInscriptos=1;
    MisAsistencias->idCliente= 1;
    MisAsistencias->CursosInscriptos->fechaInscripcion=time(0);
    MisAsistencias->CursosInscriptos->idCurso=2;

    eRmClientes verificar;
    verificar = RemoverCliente(MisClientes,Cliente1,MisAsistencias);
    REQUIRE(verificar==ExitoRmCliente);
    REQUIRE(MisClientes->CantClientes==2);



    delete[] MisClientes->misClientes;
    delete MisClientes;
}
