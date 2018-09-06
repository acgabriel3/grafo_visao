#include <estrutura.hpp>

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


vector<Vertice*> Vertice::get_adjascentes() {

    return this->adjascentes;

}


void Vertice::AdicionaAdj(Vertice* vertice) {

    this->adjascentes.push_back(vertice);

}
