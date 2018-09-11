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

int Graph::fatorial(int n) {

    int result = n;

    for(int i = n - 1; i > 0; i--){
        result = result * i;
    }

    return result;
}

int Graph::trianglesInClique(int cliqueSize) {

    int n = cliqueSize - 1;
    int nFatorial = this->fatorial(n);
    int twoFatorial = 2;
    int nLessTwoFatorial = this->fatorial(n - 2);
    int result = (nFatorial/(twoFatorial * nLessTwoFatorial));

    return result;

}

long double Graph::coefVertex(int vertex) {

    /* vector<vector<int>> cliquesMax;

            for(auto clique : cliques) {

                if(clique.size() > 2) {

                    cliquesMax.push_back(clique);

                }

            }

            int triangles = 0;
            bool vertexInClique = false;
            long double coefVertex = -1;
            int sizeClique = 0;

            for(auto clique : cliquesMax) {

                    sizeClique = clique.size();

                    for(int i = 0; i < sizeClique; i++) {
                            if(clique[i] == vertex) {
                                vertexInClique = true;
                            }
                    }

                    if(sizeClique == 3 && vertexInClique) {
                        triangles++;
                    } else if(sizeClique > 3 && vertexInClique) {
                        int trianglesInClique = this->trianglesInClique(sizeClique);
                        triangles = triangles + trianglesInClique;
                    }

                    vertexInClique = false;
            }


            if(graph[vertex].size() == 1) {

                coefVertex = 0;

            } else {

                coefVertex = (2.0f* (long double) triangles);
                coefVertex = coefVertex/((long double) graph[vertex].size());
                coefVertex = coefVertex/( (long double) graph[vertex].size() - 1.0f);

            }

            return coefVertex;

            */

    int triangles = 0;

   vector<int> adjascentes = graph[vertex];

   vector<int> adjPosterior;

   for(int i = 0; i < adjascentes.size(); i++) {

        for(int j = i + 1; j < adjascentes.size(); j++) {
            adjPosterior = graph[adjascentes[j]];
                for(auto vertexAdj : adjPosterior) {
                    if(adjascentes[i] == vertexAdj) {
                        triangles++;
                    }
                }
        }

   }

    long double coefVertex = 0;

    if(graph[vertex].size() == 1) {

        coefVertex = 0;

    } else {

        coefVertex = (2.0f* (long double) triangles);
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

            coefGraph = coefGraph/(graph.size() - 1);

            cout << "coeficiente medio de aglomeracao do grafo: " << coefGraph << endl;

}
