#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

class Abecedario {
    public:
        Abecedario ();
        int contarLetras(const string text) {
            int cont = 0;
            for(char c : text) {
                if((c>='a' && c<= 'z') or (c>='A' && c<='Z')) {
                    cont++;
                }
            }
            return cont;
        }
        map<char, int> contarRepe(const string text) {
            map<char, int> abc;
            for(char c : text) {
                if((c>='a' && c<= 'z') or (c>='A' && c<='Z')) {
                    abc[tolower(c)]++;
                }
            }
            return abc;
        }
};

int main() {
    Abecedario a;
    string texto = "Mario Kart kontigo";
    int aux = a.contarLetras(texto);
    cout<<"La cantidad de letras que hay es: "<<aux<<endl;
    map<char, int> repe = a.contarRepe(text);
    cout<<"Repeticion de cada letra: "<<endl;
    for(const auto& r : repe) {
        cout<<r.first <<" : "<<r.second<<endl;
    }
    return 0;
}