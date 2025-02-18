#include <iostream>
#include <map>
#include <string>
using namespace std;

class Agenda {
    public:
        Agenda ();
        void cargarAgenda(const string fecha, const string nya) {
            agendita[fecha].push_back(nya);
        }
        string saberCum(const string fecha) {
            auto i = agendita.find(fecha);
            if(i != agendita.end()) {
                string aux;
                for(const auto& n : i->second) {
                    aux += n + " , ";
                }
                return aux;
            } else {
                return "No se encontró";
            }
        }
    private:
        map<string, vector<string>>agendita;
};

int main() {
    Agenda ag;
    ag.cargarAgenda("17/07/2002", "vitu");
    ag.cargarAgenda("01/08/2002", "pawpi");
    ag.cargarAgenda("01/08/2002", "tumama");
    string aux;
    aux = ag.saberCum("01/08/2002");
    cout<<aux;
}