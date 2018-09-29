#include "bits/stdc++.h"

#include "estrutura.hpp"

#define KARATE "karate.gml"


//*******************************************************Metodos da classe Vertice***************************************************
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

void Vertice::set_adjascente(Vertice &vertice){

    this->adjascentes.push_back(vertice);

}


void Vertice::AdicionaAdj(Vertice &vertice) {

    this->adjascentes.push_back(vertice);

}

void Vertice::set_visitado(bool visitado) {

    this->visitado = visitado;

}

bool Vertice::get_visitado() {

    return this->visitado;

}

//*******************************************************Metodos da classe Grafo***************************************************

vector<Vertice> Grafo::get_vertices() {

    return this->vertices;

}

vector<vector<Vertice>> Grafo::get_cliques() {

    return this->cliquesMaximais;

}

void Grafo::adicionaVertice(Vertice &vertice){

this->vertices.push_back(vertice);

}

void Grafo::criaLigacao(int a, int b) {

    Vertice verticeA;
    Vertice verticeB;

    verticeA.set_id(a);
    verticeB.set_id(b);

    bool aAdc = true;
    bool bAdc = true;

    for(int i = 0; i < this->vertices.size(); i++) {

        if(this->vertices[i].get_id() == a) {
            this->vertices[i].set_adjascente(verticeB);
            aAdc = false;
        }

        if(this->vertices[i].get_id() == b) {
            this->vertices[i].set_adjascente(verticeA);
            bAdc = false;
        }
    }

    if(aAdc){
        verticeA.set_adjascente(verticeB);
        this->adicionaVertice(verticeA);
    }

    if(bAdc) {
        verticeB.set_adjascente(verticeA);
        this->adicionaVertice(verticeB);
    }

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

            this->criaLigacao(a, b);
        }
    }
    return true;
}

vector<Vertice> Grafo::intersecao(vector<Vertice> candidatos, vector<Vertice> adjascentes) {

    vector<Vertice> intersecao;

    for(auto verticeCan : candidatos) {
        for(auto verticeAdj : adjascentes) {
            if(verticeCan.get_id() == verticeAdj.get_id()) {
                intersecao.push_back(verticeCan);
            }
        }
    }

    return intersecao;

}

vector<Vertice> Grafo::retiraVertice(vector<Vertice> vertices, Vertice vertice) {

    int pos = -1;

    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i].get_id() == vertice.get_id()) {
            pos = i;
        }
    }

    if(pos > -1) {

        vertices.erase(vertices.begin() + pos);
        return vertices;

    }

    cout << "Vertice nao encontrado" << endl;
    return vertices;

}


void Grafo::bron_kerbosh(vector<Vertice> pertencentes,
                         vector<Vertice> candidatos,
                         vector<Vertice> analisados) {

    vector<Vertice> pertencentesRecur;
    vector<Vertice> candidatosRecur;
    vector<Vertice> analisadosRecur;


    if(candidatos.empty() && analisados.empty()) {
        //Temos um clique, que seria o pertencentes
        cliquesMaximais.push_back(pertencentes);
        /*cout << "Estive Aqui";
        cout << "clique: " << endl;
        for(auto vertice : pertencentes) {
            cout << vertice.get_id() << " ";
        }
        cout << "aaaaaaaaaaa" << endl; */
    }

    for(auto vertice : candidatos) {

        pertencentesRecur = pertencentes;
        pertencentesRecur.push_back(vertice); //Adicionado toda vez que bron eh chamada
        candidatosRecur = this->intersecao(candidatos, vertice.get_adjascentes());
        analisadosRecur = this->intersecao(analisados, vertice.get_adjascentes());
        this->bron_kerbosh(pertencentesRecur, candidatosRecur, analisadosRecur);
        /*for(auto vertice : pertencentes) {
            cout << vertice.get_id() << " ";
        }
        cout << "bbbbbbbbbbb" << endl; */
        analisados.push_back(vertice);
        //candidatos = this->retiraVertice(candidatos, vertice);

        }

}
