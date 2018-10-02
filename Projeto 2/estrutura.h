#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "bits/stdc++.h"

using namespace std;

/**
 * @brief Representa o vertice de um grafo, como tambem todos os vertices adjascentes a este.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a somente um vertice.
 */
class Vertice {

    private:

        string nome;
        int creditos;
        int dificuldade;

        vector<Vertice> adjascentes;

    public:

        Vertice() {}
        Vertice(string nome, int creditos, int dificuldade) {
            this->set_nome(nome);
            this->set_creditos(creditos);
            this->set_dificuldade(dificuldade);
        }

        void set_nome(string);
        void set_creditos(int);
        void set_dificuldade(int);
        string get_nome();
        int get_creditos();
        int get_dificuldade();

        void set_adjascente(Vertice&);
        vector<Vertice> get_adjascentes();

        int calculaGrau();
};

/**
 * @brief Representa um grafo, como tambem eh responsavel por medidas aplicadas no contexto macro de um grafo.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a um grafo e seus subconjuntos.
 */
class Grafo {

    private:

        vector<Vertice> vertices;
        vector<Vertice> ordemTopologica;

    public:

        void set_vertices(string);
        vector<Vertice> get_vertices();

        void adiciona_vertice(Vertice&);
        vector<Vertice> retira_vertice(Vertice&);

        void set_arestas(string);
        void cria_aresta(string, string);

        void kahns();

};

#endif
