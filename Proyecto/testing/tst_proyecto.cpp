#include <catch2/catch.hpp>

TEST_CASE( "Agregar Cliente" ) {
    sClientes* MisClientes = new sClientes;
    REQUIRE(MisClientes != nullptr);

    MisClientes->CantMaxima = 6;
    MisClientes->CantClientes = 0;
    MisClientes->misClientes = new sCliente[MisClientes->CantMaxima];

    REQUIRE(MisClientes->misClientes != nullptr);

    sCliente Cliente1={1,".", ".", ".",".",".", 0 };
    sCliente Cliente2={2,".", ".", ".",".",".", 0 };
    sCliente Cliente3={3,".", ".", ".",".",".", 0 };
    eAgrClientes verificar;

    //Agrego dos clientes diferentes que tendrian que funcionar correctamente
    verificar= AgregarCliente(&MisClientes, Cliente1, MisClientes->CantClientes);
    REQUIRE(verificar==ExitoAgregar);
    verificar= AgregarCliente(&MisClientes, Cliente2, MisClientes->CantClientes);
    REQUIRE(verificar==ExitoAgregar);

    REQUIRE(MisClientes->CantClientes == 2);
    REQUIRE(MisClientes->CantMaxima == 5);

    REQUIRE(MisClientes->misClientes[1]==Cliente1);
    REQUIRE(MisClientes->misClientes[2]==Cliente2);

    //Casos que no tendrian que funcionar
    verificar= AgregarCliente(&MisClientes, Cliente3, -1);
    REQUIRE(verificar==ErrAgrEspacio);

    delete[] MisClientes->misClientes;
    delete MisClientes;
}
