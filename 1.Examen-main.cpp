#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "UsuarioUnivalle.h"
#include "ElementosDeportivos.h"
#include "Prestamo.h"

int main() {
    std::vector<UsuarioUnivalle> usuarios;          // Lista de usuarios registrados esto puede ser una clase con el método validar código
    std::vector<std::string> codigos;               // Códigos para validar unicidad
    std::vector<ElementosDeportivos> inventario;    // Lista de elementos deportivos
    std::vector<Prestamo> prestamos;    // Lista de elementos deportivos

    int idAutonum=0;

    int opcion = 0;

    do {
        std::cout << "\n===== Sistema Univalle =====\n";
        std::cout << "1. Registrar Usuario\n";
        std::cout << "2. Registrar Elemento Deportivo\n";
        std::cout << "3. Mostrar Todos los Usuarios\n";
        std::cout << "4. Mostrar Inventario Deportivo\n";
        std::cout << "5. Registrar Prestamo\n";
        std::cout << "6. Modificar Estado del Prestamo a Finalizado\n";
        std::cout << "7. Reportes\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string codigo, nombres, apellidos;
            char tipo;
            // Pedir datos por teclado
            std::cout << "Ingrese el código: ";
            std::cin >> codigo;

            std::cout << "Ingrese los nombres: ";
            std::cin.ignore(); // limpiar el buffer
            std::getline(std::cin, nombres);

            std::cout << "Ingrese los apellidos: ";
            std::getline(std::cin, apellidos);

            std::cout << "Ingrese el tipo (E = Estudiante, F = Funcionario): ";
            std::cin >> tipo;

            if(codigos.size()==0){
                codigos.push_back(codigo);
                UsuarioUnivalle u1(codigo,nombres,apellidos,tipo);
                usuarios.push_back(u1);
            }
            else{
                 // Usamos std::find para verificar si está en el vector
                auto it = std::find(codigos.begin(), codigos.end(), codigo);
                if (it != codigos.end()) {
                    std::cout << "El código " << codigo << " ya existe en la lista.\n";
                } else {
                    codigos.push_back(codigo);
                    UsuarioUnivalle u2(codigo,nombres,apellidos,tipo);
                    usuarios.push_back(u2);
                }
            }
        }
        else if (opcion == 2) {
            std::string nombre, deporte, descripcion;
            double valor;

            std::cin.ignore(); // limpiar buffer
            std::cout << "Ingrese el nombre del elemento: ";
            std::getline(std::cin, nombre);

            std::cout << "Ingrese el deporte: ";
            std::getline(std::cin, deporte);

            std::cout << "Ingrese la descripción: ";
            std::getline(std::cin, descripcion);

            std::cout << "Ingrese el valor: ";
            std::cin >> valor;

            ElementosDeportivos e(nombre, deporte, descripcion, valor);
            inventario.push_back(e);

            std::cout << "Elemento deportivo registrado exitosamente.\n";
        }
        else if (opcion == 3) {
            std::cout << "\n=== Lista de Usuarios Registrados ===\n";
            for (const auto& u : usuarios) {
                std::cout << "Código   : " << u.getCodigo() << "\n";
                std::cout << "Nombres  : " << u.getNombres() << "\n";
                std::cout << "Apellidos: " << u.getApellidos() << "\n";
                std::cout << "Tipo     : " << u.getTipo() << "\n";
                std::cout << "-------------------------------------\n";
            }
            if (usuarios.empty()) {
                std::cout << " No hay usuarios registrados.\n";
            }
        }
        else if (opcion == 4) {
            std::cout << "\n=== Inventario de Elementos Deportivos ===\n";
            for (const auto& e : inventario) {
                std::cout << "Nombre      : " << e.getNombre() << "\n";
                std::cout << "Deporte     : " << e.getDeporte() << "\n";
                std::cout << "Descripción : " << e.getDescripcion() << "\n";
                std::cout << "Valor       : $" << e.getValor() << "\n";
                std::cout << "------------------------------------------\n";
            }
            if (inventario.empty()) {
                std::cout << "  No hay elementos deportivos registrados.\n";
            }
        }
        else if (opcion == 5) {
            //crear un objeto de tipo prestamo
             std::cout << " Solicitar Prestamo\n";

            std::cout << "\n=== Lista de Usuarios Registrados ===\n";
            for (const auto& u : usuarios) {
                std::cout << "Código   : " << u.getCodigo() << "\n";
                std::cout << "Nombres  : " << u.getNombres() << "\n";
                std::cout << "Apellidos: " << u.getApellidos() << "\n";
                std::cout << "Tipo     : " << u.getTipo() << "\n";
                std::cout << "-------------------------------------\n";
            }
            if (usuarios.empty()) {
                std::cout << " No hay usuarios registrados.\n";
            }

            std::cout << " De la lista seleccione un usuario\n";
            int se=0;
            std::string auxCodigo="";
            ElementosDeportivos auxPrestamo;
            do{
             // Pedir datos por teclado
            std::cout << "Ingrese el código del usuario selecionado: ";
            std::cin >> auxCodigo;
                    for (const auto& u : usuarios) {
                        if (u.getCodigo() == auxCodigo) {
                            std::cout << "El usuario selecionado es: "<< "\n";
                            std::cout << "Código   : " << u.getCodigo() << "\n";
                            std::cout << "Nombres  : " << u.getNombres() << "\n";
                            std::cout << "Apellidos: " << u.getApellidos() << "\n";
                            std::cout << "Tipo     : " << u.getTipo() << "\n";
                            std::cout << "-------------------------------------\n";
                            se=1;
                        }
                    }
                    ///Validar Usuarios no repetidos en el prestamo
                    for (const auto& p : prestamos) {
                        if(p.getCodigoUnivalluno()==auxCodigo and p.getEstado()=='E'){ 
                            std::cout << "El usuario selecionado ya tiene un prestamo: "<< "\n";
                            se=0;
                        }
                     }
                    ////////////////////////////////////////////////////   
                }while (se == 0);
             

            std::cout << "\nDel Inventario de Elementos Deportivos seleccione:\n";
            for (const auto& e : inventario) {
                std::cout << "Nombre      : " << e.getNombre() << "\n";
                std::cout << "Deporte     : " << e.getDeporte() << "\n";
                std::cout << "Descripción : " << e.getDescripcion() << "\n";
                std::cout << "Valor       : $" << e.getValor() << "\n";
                std::cout << "------------------------------------------\n";
            }
            if (inventario.empty()) {
                std::cout << "  No hay elementos deportivos registrados.\n";
            }
            se=0;
            std::string auxNombre="";
            do{
             // Pedir datos por teclado
            std::cout << "Ingrese el nombre del elemento deportivo selecionado: ";
            std::cin >> auxNombre;
                    for (const auto& u : inventario) {
                        if (u.getNombre() == auxNombre) {
                            auxPrestamo=u;
                          se=1;
                        }
                    }
                }while (se == 0);
                std::cout << "Nombre  del elemento deportivo seleccionado : " << auxPrestamo.getNombre()<< "\n";
                std::cout << "------------------------------------------\n";
        Prestamo unPrestamo(idAutonum, auxCodigo, auxNombre);
        prestamos.push_back(unPrestamo);
        idAutonum++;
        }
        else if (opcion == 6) {
            se=0;
            int auxID=0;
            do{
                std::cout << "\nCambiar Estado Prestamos del Sistema:\n";
                for (const auto& p : prestamos) {
                    std::cout << "Id prestamo     : " << p.getIdPrestamo() << "\n";
                    std::cout << "Codigo Univalluno      : " << p.getCodigoUnivalluno() << "\n";
                    std::cout << "Elemento deportivo     : " << p.getNombreElementoDeportivo() << "\n";
                    std::cout << "Estado : " << p.getEstado() << "\n";
                    std::cout << "------------------------------------------\n";
                }
                if (prestamos.empty()) {
                    std::cout << "  No hay prestamos registrados.\n";
                }
             // Pedir datos por teclado
            std::cout << "Ingrese el id del prestamo: ";
            std::cin >> auxID;
                    for (const auto& p : prestamos) {
                        if (p.getIdPrestamo() == auxID) {
                            p.setEstado('F');
                          se=1;
                        }
                    }
                }while (se == 0);


        }
        else if (opcion == 7) {
            std::cout << "\nPrestamos del sistema:\n";
            for (const auto& p : prestamos) {
                std::cout << "Codigo Univalluno      : " << p.getCodigoUnivalluno() << "\n";
                std::cout << "Elemento deportivo     : " << p.getNombreElementoDeportivo() << "\n";
                std::cout << "Estado : " << p.getEstado() << "\n";
                std::cout << "------------------------------------------\n";
            }
            if (inventario.empty()) {
                std::cout << "  No hay elementos deportivos registrados.\n";
            }

            //El sistema debe permitir consultar la cantidad de préstamos no finalizados
            std::cout << "\nPrestamos del sistema no finalizados:  ";
            int cantidadNoFinalizados=0;
            for (const auto& p : prestamos) {
               if(p.getEstado()=='E'){
                cantidadNoFinalizados++;
               }
            }
            std::cout << cantidadNoFinalizados<<"\n";

        }
        else if (opcion == 8) {
            std::cout << " Saliendo del sistema...\n";
        }
        else {
            std::cout << " Opción inválida.\n";
        }

    } while (opcion != 8);

    return 0;
}
