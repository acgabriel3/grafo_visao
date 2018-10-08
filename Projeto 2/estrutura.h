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
        bool visitado;

        vector<Vertice*> adjascentes;
        vector<Vertice*> requisitos;
        Vertice* antecedente;
        int pesoCritico;

    public:

        Vertice() {
            this->visitado = false;
        }
        Vertice(string nome, int creditos, int dificuldade) {
            this->set_nome(nome);
            this->set_creditos(creditos);
            this->set_dificuldade(dificuldade);
            this->visitado = false;
        }

        void set_nome(string);
        void set_creditos(int);
        void set_dificuldade(int);
        void set_visitado();
        void set_pesoCritico(int);
        void set_antecedente(Vertice&);

        string get_nome();
        int get_creditos();
        int get_dificuldade();
        bool get_visitado();
        int get_peso();
        int get_pesoCritico();

        void set_adjascente(Vertice&);
        vector<Vertice*> get_adjascentes();

        void set_requisito(Vertice&);
        vector<Vertice*> get_requisitos();

        int grau_entrada();
        int grau_saida();
};

/**
 * @brief Representa um grafo, como tambem eh responsavel por medidas aplicadas no contexto macro de um grafo.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a um grafo e seus subconjuntos.
 */
class Grafo {

    private:

        vector<Vertice> vertices;
        vector<Vertice> ordem_topologica;

    public:

        void set_vertices(string);
        vector<Vertice> get_vertices();

        void adiciona_vertice(Vertice&);
        vector<Vertice> retira_vertice(Vertice&);

        void set_arestas(string);
        void cria_aresta(string, string);

        // void kahns();
        vector<Vertice> ordenacao_topologica();
        void ordenacao_topologica_aux(Vertice&, map<string, bool>&, stack<Vertice>&);

        //adjascentes deve comecar recebendo a ordem topologica
        void caminho_critico(int chave, vector<Vertice> adjascentes); //Depois percorrer a DAG de tras pra frente e procurar o maior pesoCritico
                                                            //Entao montar o caminho por meio dos antecedentes a este vertice.

};

#endif
