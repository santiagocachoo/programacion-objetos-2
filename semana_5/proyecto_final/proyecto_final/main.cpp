#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setTipoMembresia(string tipoMembresia) {
        this->tipoMembresia = tipoMembresia;
    }

    void setActivo(bool activo) {
        this->activo = activo;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Tipo de membresia: " << tipoMembresia << endl;
        cout << "Estado: " << (activo ? "Activo" : "Inactivo") << endl;
    }

    virtual void mostrarRol() const {
        cout << "Miembro general del sistema" << endl;
    }

    virtual ~Miembro() {}
};

class MiembroRegular : public Miembro {
private:
    int puntosAntiguedad;

public:
    MiembroRegular(string nombre, int edad, string tipoMembresia, bool activo, int puntosAntiguedad) : Miembro(nombre, edad, tipoMembresia, activo) {
        this->puntosAntiguedad = puntosAntiguedad;
    }

    int getPuntosAntiguedad() const {
        return puntosAntiguedad;
    }

    void setPuntosAntiguedad(int puntosAntiguedad) {
        this->puntosAntiguedad = puntosAntiguedad;
    }

    void mostrarRol() const override {
        cout << "Miembro regular con " << puntosAntiguedad << " puntos de antiguedad" << endl;
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
        cout << "Miembro premium con beneficios: " << beneficios << endl;
    }
};

class Membresia {
private:
    int duracion;
    float precio;
    string nip;

public:
    Membresia(int duracion, float precio, string nip) {
        this->duracion = duracion;
        this->precio = precio;
        this->nip = nip;
    }

    void ensenar_duracion() {
        if (duracion < 12) {
            cout << "La membresia es de " << duracion << " meses" << endl;
        } else {
            cout << "La membresia es de " << (duracion / 12.0) << " años" << endl;
        }
    }

    int getDuracion() { return duracion; }
    void setDuracion(int nDuracion) { duracion = nDuracion; }

    float getPrecio() { return precio; }
    void setPrecio(float nPrecio) { precio = nPrecio; }

    string getNIP() { return nip; }
    void setNIP(string nNIP) { nip = nNIP; }

    virtual void costo() {
        cout << "Esta membresia tiene un costo de: " << precio << " pesos" << endl;
    }

    void ensenar_nip() {
        cout << "Su NIP es: " << nip << endl;
    }

    void probar_nip() {
        string input;
        cout << "Inserte su NIP: " << endl;
        cin >> input;
        if (input == nip) {
            cout << "Su NIP es correcto, disfrute su entrenamiento" << endl;
        } else {
            cout << "Su NIP es incorrecto" << endl;
        }
    }
};

class MembresiaEstudiantil : public Membresia {
private:
    float descuento;

public:
    MembresiaEstudiantil(int d, float p, string n)
        : Membresia(d, p, n) {
        descuento = 0.2;
    }

    MembresiaEstudiantil(int d, float p, string n, float des)
        : Membresia(d, p, n) {
        descuento = des;
    }

    void mostrarDescuento() {
        cout << "El descuento de la membresia Estudiantil es: " << (descuento * 100) << "%" << endl;
    }

    void costo() override {
        cout << "La membresia estudiantil con duracion de " << getDuracion() << " meses tiene un costo de: " << getPrecio() * (1 - descuento) << " pesos" << endl;
    }
};

class Promocion : public Membresia {
private:
    float descuentoN;
    float descuentoBF;
    float descuentoV;

public:
    Promocion(int d, float p, string n)
        : Membresia(d, p, n) {
        descuentoN = 0.3;
        descuentoBF = 0.25;
        descuentoV = 0.15;
    }

    Promocion(int d, float p, string n, float desN, float desBF, float desV)
        : Membresia(d, p, n) {
        descuentoN = desN;
        descuentoBF = desBF;
        descuentoV = desV;
    }

    void mostrarPromociones() {
        cout << "El descuento durante las temporadas de Navidad es de: " << (descuentoN * 100) << "%" << endl
             << "El descuento durante el Buen Fin es de: " << (descuentoBF * 100) << "%" << endl
             << "El descuento durante las temporadas de verano es de: " << (descuentoV * 100) << "%" << endl;
    }

    void costo() override {
        cout << "Las proximas promociones seran en verano, con eso su membresia de " << getDuracion() << " meses tendra un costo de: " << getPrecio() * (1 - descuentoBF) << " pesos" << endl;
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

    void setNombre(string nombre) { nombre = nombre; }
    void setEdad(int edad) { edad = edad; }
    void setDuracion(int duracion) { duracion = duracion; }

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
    }

