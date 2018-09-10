#ifndef GRAPH_H
#define GRAPH_H

#include "bits/stdc++.h"

using namespace std;

class Graph {

    private:

        vector<vector<int>> graph;
        vector<vector<int>> cliques;

        static bool cmp(vector<int> a, vector<int> b) {
            return a.size() > b.size();
        }
        void bron_kerbosh(vector<int> r, vector<int> p, vector<int> x) {
            if(p.empty() && x.empty()) {
                cliques.push_back(r);
            }

            vector<bool> mark_p(graph.size() + 1, false),
                         mark_x(graph.size() + 1, false);

            for(int i = 0; i < p.size(); i++) {
                mark_p[p[i]] = true;
            }
            for(int i = 0; i < x.size(); i++) {
                mark_x[x[i]] = true;
            }

            for(int i = 0; i < p.size(); i++) {
                vector<int> p_next, x_next;

                r.push_back(p[i]);

                for(int j = 0; j < graph[p[i]].size(); j++) {
                    if(mark_p[graph[p[i]][j]]) {
                        p_next.push_back(graph[p[i]][j]);
                    }
                    if(mark_x[graph[p[i]][j]]) {
                        x_next.push_back(graph[p[i]][j]);
                    }
                }

                bron_kerbosh(r, p_next, x_next);

                r.pop_back();

                mark_p[p[i]] = false;
                mark_x[p[i]] = true;
            }
        }

    public:

        Graph() {}
        Graph(int n) : graph(n + 1) {}

        int size() {
            return graph.size();
        }
        void make_path(int a, int b) {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool has_path(int a, int b) {
            return find(graph[a].begin(), graph[a].end(), b) != graph[a].end();
        }
        int degree(int v) {
            return graph[v].size();
        }
        void show_vertices() {
            cout << "\n\tVERTICES\n\n";

            for(int i = 1; i < graph.size(); i++) {
                cout << "Vertice: " << i << "\tGrau: " << degree(i) << endl;
            }
        }
        void show_cliques() {
            cout << "\n\tCLIQUES\n\n";

            if(cliques.empty()) {
                vector<int> r, p, x;

                for(int i = 1; i < graph.size(); i++) {
                    p.push_back(i);
                }

                bron_kerbosh(r, p, x);
            }

            sort(cliques.begin(), cliques.end(), cmp);

            for(int i = 0; i < cliques.size(); i++) {
                for(int j = 0; j < cliques[i].size(); j++) {
                    cout << cliques[i][j] << " ";
                }
                cout << endl;
            }
        }

        long double coefVertice(int vertice) {

            vector<vector<int>> triangulos;

            for(auto clique : cliques) {

                if(clique.size() == 3) {

                    triangulos.push_back(clique);

                }

            }

            int arestasTrian = 0;
            long double coefVertice = -1;

            for(auto triangulo : triangulos) {

                    for(int i = 0; i < triangulo.size(); i++) {
                            if(triangulo[i] == vertice) {
                                arestasTrian++;
                            }
                    }
            }


            if(graph[vertice].size() == 1) {

                coefVertice = 0;

            } else {

                coefVertice = (2.0f* (long double) arestasTrian);
                coefVertice = coefVertice/((long double) graph[vertice].size());
                coefVertice = coefVertice/( (long double) graph[vertice].size() - 1.0f);

            }

            return coefVertice;

        }

        void coefGrafo() {

            long double coefGrafo = 0;
            long double aux = 0;

            for(int i = 1; i < graph.size(); i++) {
                 aux = this->coefVertice(i);
                 cout << "coeficiente aglomeracao vertice " << i << ":" << aux << endl;
                 coefGrafo += aux;
            }

            coefGrafo = coefGrafo/graph.size();

            cout << "coeficiente aglomeracao grafo: " << coefGrafo << endl;
        }
};

#endif
