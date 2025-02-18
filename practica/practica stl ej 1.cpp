#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
using namespace std;

int main() {
    list<int> nros;
    //meto los 200 nros en la lista
    rand(time(nullptr));
    for(int i=0; i<200; i++) {
        nros.push_back(rand()%1000+1);
    }
    //imprimir
    for(auto &a : nros) {
        cout<<a<<endl;
    }
    //ordenar sin tener en cuenta los 10 primeros ni 50 ultimos
    auto inicio = next(nros.begin(), 10);
    auto fin = prev(nros.end(), 50);
    list<int> nros2(inicio, fin);
    sort(nros2.begin(), nros2.end(), [](const auto &a, const auto &b) { return a < b;});
    //imprimir de nuevo
    for(auto &a : nros2) {
        cout<<a<<endl;
    }
    //ordenar descendiente
    sort(nros2.begin(), nros2.end(), [](const auto &a, const auto &b) { return a > b;});
    //imprimir de nuevo
    for(auto &a : nros2) {
        cout<<a<<endl;
    }
}