//
//  main.cpp
//  punto_sobrecarga
//
//  Created by Santiago Cacho Herrera on 30/05/25.
//

#include <iostream>
using namespace std;

class Punto {
private:
    float x;
    float y;
public:
    Punto(float x, float y) {
        this->x = x;
        this->y = y;
    }
    
    // getters
    float getX() const {
        return x;
    }
    
    float getY() const {
        return y;
    }
    
    // operador +
    Punto operator+(const Punto& p2) {
        return Punto(x + p2.x, y + p2.y);
    }
    
    // operador -
    Punto operator-(const Punto& p2) {
        return Punto(x - p2.x, y - p2.y);
    }
    
    // operador ==
    bool operator==(const Punto& p2) {
        return (x==p2.x) && (y==p2.y);
    }
    
    // operador =!
    bool operator!=(const Punto& p2) {
        return !(*this == p2);
    }
};

// operador <<
ostream& operator<<(ostream& salida, const Punto& p) {
    salida<<"Punto en: ("<<p.getX()<<", "<<p.getY()<<")"<<endl;
    return salida;
}

int main() {
    Punto p1(3.5, 2.5);
    Punto p2(1.5, 2.5);
    Punto p3(3, 2);
    Punto p4(3, 2);
    
    cout<<boolalpha;
    
    cout<<p1+p2<<endl;
    cout<<p1-p3<<endl;
    cout<<(p3==p4)<<endl;
    cout<<(p1!=p2)<<endl;

    return 0;
}
