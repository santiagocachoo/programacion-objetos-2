//
//  main.cpp
//  punteros
//
//  Created by Santiago Cacho Herrera on 22/05/25.
//

#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string hobby;
    
public:
    // constructor
    Persona(string nombre, int edad, string hobby) {
        this->nombre = nombre;
        this->edad = edad;
        this->hobby = hobby;
        
    }
    
    // metodo para presentarse
    void presentarte() {
        cout<<"Hola, soy "<<nombre<<" y tengo "<<edad<<" años."<<endl;
    }
    
    // metodo de cumpleaños
    void cumpleaños() {
        this->edad += 1;
        cout<<nombre<<" acaba de cumplir años. Ahora tiene "<<edad<<" años."<<endl;
    }
    
    // metodo de hobby
    void miHobby() {
        cout<<"Soy "<<nombre<<" y mi hobby es "<<hobby<<endl;
    }
};

int main() {
    Persona *p1 = new Persona("Mariana", 20, "Carpinteria");
    Persona *p2 = new Persona("Pepe", 18, "Beber");
    Persona *p3 = new Persona("Jesucristo", 33, "Videojuegos");
    
    p1->presentarte();
    p1->cumpleaños();
    p1->miHobby();
    
    p2->presentarte();
    p2->cumpleaños();
    p2->miHobby();
    
    p3->presentarte();
    p3->cumpleaños();
    p3->miHobby();
    
    return 0;
}
