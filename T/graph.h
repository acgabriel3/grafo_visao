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
        };
        void bron_kerbosh(vector<int> r, vector<int> p, vector<int> x);

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

        void show_cliques();
        long double coefVertex(int vertex);
        void coefGraph();
};

#endif