    void despedida() const override {
        cout << "================================================================================" << endl;
        cout << nombre << ", gracias por jugar. ¡Nos vemos en la proxima practica!" << endl;
    }
};

void guardarRegistroEnArchivo(const RegistroMembresia* r, const string& archivo) {
    ofstream out(archivo, ios::app);
    if (out.is_open()) {
        out << r->getNombre() << "," << r->getEdad() << "," << r->getDuracion() << endl;
        out.close();
    }
}

void leerRegistrosDesdeArchivo(const string& archivo) {
    ifstream in(archivo);
    string linea;
    if (in.is_open()) {
        cout << "=== Registros guardados ===" << endl;
        while (getline(in, linea)) {
            cout << linea << endl;
        }
        in.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main() {
    vector<Miembro*> miembros;
    vector<Membresia*> membresias;
    vector<RegistroMembresia*> registros;
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Crear miembro regular\n";
        cout << "2. Crear miembro premium\n";
        cout << "3. Crear membresia estudiantil\n";
        cout << "4. Crear promocion\n";
        cout << "5. Simular acceso a Box\n";
        cout << "6. Simular acceso a Basquet\n";
        cout << "7. Mostrar todos los miembros\n";
        cout << "8. Leer registros\n";
        cout << "9. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, tipo;
            int edad, puntos;
            bool activo;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad; cin.ignore();
            cout << "Tipo membresia: "; getline(cin, tipo);
            cout << "Activo (1/0): "; cin >> activo;
            cout << "Puntos antiguedad: "; cin >> puntos; cin.ignore();
            Miembro* m = new MiembroRegular(nombre, edad, tipo, activo, puntos);
            miembros.push_back(m);
        } else if (opcion == 2) {
            string nombre, tipo, beneficios;
            int edad;
            bool activo;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad; cin.ignore();
            cout << "Tipo membresia: "; getline(cin, tipo);
            cout << "Activo (1/0): "; cin >> activo; cin.ignore();
            cout << "Beneficios: "; getline(cin, beneficios);
            Miembro* m = new MiembroPremium(nombre, edad, tipo, activo, beneficios);
            miembros.push_back(m);
        } else if (opcion == 3) {
            int duracion;
            float precio;
            string nip;
            cout << "Duracion (meses): "; cin >> duracion;
            cout << "Precio: "; cin >> precio;
            cout << "NIP: "; cin >> nip;
            Membresia* me = new MembresiaEstudiantil(duracion, precio, nip);
            me->ensenar_duracion();
            me->costo();
            me->ensenar_nip();
            me->probar_nip();
            membresias.push_back(me);
        } else if (opcion == 4) {
            int duracion;
            float precio;
            string nip;
            cout << "Duracion (meses): "; cin >> duracion;
            cout << "Precio: "; cin >> precio;
            cout << "NIP: "; cin >> nip;
            Membresia* pr = new Promocion(duracion, precio, nip);
            pr->costo();
            membresias.push_back(pr);
            cout << "Promoción creada<"<<endl;
        } else if (opcion == 5) {
            string nombre;
            int edad, duracion;
            cout << "Nombre: "; cin >> nombre;
            cout << "Edad: "; cin >> edad;
            cout << "Duracion: "; cin >> duracion;
            RegistroMembresia* acceso = new AccesoBox(nombre, edad, duracion);
            acceso->bienvenida();
            acceso->despedida();
            guardarRegistroEnArchivo(acceso, "registros.txt");
            registros.push_back(acceso);
        } else if (opcion == 6) {
            string nombre;
            int edad, duracion;
            cout << "Nombre: "; cin >> nombre;
            cout << "Edad: "; cin >> edad;
            cout << "Duracion: "; cin >> duracion;
            RegistroMembresia* acceso = new AccesoBasquet(nombre, edad, duracion);
            acceso->bienvenida();
            acceso->despedida();
            guardarRegistroEnArchivo(acceso, "registros.txt");
            registros.push_back(acceso);
        } else if (opcion == 7) {
            for (auto m : miembros) {
                m->mostrarInformacion();
                m->mostrarRol();
            }
        } else if (opcion == 8) {
            leerRegistrosDesdeArchivo("registros.txt");
        }

    } while (opcion != 9);

    for (auto m : miembros) delete m;
    for (auto me : membresias) delete me;
    for (auto r : registros) delete r;

    return 0;
    
}

