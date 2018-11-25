#ifndef PARSER_H
#define PARSER_H

#include "grafo.h"

using namespace std;

Grafo grafo(1005);

bool read() {
    fstream file;
    file.open("email-Eu-core.txt");

    if(!file) {
        return false;
    }

    string line;

    while(file >> line) {
        int a = stof(line);

        file >> line;
        int b = stof(line);

        grafo.make_path(a, b);
    }

    return true;
}

#endif