#include "grafo.cpp"

using namespace std;

int main() {

    Grafo grafo;
    grafo.setProfessores();
    grafo.setEscolas();
    grafo.calculaEmparelhamentoEstavel();

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
        vector<int> habilitacoes = i.getHabilitacoes();
        cout << "Habilitacoes: " ;
        for(auto habilitacao : habilitacoes) {
            cout << habilitacao << " ";
        }
        cout << endl;
        cout << "Vagas: " << i.getVagas() << "\n\n";
    }

    cout << "\tEMPARELHAMENTOS\n\n";

    for(auto i : professores) {
        cout << i.getId() << " emparelhado com: " << i.get_emparelhamento().getId() << endl;
    }

    return 0;
}
