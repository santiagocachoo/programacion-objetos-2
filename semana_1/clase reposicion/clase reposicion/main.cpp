//
//  main.cpp
//  clase reposicion
//  Created by Santiago Cacho Herrera on 21/05/25.

#include <iostream>
using namespace std;

const int GRAVEDAD = 9.81;

class Pelota {
private:
    string color;
    float diametro;
    string tipo;
    float masa;
    
public:
    // constructor
    Pelota(string color, float diametro, string tipo, float masa) {
        this->color = color;
        this->diametro = diametro;
        this->tipo = tipo;
        this->masa = masa;
    }
    
    // getters
    string getColor() {
        return color;
    }
    
    float getDiametro() {
        return diametro;
    }
    
    string getTipo() {
        return tipo;
    }
    
    float getMasa() {
        return masa;
    }
    
    // metodo para ver como rebota la pelota
    void rebotar() {
        if (tipo == "futbol") {
            cout<<"La pelota rebota poco"<<endl;
        } else if (tipo == "voleibol") {
            cout<<"La pelota rebota medio"<<endl;
        } else if (tipo == "basquetbol") {
            cout<<"La pelota rebota mucho"<<endl;
        } else {
            cout<<"La pelota tiene un rebote desconocido"<<endl;
        }
    }
    
    // metodo para mostrar información
    void mostrarDatos() {
        cout<<"Color: "<<color<<endl;
        cout<<"Diametro: "<<diametro<<endl;
        cout<<"Tipo de pelota: "<<tipo<<endl;
        cout<<"Masa: "<<masa<<endl;
        cout<<"Peso: "<<calcularPeso()<<endl;
    }
    
    // metodo para calcular peso
    float calcularPeso() {
        return masa * GRAVEDAD;
    }
    
    // sobrecarga de operadores
    Pelota operator+(const Pelota& p2) {
        return Pelota(color + p2.color, diametro + p2.diametro, tipo + p2.tipo, masa + p2.masa);
    }
};


int main() {
    // crear pelotas
    Pelota pFutbol("blanco", 22, "futbol", 410 );
    Pelota pBasquetbol("naranja", 75, "basquetbol", 650);
    Pelota pVoleibol("azul", 21, "voleibol", 270);
    Pelota pTenis("verde", 6.5, "tenis", 58.5);
    
    // probar metodo de rebotar
    pFutbol.rebotar();
    pBasquetbol.rebotar();
    pVoleibol.rebotar();
    pTenis.rebotar();
    
    // probar metodo de calcular peso
    cout<<pFutbol.calcularPeso()<<endl;
    cout<<pBasquetbol.calcularPeso()<<endl;
    cout<<pVoleibol.calcularPeso()<<endl;
    cout<<pTenis.calcularPeso()<<endl;

    // probar sobrecarga de operadores
    Pelota mezclaDePelotas = pFutbol + pBasquetbol;
    mezclaDePelotas.mostrarDatos();
    
    return 0;
}
