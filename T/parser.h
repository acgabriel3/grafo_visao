#ifndef PARSER_H
#define PARSER_H

#include "bits/stdc++.h"
#include "graph.h"

#define KARATE "karate.gml"
#define INTEGRANTES 34

using namespace std;

Graph graph(INTEGRANTES);

bool read() {
    fstream file;
    file.open(KARATE);

    if(!file) {
        cout << "Falha ao abrir arquivo" << endl;
        return false;
    }

    string line, source, target;

    while(file >> line) {
        if(line == "edge") {
            while(file >> line && line != "source");
            file >> source;
            int a = stof(source);

            while(file >> line && line != "target");
            file >> target;
            int b = stof(target);

            graph.make_path(a, b);
        }
    }
    return true;
}

#endif