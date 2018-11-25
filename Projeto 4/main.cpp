#include "parser.h"

using namespace std;

int main() {

    if(!read()) {
        cout << "Falha ao abrir o arquivo" << endl;
        return 0;
    }

    grafo.show();

    return 0;
}