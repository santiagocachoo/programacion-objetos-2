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
    
    // getters
    string getNombre() const {
        return nombre;
    }
    
    int getEdad() const {
        return edad;
    }
    
    string getTipoMembresia() const {
        return tipoMembresia;
    }
    
    bool getActivo() const {
        return activo;
    }
    
    // setters
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    
    void setEdad(int edad) {
        this->edad = edad;
    }
    
    void setTipoMembresia(string tipoMembresia) {
        this-> tipoMembresia = tipoMembresia;
    }
    
    void setActivo(bool activo) {
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
    
    // metodo virtual
    virtual void mostrarRol() const {
        cout<<"Miembro general del sistema"<<endl;
    }
    
    virtual ~Miembro() {}
};

class MiembroRegular : public Miembro {
private:
    int puntosAntiguedad;
    
public:
    MiembroRegular(string nombre, int edad, string tipoMembresia, bool activo, int puntosAntiguedad) : Miembro(nombre, edad, tipoMembresia, activo){
        this->puntosAntiguedad = puntosAntiguedad;
    }
    
    int getPuntosAntiguedad() const {
        return puntosAntiguedad;
    }
    
    void setPuntosAntiguedad(int puntosAntiguedad) {
        this->puntosAntiguedad = puntosAntiguedad;
    }
    
    void mostrarRol() const override {
        cout<<"Miembro regular con "<<puntosAntiguedad<<" puntos de antiguedad"<<endl;
    }
};

class MiembroPremium : public Miembro {
private:
    string beneficios;
    
public:
    MiembroPremium(string nombre, int edad, string tipoMembresia, bool activo, string beneficios) : Miembro(nombre, edad, tipoMembresia, activo) {
        this->beneficios = beneficios;
    }
    
    string getBeneficios() const {
        return beneficios;
    }
    
    void setBeneficios(string beneficios) {
        this->beneficios = beneficios;
    }
    
    void mostrarRol() const override {
        cout<<"Miembro premium con beneficios: "<<beneficios<<endl;
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
    
    int getDuracion() { return duracion; }
    void setDuracion(int nDuracion) { duracion = nDuracion; }

    float getPrecio() { return precio; }
    void setPrecio(float nPrecio) { precio = nPrecio; }

    std::string getNIP() { return nip; }
    void setNIP(std::string nNIP) { nip = nNIP; }

    virtual void costo() {
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

class MembresiaEstudiantil : public Membresia {
private:
    float descuento;
public:
    MembresiaEstudiantil(int d, float p, std::string n) : Membresia(d, p, n) { descuento = 0.2; }
    MembresiaEstudiantil(int d, float p, std::string n, float des) : Membresia(d, p, n) { descuento = des; }

    void mostrarDescuento() {
        std::cout << "El descuento de la membresia Estudiantil es: " << (descuento * 100) << "%" << std::endl;
    }

    void costo() override {
        std::cout << "La membresia estudiantil con duracion de " << getDuracion() << " meses tiene un costo de: " << getPrecio() * (1 - descuento) << " pesos" << std::endl;
    }
};

class Promocion : public Membresia {
private:
    float descuentoN;
    float descuentoBF;
    float descuentoV;
public:
    Promocion(int d, float p, std::string n) : Membresia(d, p, n) { descuentoN = 0.3; descuentoBF = 0.25; descuentoV = 0.15; }
    Promocion(int d, float p, std::string n, float desN, float desBF, float desV) : Membresia(d, p, n) { descuentoN = desN; descuentoBF = desBF; descuentoV = desV; }

    void mostrarPromociones() {
        std::cout << "El descuento durante las temporadas de Navidad es de: " << (descuentoN * 100) << "%" << std::endl
        << "El descuento durante el Buen Fin es de: " << (descuentoBF * 100) << "%" << std::endl
        << "El descuento durante las temporadas de verano es de: " << (descuentoV * 100) << "%" << std::endl;
    }

    void costo() override {
        std::cout << "Las proximas promociones seran en verano, con eso su membresia de " << getDuracion() << " meses tendra un costo de: " << getPrecio() * (1 - descuentoBF) << " pesos" << std::endl;
    }
};

class RegistroMembresia {
protected:
    string nombre;
    int edad;
    int duracion;

public:
    RegistroMembresia(string nombre, int edad, int duracion)
        : nombre(nombre), edad(edad), duracion(duracion) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    int getDuracion() const { return duracion; }

    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setDuracion(int d) { duracion = d; }

    virtual void bienvenida() const {
        cout << "================================================================================" << endl;
        cout << "Hola " << nombre << ", bienvenido!" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
    }

    virtual void despedida() const {
        cout << "================================================================================" << endl;
        cout << "Gracias " << nombre << " por tu visita. ¡Hasta pronto!" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
    }

    void renovar() {
        cout << "================================================================================" << endl;
        cout << "La duracion de tu membresia es " << duracion << "." << endl;
        cout << "Procesando pago por un mes de membresia..." << endl;
        duracion += 1;
        cout << "Hola " << nombre << " gracias por renovar tu membresia por otro mes." << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
    }

    virtual ~RegistroMembresia() {
        cout << "Membresia de " << nombre << " eliminada." << endl;
    }
};

class AccesoBox : public RegistroMembresia {
public:
    AccesoBox(string nombre, int edad, int duracion)
        : RegistroMembresia(nombre, edad, duracion) {}

    void bienvenida() const override {
        cout << "================================================================================" << endl;
        cout << "Bienvenido al RING de BOXEO, " << nombre << "!" << endl;
        cout << "Preparate para una sesión intensa." << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
    }

    void despedida() const override {
        cout << "================================================================================" << endl;
        cout << nombre << ", excelente trabajo en el ring. ¡Hasta la proxima pelea!" << endl;
    }
};

class AccesoBasquet : public RegistroMembresia {
public:
    AccesoBasquet(string nombre, int edad, int duracion)
        : RegistroMembresia(nombre, edad, duracion) {}

    void bienvenida() const override {
        cout << "================================================================================" << endl;
        cout << "Bienvenido a la CANCHA de BASQUET, " << nombre << "!" << endl;
        cout << "Disfruta tu juego." << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
    }

    void despedida() const override {
        cout << "================================================================================" << endl;
        cout << nombre << ", gracias por jugar. ¡Nos vemos en la proxima practica!" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Duracion Membresia: " << duracion << endl;
    }
};


int main() {
    /*
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
     */
    Miembro* miembro1 = new MiembroRegular("Juan", 30, "Regular", true, 150);
    Miembro* miembro2 = new MiembroPremium("Ana", 40, "Premium", true, "Acceso VIP y regalos");
    Membresia* me = new MembresiaEstudiantil(12, 999.99, "0708");
    Membresia* mp = new Promocion(12, 999.99, "0708");
    RegistroMembresia* m1 = new RegistroMembresia("Julian Medina", 18, 3);
    RegistroMembresia* m2 = new RegistroMembresia("Rodolfo Guerra", 45, 0);

    miembro1->mostrarInformacion();
    miembro2->mostrarInformacion();
    me->costo();
    mp->costo();
    m1->bienvenida();
    m2->bienvenida();
    
    delete miembro1;
    delete miembro2;
    delete me;
    delete mp;
    delete m1;
    delete m2;
    
    return 0;
}
