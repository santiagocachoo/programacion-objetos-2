//
//  MiprimerObjeto.cpp
//  clase_1
//
//  Created by Santiago Cacho Herrera on 19/05/25.
#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string voz;
    
public:
    Persona(string nombre, int edad, string voz) {
        this-> nombre = nombre;
        this-> edad = edad;
        this-> voz = voz;
    }
    
    void presentarse() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." <<endl;
    }
    
    void cantar() {
        cout << nombre << " canta una canción!" <<endl;
    }
    
    void tono() {
        cout << nombre << " canta en: " << voz <<endl;
    }
};

