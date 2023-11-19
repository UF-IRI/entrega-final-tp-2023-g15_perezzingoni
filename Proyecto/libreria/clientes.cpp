#include "clientes.h"

eAgrClientes AgregarCliente(sClientes *Clientela, sCliente Cliente){
    //condiciones de error
    if(*misClientes==nullptr)
        return eAgrClientes::ErrAgrEspacio;


    //si el cliente ya existe no lo agrego
    eSrchClientes verificar;
    verificar= BuscarCliente(aux, Cliente.idCliente, Cliente);
    if(verificar== ErrSrchNoExite){
        delete[] aux;
        return eAgrClientes::ErrAgrExiste;
    }

    //ahora sí agrego al cliente
    if(Clientela->CantClientes==Clientela->CantMaxima)
        resizeClientes(Clientela,Clientela->CantClientes,Clientela->CantClientes+5);

    delete[] *Clientela->misClientes;
    *Clientela->misClientes = aux;
    return eAgrClientes::ExitoAgregar;
}

void resizeClientes(sClientes * Clientela, u_int tam, u_int nuevoTam) {
    if(*Clientela->misClientes!=nullptr){
    sClientes* aux = new sClientes[nuevoTam];
    if(aux == nullptr)
        return;
    int longitud = (tam < nuevoTam) ? tam: nuevoTam;
    for(int i = 0; i < longitud; i++)
        aux[i] =*Clientela->misClientes[i];
    delete[] *Clientela->misClientes;
    *Clientela->misClientes = aux;
    }
}

eUpdClientes ActualizarCliente(sClientes *Clientela, sCliente ClienteActualizado, sCliente Cliente){
    if(Clientela->misClientes==nullptr){
        return eUpdClientes::ErrUpdCliente;
    }

    for(int i=0;i<Clientela->CantClientes;i++){
        if(Clientela->misClientes[i].idCliente== Cliente.idCliente){
            Clientela->misClientes[i]=ClienteActualizado;
            return eUpdClientes::ExitoUpdCliente;
        }
    }
    return eUpdClientes::ErrUpdClienteNoExiste;
}

eSrchClientes BuscarCliente(sClientes *Clientela, str Nombre, str Apellido, sCliente& Cliente){
    if(Clientela->misClientes==nullptr)
        return eSrchClientes::ErrSrchCliente;
    for (int i=0;i<Clientela->CantClientes;i++){
        if(Clientela->misClientes[i].nombre==Nombre && misClientes->misClientes[i].apellido==Apellido){
            Cliente= misClientes->misClientes[i];
            return eSrchClientes::ExitoSrchCliente;
        }
    }
    return eSrchClientes::ErrSrchNoExite;
}

eSrchClientes BuscarCliente(sClientes *Clientela, unsigned int idCliente, sCliente& Cliente){
    if(Clientela->misClientes==nullptr)
        return eSrchClientes::ErrSrchCliente;
    for (int i=0;i<Clientela->CantClientes;i++){
        if(Clientela->misClientes[i].idCliente==idCliente){
            Cliente= Clientela->misClientes[i];
            return eSrchClientes::ExitoSrchCliente;
        }
    }
    return eSrchClientes::ErrSrchNoExite;
}

eSrchClientes BuscarCliente(sClientes *Clientela, str Email, sCliente& Cliente){
    if(Clientela->misClientes==nullptr)
        return eSrchClientes::ErrSrchCliente;
    for (int i=0;i<Clientela->CantClientes;i++){
        if(Clientela->misClientes[i].email==Email){
            Cliente= Clientela->misClientes[i];
            return eSrchClientes::ExitoSrchCliente;
        }
    }
    return eSrchClientes::ErrSrchNoExite;
}

eRmClientes RemoverCliente(sClientes *Clientela, sCliente Cliente, Asistencia *misAsistencias){
    eRmAsistencias sacarAsistencias;
    if(Clientela->misClientes==nullptr)
        return eRmClientes::ErrRmCliente;
    if(BuscarCliente(Clientela,Cliente.idCliente, Cliente)!=ExitoSrchClase)
        return eRmClientes::ErrRmClienteNoExiste;
    for(int i=0;i<Clientela->CantClientes;i++){
        if(Clientela->misClientes[i].idCliente==Cliente.idCliente){
            for(int j=i;j<Clientela->CantClientes;j++){
               Clientela->misClientes[j]=Clientela->misClientes[j+1];
            }
            Clientela->CantClientes--;
            sacarAsistencias = EliminarAsistencias(misAsistencias, Cliente);
            return eRmClientes::ExitoRmCliente;
        }
    }
    return eRmClientes::ErrRmClienteNoExiste;
}

eRmAsistencias EliminarAsistencias(Asistencia *misAsistencias, sCliente Cliente){
    if(misAsistencias==nullptr)
        return eRmAsistencias::ErrRmAsistencias;
    for(int i=0;i<misAsistencias->cantClientesInscriptos;i++){
        if(misAsistencias[i].idCliente==Cliente.idCliente){
            for (int j=0;j<misAsistencias->CursosInscriptos;j++)
               //Sumar cupos a las clases que iba a asistir
            for(int j=i;i<misAsistencias->cantClientesInscriptos;j++){
               misAsistencias[j]=misAsistencias[j+1];
            }
            misAsistencias->cantClientesInscriptos--;
            return eRmAsistencias::ExitoRmAsistencias;
        }
    }
    return eRmAsistencias::ErrRmAsistenciasNoExiste;
}
