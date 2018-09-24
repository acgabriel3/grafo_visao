#ifndef GRAPH_H
#define GRAPH_H

#include "bits/stdc++.h"

using namespace std;

/**
 * @file graph.h
 * @author Thiago Santos Matos
 * @author Gabriel Alves Castro
 * @date 09 de setembro de 2018
 *
 * @brief Descricao acerca da classe Graph, acerca de sua estrutura e m�todos.
 *
 * A classe Graph eh o menor n�vel de abstracao abordado nesse projeto. A sua funcionalidade eh representar
 * um grafo no sentido da abstracao matematica de "grafos", por meio de uma lista de adjacencia. Deste modo,
 * todos os seus metodos referem-se a implementacao das medidas disponiveis na literatura de grafos. Sendo que
 * nessa versao 1.0 existem apenas algumas medidas implementadas.
 *
 */

 /**
 * @brief classe abstrata com o intuito de representar um grafo por meio de uma lista de adjacencia
 *
 * A classe possui o metodo bron_kerbosh, que eh uma implementacao deste algoritmo conhecido para encontrar cliques maximais
 * A classe possui o metodo has_path, que indica se ha caminho entre dois vertices
 * A classe possui o metodo degree, que indica o grau de um vertice
 * A classe possui o metodo show_vertices, que printa no prompt os vertices presentes no grafo e seu grau
 * A classe possui o metodo show_cliques, que printa no prompt os cliques maximais do vertice
 * A classe possui o metodo coefVertex, que calcula o coeficiente de aglomeracao de um determinado vertice
 * A classe possui o metodo coefGraph, que calcula o coeficiente de aglomeracao de cada vertice, os imprime no prompt, e calcula e imprime o coeficiente de aglomeracao medio do grafo
 *
 */


class Graph {

    private:

        vector<vector<int>> graph;
        vector<vector<int>> cliques;

        static bool cmp(vector<int> a, vector<int> b) {
            return a.size() > b.size();
        };

        int size() {
            return graph.size();
        }

    public:

        Graph() {}
        Graph(int n) : graph(n + 1) {}

        /**
     * @brief Implementa o algoritmo conhecido bron_kerbosh, para encontrar cliques maximais
     *
     * utiliza-se de dois vetores de booleanos para realizar a marcacao dos vertices.
     *
     * @param r sao os vertices pertencentes ao clique (ou o ponto de partida)
     * @param p sao os vertices candidatos a pertencerem ao clique maximal
     * @param x sao os vertices que nao podem pertencer ao clique maximal
     */

        void bron_kerbosh(vector<int> r, vector<int> p, vector<int> x);

    /**
     * @brief Armazena uma aresta na memoria, quando da leitura de parser

     * @param a eh o id de um dos vertices
     * @param b eh o id de um dos vertices
     */
        void make_path(int a, int b) {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

    /**
     * @brief Indica se ha um caminho entre dois vertices
     *
     * @param a eh o id de um dos vertices
     * @param b eh o id de um dos vertices
     */
        bool has_path(int a, int b) {
            return find(graph[a].begin(), graph[a].end(), b) != graph[a].end();
        }
    /**
     * @brief Calcula o grau de um vertice.

     * @param v eh o id do vertice
     */
        int degree(int v) {
            return graph[v].size();
        }

    /**
     * @brief Mostra os vertices presentes no grafo
     */
        void show_vertices() {
            cout << "\n\tVERTICES\n\n";

            for(int i = 1; i < graph.size(); i++) {
                cout << "Vertice: " << i << "\tGrau: " << degree(i) << endl;
            }
        }

        /**
     * @brief Calcula e imprime os cliques maximais do grafo
     */
        void show_cliques();

        /**
     * @brief Calcula o coeficiente de aglomeracao de um vertice
     * A formula eh: (2*t/(n*n-1))
     * @param v e o indice do vertice
     */
        long double coefVertex(int vertex);

        /**
     * @brief Calcula o coeficiente de aglomeracao de cada vertice e imprime. Calcula o coeficiente de aglomeracao medio do grafo e imprime
     * O coeficiente de aglomeracao medio eh a media dos coeficientes de aglomeracao de cada vertice
     * Este metodo utiliza o metodo "coefVertex" em sua implementacao
     */
        void coefGraph();

        int fatorial(int n);
        int trianglesInClique(int sizeClique);
};

#endif
