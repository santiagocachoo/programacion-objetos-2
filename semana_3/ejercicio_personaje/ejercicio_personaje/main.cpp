//
//  main.cpp
//  ejercicio_personaje
//
//  Created by Santiago Cacho Herrera on 29/05/25.
//

#include <iostream>
using namespace std;

class Personaje {
private:
    string nombre;
    int edad;
    
public:
    
    // constructor vacio
    Personaje() {
        nombre = "Desconocido";
        edad = 0;
    }

    // constructor con dos atributos
    Personaje(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }
    
    // constructor solo con nombre y edad con 18
    Personaje(string nombre) {
        this->nombre = nombre;
        edad = 18;
    }
    
    // constructor solo con edad
    Personaje(int edad) {
        nombre = "Desconocido";
        this->edad = edad;
    }
    
    // getters
    string getNombre() {
        return nombre;
    }
    
    int getEdad() {
        return edad;
    }
    
    // setters
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    
    void setEdad(int edad) {
        this->edad = edad;
    }
    
    
    // metodo para mostrar información
    void mostrarInformacion() {
        cout<<"Nombre: "<<nombre<<", Edad: "<<edad<<endl;;
    }
};

class Heroe : public Personaje {
private:
    string poderEspecial;
public:
    // constructor que llama al constructor base con nombre y edad
    Heroe(string nombre, int edad, string poderEspecial) : Personaje(nombre, edad) {
        this->poderEspecial = poderEspecial;
    }
    
    // metodo especifico de heroe
    void presentarHeroe() {
        cout<<"Soy "<<getNombre()<<", un heroe con el poder de "<<poderEspecial<<endl;
    }
    
    // getter y setter de poder especiañ
    string getPoderEspecial() {
        return poderEspecial;
    }
    
    void setPoderEspecial(string poderEspecial) {
        this->poderEspecial = poderEspecial;
    }
};

int main() {
    // crear objetos con diferentes constructores
    Personaje personajeSinNada;
    Personaje personajeCompleto("Oscar", 40);
    Personaje personajeConNombre("Pepe");
    Personaje personajeConEdad(22);
    
    personajeSinNada.mostrarInformacion();
    personajeCompleto.mostrarInformacion();
    personajeConNombre.mostrarInformacion();
    personajeConEdad.mostrarInformacion();
    
    // HEROES
    Heroe ironman("Iron Man", 42, "tener dinero");
    Heroe batman("Batman", 40, "tener mucho dinero");
    Heroe drStrange("Dr. Strange", 45, "magia");
    Heroe flash("Flash", 19, "supervelocidad");
    
    batman.setPoderEspecial("ser huerfano");
    cout<<"El poder de "<<batman.getNombre()<<" es: "<<batman.getPoderEspecial()<<endl;
    
    return 0;
}
