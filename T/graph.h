#ifndef GRAPH_H
#define GRAPH_H

#include "bits/stdc++.h"

using namespace std;

class Graph {

    private:

        vector<vector<int>> graph;

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
        void show() {
            for(int i = 1; i < graph.size(); i++) {
                cout << "Vertice: " << i << "\tGrau: " << degree(i) << endl;
            }
        }
};

#endif