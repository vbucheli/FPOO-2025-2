#include "ElementosDeportivos.h"

// Constructor
ElementosDeportivos::ElementosDeportivos(const std::string& nombre,
                                         const std::string& deporte,
                                         const std::string& descripcion,
                                         double valor)
    : nombre(nombre), deporte(deporte), descripcion(descripcion), valor(valor) {}
ElementosDeportivos::ElementosDeportivos(){
    
}

// Destructor
ElementosDeportivos::~ElementosDeportivos() {}

// Getters
std::string ElementosDeportivos::getNombre() const {
    return nombre;
}

std::string ElementosDeportivos::getDeporte() const {
    return deporte;
}

std::string ElementosDeportivos::getDescripcion() const {
    return descripcion;
}

double ElementosDeportivos::getValor() const {
    return valor;
}
