//
//  miembro.cpp
//  clase reposicion
//
//  Created by Santiago Cacho Herrera on 21/05/25.
//

#include "miembro.h"
#include <iostream>

Miembro::Miembro(string nombre, int edad, string tipoMembresia, bool activo) {
    this->nombre = nombre;
    this->edad = edad;
    this->tipoMembresia = tipoMembresia;
    this->activo = activo;
}

void Miembro::mostrarInformacion() {
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Tipo de membresia: "<<tipoMembresia<<endl;
    cout<<"Estado: "<<(activo ? "Activo" : "Inactivo")<<endl;
}

void Miembro::cambiarEstadoMembresia(bool nuevoEstado) {
    activo = nuevoEstado;
}

void Miembro::cambiarTipoMembresia(string nuevoTipo) {
    tipoMembresia = nuevoTipo;
}

bool Miembro::estaActivo() {
    return activo;
}
