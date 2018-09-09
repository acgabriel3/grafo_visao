#include "bits/stdc++.h"

#include "estrutura.hpp"

#define KARATE "karate.gml"

string Vertice::get_nome() {

    return this->nome;

}


void Vertice::set_nome(string nome) {

    this->nome = nome;

}


int Vertice::get_id() {

    return this->id;

}

void Vertice::set_id(int id) {

    this->id = id;

}


vector<Vertice> Vertice::get_adjascentes() {

    return this->adjascentes;

}


void Vertice::AdicionaAdj(Vertice &vertice) {

    this->adjascentes.push_back(vertice);

}

bool Grafo::leGml () {
    fstream file;
    file.open(KARATE);

    if(!file) {
        cout << "Falha ao abrir arquivo" << endl;
        return false;
    }

    string line, source, target;

    while(file >> line) {
        if(line == "edge") {
            while(file >> line && line != "source");
            file >> source;
            int a = stof(source);

            while(file >> line && line != "target");
            file >> target;
            int b = stof(target);

            //graph.make_path(a, b);
        }
    }
    return true;
}
