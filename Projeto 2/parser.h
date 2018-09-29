#ifndef PARSER_H
#define PARSER_H

/**
 * @file parser.h
 * @author Thiago Santos Matos
 * @author Gabriel Alves Castro
 * @date 29 de setembro de 2018
 *
 * @brief Descrição das funções e variáveis responáveis por ler e armazenar os dados do arquivo fluxo.txt
 *
 */

#include "bits/stdc++.h"
#include "estrutura.h"

/**
 * @brief Define o nome do arquivo onde estão os dados que serão recebidos
 * 
 */
#define KARATE "fluxo.txt"
/**
 * @brief Define a quantidade de disciplinas do fluxo, representadas por vértices no grafo
 * 
 */
#define DISCIPLINAS 34

using namespace std;

/**
 * @brief Objeto da classe grafo que será utilizado para representar as relações entre os membros do grupo de karate.
 * 
 * Objeto inicializado com a quantidade de vértices correspondentes ao número de integrantes do grupo de karate.
 */
Graph graph(INTEGRANTES);

/**
 * @brief Lê os dados presentes no arquivo karate.gml e armazena as relações entre os integrantes do clube de karate no objeto da classe grafo instânciado.
 * 
 * @return true se foi possível ler e armazenar os dados presentes no arquivo karate.gml
 * @return false se não foi possível abrir o arquivo karate.gml
 */
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