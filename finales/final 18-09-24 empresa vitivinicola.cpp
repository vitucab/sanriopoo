#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
class Vino {
protected:
    int nro, cantidad_litros, anio_produccion, espera;
    char tipo;
public:
    Vino(int num, int cantlitros, int anioprod){
        this->cantidad_litros = cantlitros;
        this->anio_produccion = anioprod;
        this->nro = num;
    }
    int calcularPrecio();
};

int Vino::calcularPrecio() {
    return this->precio * this->cantidad_litros;
}

class DeMesa {
public:
    DeMesa() {
        this->precio = 120;
        this->tipo = 'm';
        this->espera = 1;
    }
};

class Premium {
public:
    Premium(int cantlitros, int anioprod){
        this->precio = 200;
        this->tipo = 'p';
        this->espera = 2;
    }
};

class Especial {
public:
    Especial(int cantlitros, int anioprod) {
        this->precio = 320;
        this->tipo = 'e';
        this->espera = 3;
    }
};

class Empresa {
private:
public:
    Empresa();
}
*/

class Vino {
protected:
    int nro, cantidad_litros, anio_produccion, precio, espera;
    char tipo;
public:
    Vino(int num, int cantlitros, int anioprod, char t){
        this->cantidad_litros = cantlitros;
        this->anio_produccion = anioprod;
        this->nro = num;
        this->tipo = t;
    }
    void getPrecioYEspera();
    int calcularTotal();
    int getEspera() {
        return espera;
    }
    int getPrecio() {
        return precio;
    }
    int getCantLitros() {
        return cantidad_litros;
    }
    int getAnioProd() {
        return anio_produccion;
    }
    int getNro(){
        return nro;
    }
    char getTipo() {
        return t;
    }
};

void Vino::getPrecioYEspera() {
    if (tipo == 'm') {
        precio = 120;
        espera = 1;
    } else if(tipo == 'p') {
        precio = 200;
        espera = 2;
    } else if (tipo == 'e') {
        precio = 320;
        espera = 3;
    }
}

void Vino::calcularTotal() {
    return this->getPrecio * this->getCantLitros;
}

class Empresa {
private:
    Vino* v;
    vector<Vino*> vinitos;
public:
    Empresa();
    bool sePuedeVender(Vino* v, int anioact);
    void leerArchivo(char* nombA);
    void anioDeterminado(int anioact);
};

bool Empresa::sePuedeVender(Vino* v, int anioact) {
    if ((anioact - v->getAnioProd) >= v->getEspera){
        return true;
    }
    return false;
}

void Empresa::leerArchivo(char* nombA){
    ifstream archivo;
    archivo.open(nombA, ios::binary);
    if(archivo.fail()){
        return;
    }
    while(archivo.eof()){
        int nro, cantidad_litros, anio_produccion;
        char tipo;
        archivo.read(reinterpret_cast<char*>(&nro), sizeof(nro));
        archivo.read(&tipo, sizeof(tipo));
        archivo.read(reinterpret_cast<char*>(&cantidad_litros), sizeof(cantidad_litros));
        archivo.read(reinterpret_cast<char*>(&anio_produccion), sizeof(anio_produccion));
        vinitos.push_back(Vino*(nro,tipo,cantidad_litros, anio_produccion));
    }
    archivo.close();
}

void Empresa::anioDeterminado(int anioact) {
    int montototal = 0, litrostotal = 0;
    for(const auto& v1 : vinitos) {
        if(v1->sePuedeVender(v1,anioact)) {
            litrostotal += v1->getCantLitros();
            montototal += v1->calcularTotal();
        }
    }
    cout<<"Litros que se pueden vender: "<<litrostotal<<endl;
    cout<<"El monto que se puede obtener: "<<montototal<<endl;
}

