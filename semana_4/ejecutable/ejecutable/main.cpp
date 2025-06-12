//
//  main.cpp
//  ejecutable
//
//  Created by Santiago Cacho Herrera on 02/06/25.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Usuario {
private:
    string nombre;
    int edad;
    string carrera;
    bool estudia;
    
public:
    virtual void pedirDatos() {
        string respuesta;
        
        cout<<"Ingresa tu nombre completo: ";
        getline(cin, nombre);
        
        cout<<"Ingresa tu edad: ";
        cin>>edad;
        cin.ignore();
        
        cout<<"Ingresa tu carrera o profesión: ";
        getline(cin, carrera);
        
        
        cout<<"¿Estudias actualmente? (si/no): ";
        getline(cin, respuesta);
        estudia = (respuesta == "si");
    }
    
    virtual void imprimirResumen() {
        cout<<"\nHola, me llamo "<<nombre<<endl;
        cout<<"Tengo "<<edad<<" y estudio/trabajo en: "<<carrera<<endl;
        cout<<"Actualmente estoy estudiando: "<<(estudia ? "si" : "no")<<endl;
    }
    
    // getters
    string getNombre() const {
        return nombre;
    }
    
    int getEdad() const {
        return edad;
    }
    
    string getCarrera() const {
        return carrera;
    }
    
    bool getEstudia() const {
        return estudia;
    }
};

class EstudianteUniversitario : public Usuario {
private:
    string universidad;
    
public:
    void pedirDatos() override {
        Usuario::pedirDatos();
        cout<<"Ingresa tu universidad: ";
        getline(cin, universidad);
    }
    
    void imprimirResumen() override {
        Usuario::imprimirResumen();
        cout<<"Universidad: "<<universidad<<endl;
        cout<<"Clase: Estudiante Universitario"<<endl;
    }
};

class EstudiantePreparatoria : public Usuario {
private:
    string preparatoria;
    
public:
    void pedirDatos() override {
        Usuario::pedirDatos();
        cout<<"Ingresa tu preparatoria: ";
        getline(cin, preparatoria);
    }
    
    void imprimirResumen() override {
        Usuario::imprimirResumen();
        cout<<"Preparatoria: "<<preparatoria<<endl;
        cout<<"Clase: Estudiante Preparatoria"<<endl;
    }
};

int main() {
    ifstream in("usuario.txt");
    if (in.is_open()) {
        string linea;
        cout<<"Datos previos:\n";
        while (getline(in, linea))cout<<linea<<endl;
        in.close();
        cout<<"---------------\n";
    }
    
    cout<<"Tipo de usuario (1: Estudiante Universitario, 2: Estudiante Preparatoria): ";
    int tipo;
    cin>>tipo;
    cin.ignore();
    
    Usuario *u;
    if (tipo==1) u = new EstudianteUniversitario();
    else u = new EstudiantePreparatoria();
    
    u->pedirDatos();
    u->imprimirResumen();
    
    ofstream out("usuario.txt");
    if (out.is_open()) {
        out<<"Nombre completo: "<<u->getNombre()<<"\n";
        out<<"Edad: "<<u->getEdad()<<"\n";
        out<<"Carrera: "<<u->getCarrera()<<"\n";
        out<<"Estudia actualmente: "<<(u->getEstudia() ? "si" : "no")<<"\n";
        if (tipo==1) out<<"Clase: Estudiante Universitario\n";
        else out<<"Clase: Estudiante de Preparatoria\n";
        out.close();
    }
    
    delete u;
    return 0;
}
