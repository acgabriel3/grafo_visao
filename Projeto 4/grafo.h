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

        int get_id() {
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


};

class Grafo {

    private:

        vector<Vertice> vertices;

    public:

        Grafo() {}

        void set_grafo(vector<Vertice> vertices) {
            this->vertices = vertices;
        }

        vector<Vertice> get_vertices() {
            return this->vertices;
        }

        void set_vertice(Vertice vertice) {
            this->vertices.push_back(vertice);
        }

        int achaPosicao(int id);

        void arestaDirecionada(int a, int b);

       /* void show() {
            for(int i = 0; i < grafo.size(); i++) {
                cout << "[" << i << "]: ";
                for(int j = 0; j < grafo[i].size(); j++) {
                    cout << grafo[i][j] << " ";
                }
                cout << endl;
            }
        }*/
};

#endif
