#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>
#include <vector>
#include <stdexcept>

/*
===============================================================================
                                CRC - PRESTAMO
===============================================================================

Clase:
    Prestamo

Responsabilidades:
    - Registrar los prestamos de elementos deportivos a los usuario univallunos:
        * ID
        * CódigoUnivalluno
        * nombreElementoDeportivo
        * Tipo (E En prestamo o F Finalizado)
    - Garantizar unicidad de los prestamos dado que un univalluno no puede tener más de un elemento deportivo.
    - Proveer acceso a los datos básicos mediante métodos getters.

Colaboradores:
    - 

===============================================================================
*/

class Prestamo {
private:
    int idPrestamo;
    std::string codigoUnivalluno;
    std::string nombreElementoDeportivo;
    char estado; // E "En prestamo" o F "Finalizado"



public:
    // Constructor
    //id paso por valor
    //const std::string& codigoUnivalluno paso por referencia
    Prestamo(int id, const std::string& codigoUnivalluno,
                    const std::string& nombreElementoDeportivo);
    Prestamo();

   


    // Getters
    int getIdPrestamo() const;
    std::string getCodigoUnivalluno() const;
    std::string getNombreElementoDeportivo() const;
    char getEstado() const;
    //Settes
    void setEstado(char estado);
};

#endif // PRESTAMO_H
