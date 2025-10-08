#include "UsuarioUnivalle.h"
#include <algorithm> // std::find



UsuarioUnivalle::UsuarioUnivalle(const std::string& codigo,
                                 const std::string& nombres,
                                 const std::string& apellidos,
                                 char tipo)
    : codigo(codigo), nombres(nombres), apellidos(apellidos) 
{
    if (tipo != 'E' && tipo != 'F') {
        throw std::invalid_argument("Tipo inválido: debe ser 'E' (Estudiante) o 'F' (Funcionario).");
    }
    this->tipo = tipo;
}

// Destructor
UsuarioUnivalle::~UsuarioUnivalle() {
    // Nada especial que liberar, strings se limpian solos
}

// Getters
std::string UsuarioUnivalle::getCodigo() const { return codigo; }
std::string UsuarioUnivalle::getNombres() const { return nombres; }
std::string UsuarioUnivalle::getApellidos() const { return apellidos; }
char UsuarioUnivalle::getTipo() const {return tipo;}
