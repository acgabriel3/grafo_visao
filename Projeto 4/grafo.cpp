#include "grafo.h"


Grafo::achaPosicao(int id) {

    int pos = -1;

    for(int i = 0; i < this->vertices.size(); i++) {
        if(this->vertices.get_id() == id) {
            pos = i;
        }
    }

    return pos;

}

Grafo::arestaDirecionada(int a, int b) {

    int pos = this->achaPosicao(a);
    int posAdj = this->achaPosicao(b);

    Vertice vertice;
    Vertice adjascente;

    if(pos == -1) {

        vertice.set_id(a);

        if(posAdj == -1) {

            adjascente.set_id(b);
            vertice.set_adjascente(adjascente);
            this->set_vertice(vertice);
            this->set_vertice(adjascente);

        } else {

            vertice.set_adjascente(this->vertices[posAdj]);
            this->set_vertice(vertice);

        }

    } else {


        if(posAdj == -1) {

            adjascente.set_id(b);
            this->set_vertice(adjascente);
            this->vertices[pos].set_adjascente(adjascente);

        } else {

            this->vertices[pos].set_adjascente(this->vertices[posAdj]);

        }
    }

}
