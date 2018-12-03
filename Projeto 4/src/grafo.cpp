#include "../include/grafo.h"


// é inutil agora
int Grafo::achaPosicao(int id) {

    int pos = -1;

    for(int i = 0; i < this->vertices.size(); i++) {
        if(this->vertices[i].get_id() == id) {
            pos = i;
        }
    }

    return pos;

}


// mexi aqui nessa função e mudei pro find
void Grafo::arestaDirecionada(Vertice& origem, Vertice& destino) {
    if (find(this->vertices.begin(), this->vertices.end(), origem) == this->vertices.end()) {
        this->vertices.push_back(origem);
    }
    if (find(this->vertices.begin(), this->vertices.end(), destino) == this->vertices.end()) {
        this->vertices.push_back(destino);
    }

    vertices[find(this->vertices.begin(), this->vertices.end(), origem) - this->vertices.begin()].set_adjascente(destino);
}


void Grafo::show() {

    for(int i = 0; i < this->vertices.size(); i++) {

        cout << "[" << this->vertices[i].get_id() << "]: ";

        for(int j = 0; j < this->vertices[i].get_adjascentes().size(); j++) {
            cout << this->vertices[i].get_adjascentes()[j].get_id() << " ";
        }

        cout << endl;
    }

}

// agora vc ja manda o vertice construido pro grafo
bool Grafo::leitura() {

    fstream file;
    file.open("email-Eu-core.txt");

    if(!file.is_open()) {
        return false;
    }

    string line;
    int lin = 1;
    while (getline(file, line)) {
        if (line.find("//") != string::npos) {
            continue;
        } else {
            cout << "linha: " << lin << "\n";
            int src, dest;
            stringstream formated(line);
            formated >> src >> dest;
            // cout << src << " " << dest << "\n";
            // cout << src << "\n";

            Vertice origem = Vertice();
            origem.set_id(src);
            Vertice destino = Vertice();
            destino.set_id(dest);
            this->arestaDirecionada(origem, destino);
            ++lin;
        }
    }

    return true;
}

int Grafo::computaEIJ(Comunidade comunidadeA, Comunidade comunidadeB) {

    if(this->totalArestas == 0) {
      this->calculaTotalArestas();
    }

    for(auto verticeA : comunidadeA.get_vertices()) {

    }

}









































































