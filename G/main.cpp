#include "bits/stdc++.h"

#include "estrutura.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    Grafo grafoTeste;

    grafoTeste.leGml();

    vector<Vertice> vertices = grafoTeste.get_vertices();

    for(int i = 0; i < vertices.size(); i++) {
        cout << vertices[i].get_id() << endl;
    }

    cout << "eh nois manolo" << endl;

    return 0;
}
