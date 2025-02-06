#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class DeMesa {
protected:
    int nro, cantidad_litros, anio_produccion, precio;
    char tipo;
public:
    DeMesa(int num, int cantlitros, int anioprod, char tip, int price) : nro(num), cantidad_litros(cantlitros), anio_produccion(anioprod), tipo(tip), precio(price) {}
    int calcularPrecio();
};

int DeMesa::calcularPrecio() {
    return this->precio * this->cantidad_litros;
}

class Premium : public DeMesa{
public:
    Premium(int num, int cantlitros, int anioprod, char tip, int price) : DeMesa(num, cantlitros, anioprod, 'p', 200){}
};

class Especial : public DeMesa {
public:
    Especial(int num, int cantlitros, int anioprod, char tip, int price) : DeMesa(num, cantlitros, anioprod, 'e', 320) {}
};

class Empresa {
private:
public:
    Empresa();
}

/*
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
    pair<int,int> anioDeterminado(int anioact);
    void archivoDeTexto(char* nombA, char* nombT);
    vector<int>masLitrosEn5();
    int elAnioMasVino();
    int elAnioMasMonto();
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
    int nro, cantidad, anio;
    char tipo;
    while(archivo.read(reinterpret_cast<char*>(&nro), sizeof(nro))){
        archivo.read(&tipo, sizeof(tipo));
        archivo.read(reinterpret_cast<char*>(&cantidad_litros), sizeof(cantidad_litros));
        archivo.read(reinterpret_cast<char*>(&anio_produccion), sizeof(anio_produccion));
        vinitos.push_back(nro,tipo,cantidad_litros, anio_produccion));
    }
    archivo.close();
}

pair<int,int> Empresa::anioDeterminado(int anioact) {
    int montototal = 0, litrostotal = 0;
    for(const auto& v : vinitos) {
        if(v->sePuedeVender(v,anioact)) {
            litrostotal += v->getCantLitros();
            montototal += v->calcularTotal();
        }
    }
    return {litrostotal, montototal};
}

void Empresa::archivoDeTexto(char* nombA, char* nombT) {
    leerArchivo(nombA);
    ofstream archivo2;
    archivo2.open(nombT);
    if(archivo2.fail()){
        return;
    }
    archivo2<<"Año - Litros - Monto"<<endl;
    for(int i=2020;i<=2023;++i) {
        auto [litros, monto] = anioDeterminado(i);
        archivo2<<i<<" - "<<litros<<" - "<<monto<<endl;
    }
    archivo2.close();
}

//lo hizo chatgpt, con suerte lo entendi :'v
vector<int> Empresa::masLitrosEn5() {
    map<int,int> litrosXAnio;
    for(const auto& v : vinitos) {
        litrosXAnio[v.anio_produccion]+=vino.cantidad_litros;
    }
    vector<pair<int,int>> ordenAnios(litrosXAnio.begin(),litrosXAnio.end());
    sort(ordenAnios.begin(), ordenAnios.end(), [](const auto &a, const auto &b) { return a.second > b.second; });
    vector<int> los5mas;
    for (size_t i = 0; i < min<size_t>(5, aniosOrdenados.size()); i++) {
        top5.push_back(aniosOrdenados[i].first);
    }
    return top5;
}

int Empresa::elAnioMasVino() {
    int maxA = 0, maxL = 0;
    for(int i=2020;i<=2025;i++) {
        auto [litros,_]=anioDeterminado(i);
        if(litros > maxL){
            maxL = litros;
            maxA = i;
        }
    }
    return maxA;
}

int Empresa::elAnioMasMonto() {
    int maxA = 0, maxM = 0;
    for(int i=2020;i<=2025;i++) {
        auto [_,monto]=anioDeterminado(i);
        if(monto > maxM){
            maxM = monto;
            maxA = i;
        }
    }
    return maxA;
}
*/

template <class T>
class Cola {
public:
    Cola();
    void add(T dato);
    T obtener();
    bool estaVacia() const; //no la pide pero la necesito
private:
    struct Nodo {
        T dato;
        Nodo* sig;
    }
    Nodo* frente;
    Nodo* final;
    int size;
}

bool Cola::estaVacia() const {
    return frente == nullptr;
}

void Cola::add(T dato) {
    Nodo* nuevoNodo = new Nodo{dato, nullptr};
    if(estaVacia()){
        frente=final=nuevoNodo;
    } else {
        final->sig = nuevoNodo;
        final = nuevoNodo;
    }
    size++;
}

T Cola::obtener() {
    if(estaVacia()) {
        return T{};
    }
    Nodo* aux = frente;
    T dato = frente->dato;
    frente = frente->sig;
    if(frente == nullptr){
        final=nullptr;
    }
    delete aux;
    size--;
    return dato;
}