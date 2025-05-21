//
//  main.cpp
//  clase reposicion
//
//  Created by Santiago Cacho Herrera on 21/05/25.
//

#include <iostream>
#include "miembro.h"

using namespace std;

int main() {
    // Crear un miembro del gimnasio
    Miembro m1("Carlos Pérez", 28, "Premium", true);

    // Mostrar la información inicial
    cout << "Información del miembro:\n";
    m1.mostrarInformacion();

    // Cambiar el tipo de membresía
    m1.cambiarTipoMembresia("Básica");

    // Desactivar la membresía
    m1.cambiarEstadoMembresia(false);

    // Mostrar la información actualizada
    cout << "\nDespués de cambios:\n";
    m1.mostrarInformacion();

    return 0;
}
