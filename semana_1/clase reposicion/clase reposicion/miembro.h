//
//  miembro.h
//  clase reposicion
//
//  Created by Santiago Cacho Herrera on 21/05/25.
//

#ifndef miembro_h
#define miembro_h

#include <string>
using namespace std;

class Miembro {
private:
    string nombre;
    int edad;
    string tipoMembresia;
    bool activo;
    
public:
    Miembro(string nombre, int edad, string tipoMembresia, bool activo);
    
    // metodos
    void mostrarInformacion();
    void cambiarEstadoMembresia(bool nuevoEstado);
    void cambiarTipoMembresia(string nuevoTipo);
    bool estaActivo();
};

#endif
