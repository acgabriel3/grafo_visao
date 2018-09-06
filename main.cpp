#include "estrutura.hpp"

using namespace std;

int main(void) {

    Vertice verticeTeste;
    Vertice verticeTeste1;
    Vertice verticeTeste2;
    Vertice verticeTeste3;
    Vertice verticeTeste4;
    Grafo grafoTeste;

    string bla = "1";
    verticeTeste.set_nome(bla);
    verticeTeste1.set_nome(bla);
    verticeTeste2.set_nome(bla);
    verticeTeste3.set_nome(bla);
    verticeTeste4.set_nome(bla);

    verticeTeste.AdicionaAdj(verticeTeste1);
    verticeTeste.AdicionaAdj(verticeTeste2);
    verticeTeste.AdicionaAdj(verticeTeste3);
    verticeTeste.AdicionaAdj(verticeTeste4);

    vector<Vertice*> verticesAdj = verticeTeste.get_adjascentes();

    cout << verticesAdj[0]->get_nome() << endl;
    cout << verticesAdj[1]->get_nome() << endl;
    cout << verticesAdj[2]->get_nome() << endl;
    cout << verticesAdj[3]->get_nome() << endl;


    cout << "eh nois manolo" << endl;

    return 0;
}
