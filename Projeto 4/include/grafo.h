#ifndef GRAFO_H
#define GRAFO_H

#include <bits/stdc++.h>

using namespace std;

class Vertice {

    private:

        string nome;
        int id;

        vector<Vertice> adjascenteDest;


    public:

        void set_id(int id) {
            this->id = id;
        }

        // aqui é frescura do find, mas tem q por o const no final
        int get_id() const {
            return this->id;
        }

        void set_nome(string nome) {
            this->nome = nome;
        }

        string get_nome() {
            return this->nome;
        }

        void set_adjascentes(vector<Vertice> adjascenteDest) {
            this->adjascenteDest = adjascenteDest;
        }

        vector<Vertice> get_adjascentes() {
            return this->adjascenteDest;
        }

        void set_adjascente(Vertice vertice) {
            this->adjascenteDest.push_back(vertice);
        }

        // adicionei os operadores pro vertice, para que o find funcione corretamente
        bool operator==(const Vertice& rhs) const {
            return this->id == rhs.get_id();
        }
        bool operator!=(const Vertice& rhs) const {
            return this->id != rhs.get_id();
        }
        bool operator>(const Vertice& rhs) const {
            return this->id > rhs.get_id();
        }
        bool operator<(const Vertice& rhs) const {
            return this->id < rhs.get_id();
        }
};

class Comunidade {

    private:

        vector<Vertice> vertices;

    public:

        vector<Vertice> get_vertices() {
            return this->vertices;
        }

        void set_vertices(vector<Vertice> vertices) {
            this->vertices = vertices;
        }

        void set_vertice(Vertice vertice) {
            this->vertices.push_back(vertice);
        }

        void uniaoComunidades(Comunidade comunidade);

};

class Grafo {

    private:

        vector<Vertice> vertices;
        vector<Comunidade> comunidades;

        int totalArestas = 0;

    public:

        Grafo() {}

        void set_vertices(vector<Vertice> vertices) {
            this->vertices = vertices;
        }

        vector<Vertice> get_vertices() {
            return this->vertices;
        }

        void set_vertice(Vertice vertice) {
            this->vertices.push_back(vertice);
        }

        void set_comunidades(vector<Comunidade> comunidades) {
            this->comunidades = comunidades;
        }

        vector<Comunidade> get_comunidades() {
            return this->comunidades;
        }

        void set_comunidade(Comunidade comunidade) {
            this->comunidades.push_back(comunidade);
        }

        int achaPosicao(int id);

        void arestaDirecionada(Vertice& a, Vertice& b);

        void show();

        bool leitura();

        int computaEIJ(Comunidade comunidadeA, Comunidade comunidadeB);


};

#endif
