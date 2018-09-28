#include "bits/stdc++.h"

#include "estrutura.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    Grafo grafoTeste;

    grafoTeste.leGml();

    vector<Vertice> vertices = grafoTeste.get_vertices();
    vector<Vertice> auxAdj;

    for(int i = 0; i < vertices.size(); i++) {
        cout << vertices[i].get_id() << " adjascentes: ";
        auxAdj = vertices[i].get_adjascentes();
        for(int j = 0; j < auxAdj.size(); j++) {
            cout << " " << auxAdj[j].get_id();
        }
        cout << endl;
    }

    vector a;
    vector b;

    grafoTeste.bron_kerbosh(grafoTeste.get_vertices(),a, b);

    for(auto clique : grafoTeste.get_cliques()) {
        for(auto vertice : clique) {
            cout << vertice.get_id() << " ";
        }
        cout << endl;
    }

    //imprimir cliques

    cout << "eh nois manolo" << endl;

    return 0;
}
