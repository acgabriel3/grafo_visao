#include "estrutura.h"

using namespace std;

int main() {

    Grafo grafo;

    grafo.set_vertices("fluxo.txt");

    vector<Vertice> vertices = grafo.get_vertices();

    for(auto i : vertices) {
        cout << i.get_nome() << endl;
        cout << "\tCreditos: " << i.get_creditos() << endl;
        cout << "\tDificuldade: " << i.get_dificuldade() << endl;

        vector<Vertice> adjascentes = i.get_adjascentes();

        for(auto j : adjascentes) {
            cout << "\t\t" << j.get_nome() << endl;
        }
    }

    return 0;
}
