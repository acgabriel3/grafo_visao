#include "../include/grafo.h"

int main() {

    cout << "oieeeeee" << endl;

    Grafo grafo = Grafo();

    if(!grafo.leitura()) {
        cout << "Falha ao abrir o arquivo" << endl;
        return 0;
    }

    cout << "olaaaaaa";

    cout << "tamanho" << grafo.get_vertices().size() << endl;

    grafo.show();

    return 0;
}
