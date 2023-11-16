#include "clientes.h"
eAgrClientes AgregarCliente(sClientes**misClientes, sCliente Cliente, int cantClientes){
    //condiciones de error
    if(*misClientes==nullptr || cantClientes<0)
        return eAgrClientes::ErrAgrEspacio;

    //creo un array estatico para trabajar en y fuerzo que tenga sufcientes espacios de no tenerlos
    sClientes* aux = new sClientes[cantClientes];
    for(int i = 0; i < cantClientes; i++)
        aux[i] =*misClientes[i];
    if(aux==nullptr || aux->CantClientes!=cantClientes){
        delete[] aux;
        return eAgrClientes::ErrAgrEspacio;
    }
    if(aux->CantClientes==aux->CantMaxima){
        resizeContactos(&aux, aux->CantClientes, aux->CantClientes+5);
        aux->CantMaxima+=5;
    }

    //si el cliente ya existe no lo agrego
    eSrchClientes verificar;
    verificar= BuscarCliente(aux, Cliente.idCliente);
    if(verificar== ErrSrchNoExite){
        delete[] aux;
        return eAgrClientes::ErrAgrExiste;
    }

    //ahora sí agrego al cliente
    aux->misClientes[cantClientes]=Cliente;
    aux->CantClientes++;

    delete[] *misClientes;
    *misClientes = aux;
    return eAgrClientes::ExitoAgregar;
}

void resizeContactos(sClientes** misClientes, u_int tam, u_int nuevoTam) {
    if(*misClientes!=nullptr);
    sClientes* aux = new sClientes[nuevoTam];
    if(aux == nullptr)
        return;
    int longitud = (tam < nuevoTam) ? tam: nuevoTam;
    for(int i = 0; i < longitud; i++)
        aux[i] =*misClientes[i];
    delete[] *misClientes;
    *misClientes = aux;
}

eSrchClientes BuscarCliente(sClientes *misClientes, unsigned int idCliente){

}
