#include "bits/stdc++.h"
#include "graph.h"
#include "parser.h"

using namespace std;

int main() {

    if(!read()) {
        cout << "Falha ao ler arquivo" << endl;
        return 0;
    }

    graph.show_vertices();
    graph.show_cliques();
    graph.coefGraph();

    return 0;
}
