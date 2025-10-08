#ifndef ELEMENTOSDEPORTIVOS_H
#define ELEMENTOSDEPORTIVOS_H

#include <string>

/*
===============================================================================
                                CRC - ElementosDeportivos
===============================================================================

Clase:
    ElementosDeportivos

Responsabilidades:
    - Representar los elementos deportivos registrados en el sistema.
    - Almacenar información básica:
        * Nombre
        * Deporte al que pertenece
        * Descripción (campo de texto largo)
        * Valor en pesos colombianos (o la moneda definida).
    - Proveer métodos de acceso a estos datos (getters).
    - Permitir su uso futuro en el registro de préstamos.

Colaboradores:
    - Clases futuras (ej. GestorElementos, PrestamoDeportivo):
        Podrán utilizar ElementosDeportivos para gestionar inventarios
        y asociar préstamos de cada elemento deportivo.

===============================================================================
*/

class ElementosDeportivos {
private:
    std::string nombre;
    std::string deporte;
    std::string descripcion;
    double valor;  // Valor en pesos (puede ampliarse con clases de dinero/moneda)

public:
    // Constructor
    ElementosDeportivos(const std::string& nombre,
                        const std::string& deporte,
                        const std::string& descripcion,
                        double valor);
    ElementosDeportivos();

    // Destructor
    ~ElementosDeportivos();

    // Getters
    std::string getNombre() const;
    std::string getDeporte() const;
    std::string getDescripcion() const;
    double getValor() const;

};

#endif // ELEMENTOSDEPORTIVOS_H
