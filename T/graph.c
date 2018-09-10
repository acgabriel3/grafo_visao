#include "graph.h"

void Graph::bron_kerbosh(vector<int> r, vector<int> p, vector<int> x) {
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

void Graph::show_cliques() {

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

long double Graph::coefVertex(int vertex) {

    vector<vector<int>> triangles;

            for(auto clique : cliques) {

                if(clique.size() == 3) {

                    triangles.push_back(clique);

                }

            }

            int edgesTrian = 0;
            long double coefVertex = -1;

            for(auto triangle : triangles) {

                    for(int i = 0; i < triangle.size(); i++) {
                            if(triangle[i] == vertex) {
                                edgesTrian++;
                            }
                    }
            }


            if(graph[vertex].size() == 1) {

                coefVertex = 0;

            } else {

                coefVertex = (2.0f* (long double) edgesTrian);
                coefVertex = coefVertex/((long double) graph[vertex].size());
                coefVertex = coefVertex/( (long double) graph[vertex].size() - 1.0f);

            }

            return coefVertex;

}

void Graph::coefGraph() {

    cout << "\n\tCoeficientes de aglomeracao\n\n";

     long double coefGraph = 0;
            long double aux = 0;

            for(int i = 1; i < graph.size(); i++) {
                 aux = this->coefVertex(i);
                 cout << "coeficiente de aglomeracao vertice " << i << ": " << aux << endl;
                 coefGraph += aux;
            }

            coefGraph = coefGraph/graph.size();

            cout << "coeficiente medio de aglomeracao do grafo: " << coefGraph << endl;

}
