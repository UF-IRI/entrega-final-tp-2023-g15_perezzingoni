/*#include <catch2/catch.hpp>
#include "summary1.h"

TEST_CASE( "Proyecto" ) {

    SECTION ("Agregar cliente"){
        sClientes Clientela;
        Clientela.CantClientes=1;
        Clientela.CantMaxima=2;
        sCliente *Cliente = new sCliente[1];
        Cliente[0].apellido="1";
        Cliente[0].email= ".";
        Cliente[0].estado=0;
        Cliente[0].fechaNac=";";
        Cliente[0].idCliente=2;
        Cliente[0].nombre=";";
        Cliente[0].telefono=";";
        Clientela.misClientes= Cliente;
     sCliente Cliente1 = {1,".", ".", ".",".",".", 0};
        eAgrClientes verificar;
     sClientes Clientela;

    Clientela.CantClientes = 1;
    Clientela.CantMaxima = 1;
    sCliente* misClientes = new sCliente[Clientela.CantClientes];
    Clientela.misClientes = misClientes;

    REQUIRE(Clientela.misClientes != nullptr);

    sCliente Cliente1={1,".", ".", ".",".",".", 0 };
    sCliente Cliente2={2,".", ".", ".",".",".", 0 };
    sCliente Cliente3={3,".", ".", ".",".",".", 0 };
    eAgrClientes verificar;gqq

    Clientela.misClientes[0]= Cliente1;

        sClientes Clientela;
        Clientela.CantClientes = 1;
        Clientela.CantMaxima = 1;
        sCliente* misClientes = new sCliente[Clientela.CantClientes];
        Clientela.misClientes = misClientes;

        REQUIRE(Clientela.misClientes != nullptr);

        sCliente Cliente1={1,".", ".", ".",".",".", 0 };
        sCliente Cliente2={2,".", ".", ".",".",".", 0 };
        sCliente Cliente3={3,".", ".", ".",".",".", 0 };
        eAgrClientes verificar;

        Clientela.misClientes[0]= Cliente1;
    //Agrego un cliente diferente que tendria que funcionar correctamente
        verificar= AgregarCliente(&Clientela, Cliente1);
    REQUIRE(verificar==ExitoAgregar);

    REQUIRE(Clientela.CantClientes == 2);
    REQUIRE(Clientela.CantMaxima == 5);

    //Casos que no tendrian que funcionar

    //cliente ya existente
    verificar= AgregarCliente(&Clientela, Cliente1);
    REQUIRE(verificar==ErrAgrExiste);
    //
    delete[] misClientes;
    }
*/
  /*  SECTION ("Modificar Cliente"){
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

    SECTION ("Buscar Cliente"){
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

    SECTION ("Echar Cliente"){
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
}*/



