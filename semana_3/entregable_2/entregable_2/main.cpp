//
//  main.cpp
//  entregable_2
//
//  Created by Santiago Cacho Herrera on 26/05/25.
//

#include <iostream>
using namespace std;

class Miembro {
private:
    string nombre;
    int edad;
    string tipoMembresia;
    bool activo;
    
public:
    Miembro(string nombre, int edad, string tipoMembresia, bool activo) {
        this->nombre = nombre;
        this->edad = edad;
        this->tipoMembresia = tipoMembresia;
        this->activo = activo;
    }
    
    // metodos
    void mostrarInformacion() {
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Edad: "<<edad<<endl;
        cout<<"Tipo de membresia: "<<tipoMembresia<<endl;
        cout<<"Estado: "<<(activo ? "Activo" : "Inactivo")<<endl;
    }
    
    void cambiarEstadoMembresia(bool nuevoEstado) {
        activo = nuevoEstado;
    }
    
    void cambiarTipoMembresia(string nuevoTipo) {
        tipoMembresia = nuevoTipo;
    }
    
    bool estaActivo() {
        return activo;
    }
};

class Membresia {
private:
    int duracion;
    float precio;
    std::string nip;
public:
    Membresia(int duracion, float precio, std::string nip) {
        this->duracion = duracion;
        this->precio = precio;
        this->nip = nip;
    }
    void ensenar_duracion() {
        if (duracion < 12) {
            std::cout << "La membresia es de " << duracion << " meses" << std::endl;
        }
        else {
            std::cout << "La membresia es de " << (duracion / 12.0) << " años" << std::endl;
        }
    }
    void costo() {
        std::cout << "Esta membresia tiene un costo de: " << precio << " pesos" << std::endl;
    }
    void ensenar_nip() {
        std::cout << "Su NIP es: " << nip << std::endl;
    }
    void probar_nip() {
        std::string input;
        std::cout << "Inserte su NIP: " << std::endl;
        std::cin >> input;
        if (input == nip) {
            std::cout << "Su NIP es correcto, disfrute su entrenamiento" << std::endl;
        }
        else {
            std::cout << "Su NIP es incorrecto" << std::endl;
        }
    }
};

class RegistroMembresia {
private:
    string nombre;
    int edad;
    int duracion;

public:
    RegistroMembresia(string nombre, int edad, int duracion){
        this->nombre = nombre;
        this->edad = edad;
        this->duracion = duracion;
    }
    void bienvenida(){
        cout << "================================================================================" << endl;
        cout << "Hola " << nombre << " que tengas una buena sesion!" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
    }
    void renovar(){
        cout << "================================================================================" << endl;
        cout << "La duracion de tu membresia es " << duracion << "." << endl;
        cout << "Procesando pago por un mes de membresia..." << endl;
        this->duracion += 1;
        cout << "Hola " << nombre << " gracias por renovar tu membresia por otro mes." << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
        
    }
    void despedida(){
        cout << "================================================================================" << endl;
        cout << "Muchas gracias por usar nuestro servicio " << nombre << " que tengas un excelente dia!!!" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
        cout << "================================================================================" << endl;
    }
};


int main() {
    Miembro miembro1("Diego", 19, "Premium", true);
    Membresia membresia1(12, 2500, "1985");
    RegistroMembresia registro1("Diego", 19 , 12);
    
    Miembro *miembro2 = new Miembro("Rogelio", 21, "Premium", true);
    Membresia *membresia2 = new Membresia(6, 1000, "pepe");
    RegistroMembresia *registro2 = new RegistroMembresia("Santiago", 20, 3);
    
    miembro1.mostrarInformacion();
    membresia1.ensenar_nip();
    registro1.bienvenida();
    
    miembro2->mostrarInformacion();
    membresia2->ensenar_duracion();
    registro2->despedida();
    
    
    return 0;
}
