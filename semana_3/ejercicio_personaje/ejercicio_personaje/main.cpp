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
    string getNombre() const {
        return nombre;
    }
    
    int getEdad() const {
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
    
    // metodo y destructor virtual
    virtual void accionEspecial() const {
        cout<<nombre<<" realiza una acción especial"<<endl;
    }
    
    virtual ~Personaje() {
        cout<<"Destruyendo personaje: "<<nombre<<endl;
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
    
    // getter y setter de poder especial
    string getPoderEspecial() {
        return poderEspecial;
    }
    
    void setPoderEspecial(string poderEspecial) {
        this->poderEspecial = poderEspecial;
    }
    
    void accionEspecial() const override {
        cout<<getNombre()<<" usa su poder especial: "<<poderEspecial<<"!"<<endl;
    }
    
    ~Heroe() {
        cout<<"Destruyendo heroe: "<<getNombre()<<endl;
    }
};

class Villano : public Personaje {
private:
    string planMalvado;
    
public:
    Villano(string nombre, int edad, string planMalvado) : Personaje(nombre, edad) {
        this->planMalvado = planMalvado;
    }
    
    void accionEspecial() const override{
        cout<<getNombre()<<" ejecuta su plan malvado: "<<planMalvado<<"!"<<endl;
    }
    
    ~Villano() {
        cout<<"Destruyendo villano: "<<getNombre()<<endl;
    }
};


int main() {
    // crear objetos con diferentes constructores
    /*
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
     */
    
    Personaje *p1 = new Heroe("Mario", 30, "volar");
    Personaje *p2 = new Villano("Vector", 22, "robar la luna");
    
    p1->accionEspecial();
    p2->accionEspecial();
    
    delete p1;
    delete p2;
    
    return 0;
}
