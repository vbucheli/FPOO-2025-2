#include "Prestamo.h"
#include <stdexcept>
#include <iostream>

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
Prestamo::Prestamo(int id, const std::string& u, const std::string& e)
    : idPrestamo(id), codigoUnivalluno(u), nombreElementoDeportivo(e), estado('E')  // Estado inicial: 'E' (En préstamo)
{
}
Prestamo::Prestamo(){
    estado='E';
}

// -------------------------------------------------------------------
// Métodos de acceso (getters)
// -------------------------------------------------------------------

int Prestamo::getIdPrestamo() const {
    return idPrestamo;
}

char Prestamo::getEstado() const {
    return estado;
}

std::string Prestamo::getCodigoUnivalluno() const{
    return codigoUnivalluno;
}

std::string Prestamo::getNombreElementoDeportivo() const{
    return nombreElementoDeportivo;
}
//Settes
void Prestamo::setEstado(char estadoAux){
    estado=estadoAux;
}