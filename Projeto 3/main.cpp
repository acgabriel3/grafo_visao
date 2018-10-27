#include "grafo.h"

using namespace std;

int main() {

    Grafo grafo;
    grafo.setProfessores();
    grafo.setEscolas();

    vector<Professor> professores = grafo.getProfessores();
    vector<Escola> escolas = grafo.getEscolas();

    cout << "\tPROFESSORES\n\n";

    for(auto i : professores) {
        cout << i.getId() << endl;
        cout << "Habilitacoes: " << i.getHabilitacoes() << endl;

        vector<string> interesses = i.getInteresses();

        cout << "Interesses: ";
        for(auto j : interesses) {
            cout << j << " ";
        }
        cout << "\n\n";
    }

    cout << "\tESCOLAS\n\n";

    for(auto i : escolas) {
        cout << i.getId() << endl;
        cout << "Habilitacoes: " << i.getHabilitacoes() << endl;
        cout << "Vagas: " << i.getVagas() << "\n\n";
    }

    return 0;
}