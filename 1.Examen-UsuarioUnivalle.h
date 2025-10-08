#ifndef USUARIOUNIVALLE_H
#define USUARIOUNIVALLE_H

#include <string>
#include <vector>
#include <stdexcept>

/*
===============================================================================
                                CRC - UsuarioUnivalle
===============================================================================

Clase:
    UsuarioUnivalle

Responsabilidades:
    - Registrar Univallunos con sus datos básicos:
        * Código
        * Nombres
        * Apellidos
        * Tipo (Estudiante o Funcionario)
    - Garantizar unicidad de los códigos (no se permiten duplicados).
    - Proveer acceso a los datos básicos mediante métodos getters.

Colaboradores:
    - 

===============================================================================
*/

class UsuarioUnivalle {
private:
    std::string codigo;
    std::string nombres;
    std::string apellidos;
    char tipo; // "E Estudiante" o "F Funcionario"



public:
    // Constructor
    UsuarioUnivalle(const std::string& codigo,
                    const std::string& nombres,
                    const std::string& apellidos,
                    char tipo);

    // Destructor
    ~UsuarioUnivalle();


    // Getters
    std::string getCodigo() const;
    std::string getNombres() const;
    std::string getApellidos() const;
    char getTipo() const;
};

#endif // USUARIOUNIVALLE_H
