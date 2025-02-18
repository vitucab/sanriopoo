#include <iostream>
#include <map>
#include <cstring>
using namespace std;

class Agenda {
    public:
        Agenda ();
        void cargarAgenda(const string nya, const int nro) {
            agendita[nya] = nro;
        }
        int saberNro(const string nya) {
            auto i = agendita.find(nya);
            if(i != agendita.end()) {
                return i->second;
            } else {
                return -1;
            }
        }
    private:
        map<string,int>agendita;
};

int main() {
    Agenda ag;
    ag.cargarAgenda("ArianaGrande", 333);
    ag.cargarAgenda("VituCab", 666);
    int aux;
    aux = ag.saberNro("VituCab");
    cout << aux;
}