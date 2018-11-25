#ifndef GRAFO_H
#define GRAFO_H

#include <bits/stdc++.h>

using namespace std;

class Grafo {

    private:

        vector<vector<int>> grafo; 

    public:

        Grafo() {}
        Grafo(int n) : grafo(n) {}

        void make_path(int a, int b) {
            if(!has_path(a, b)) {
                grafo[a].push_back(b);
            }
        }
        bool has_path(int a, int b) {
            return find(grafo[a].begin(), grafo[a].end(), b) != grafo[a].end();
        }

        void show() {
            for(int i = 0; i < grafo.size(); i++) {
                cout << "[" << i << "]: ";
                for(int j = 0; j < grafo[i].size(); j++) {
                    cout << grafo[i][j] << " ";
                }
                cout << endl;
            }
        }
};

#endif