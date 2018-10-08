#include "estrutura.h"

using namespace std;

int main() {

    Grafo grafo;
    grafo.set_vertices("fluxo.txt");

    cout << "\tGRAFO\n\n";

    vector<Vertice> vertices = grafo.get_vertices();

    for(auto i : vertices) {
        cout << i.get_nome() << " [";
        cout << "creditos " << i.get_creditos() << " ";
        cout << "dificuldade " << i.get_dificuldade() << "]:";

        vector<Vertice*> adjascentes = i.get_adjascentes();

        for(auto j : adjascentes) {
            cout << " " << j->get_nome() << " ";
            cout << "[peso " << j->get_peso() << "];";
        }

        cout << endl;
    }

    cout << "\n\tORDENACAO TOPOLOGICA\n\n";

    vector<Vertice> ordem_topologica = grafo.ordenacao_topologica();

    for(auto i : ordem_topologica) {
        cout << i.get_nome() << endl;
    }

    cout << "\n\tCAMINHO CRITICO\n\n";

    pair<vector<Vertice>, int> caminho_critico = grafo.caminho_critico();

    for(auto i : caminho_critico.first) {
        cout << i.get_nome() << endl;
    }
    cout << "\tPeso Total do Caminho Critico = " << caminho_critico.second << endl;

    return 0;
}
