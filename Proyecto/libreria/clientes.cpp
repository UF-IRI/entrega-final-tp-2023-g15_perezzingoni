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
    verificar= BuscarCliente(aux, Cliente.idCliente, Cliente);
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

eUpdClientes ActualizarCliente(sClientes *MisClientes, sCliente ClienteActualizado, sCliente Cliente){
    if(MisClientes==nullptr){
        return eUpdClientes::ErrUpdCliente;
    }

    for(int i=0;i<MisClientes->CantClientes;i++){
        if(MisClientes->misClientes[i].idCliente== Cliente.idCliente){
            MisClientes->misClientes[i]=ClienteActualizado;
            return eUpdClientes::ExitoUpdCliente;
        }
    }
    return eUpdClientes::ErrUpdClienteNoExiste;
}

eSrchClientes BuscarCliente(sClientes *misClientes, str Nombre, str Apellido, sCliente& Cliente){
    if(misClientes==nullptr)
        return eSrchClientes::ErrSrchCliente;
    for (int i=0;i<misClientes->CantClientes;i++){
        if(misClientes->misClientes[i].nombre==Nombre && misClientes->misClientes[i].apellido==Apellido){
            Cliente= misClientes->misClientes[i];
            return eSrchClientes::ExitoSrchCliente;
        }
    }
    return eSrchClientes::ErrSrchNoExite;
}

eSrchClientes BuscarCliente(sClientes *misClientes, unsigned int idCliente, sCliente& Cliente){
    if(misClientes==nullptr)
        return eSrchClientes::ErrSrchCliente;
    for (int i=0;i<misClientes->CantClientes;i++){
        if(misClientes->misClientes[i].idCliente==idCliente){
            Cliente= misClientes->misClientes[i];
            return eSrchClientes::ExitoSrchCliente;
        }
    }
    return eSrchClientes::ErrSrchNoExite;
}

eSrchClientes BuscarCliente(sClientes *misClientes, str Email, sCliente& Cliente){
    if(misClientes==nullptr)
        return eSrchClientes::ErrSrchCliente;
    for (int i=0;i<misClientes->CantClientes;i++){
        if(misClientes->misClientes[i].email==Email){
            Cliente= misClientes->misClientes[i];
            return eSrchClientes::ExitoSrchCliente;
        }
    }
    return eSrchClientes::ErrSrchNoExite;
}

eRmClientes RemoverCliente(sClientes *MisClientes, sCliente Cliente, Asistencia *misAsistencias){
    eRmAsistencias sacarAsistencias;
    if(MisClientes==nullptr)
        return eRmClientes::ErrRmCliente;
    if(BuscarCliente(MisClientes,Cliente.idCliente, Cliente)!=ExitoSrchClase)
        return eRmClientes::ErrRmClienteNoExiste;
    for(int i=0;i<MisClientes->CantClientes;i++){
        if(MisClientes->misClientes[i].idCliente==Cliente.idCliente){
            for(int j=i;j<MisClientes->CantClientes;j++){
               MisClientes->misClientes[j]=MisClientes->misClientes[j+1];
            }
            MisClientes->CantClientes--;
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
