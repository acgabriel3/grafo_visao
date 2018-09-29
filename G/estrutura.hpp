#ifndef ESTRUTURA_HPP
#define ESTRUTURA_HPP

#include "bits/stdc++.h"

using namespace std;

/**
 * @brief Representa o vertice de um grafo, como tambem todos os vertices adjascentes a este.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a somente um vertice.
 */

//OBS: TALVEZ NESTE TRABALHO NAO SEJA NECESSARIO EXCLUIR VERTICES, NEM MANIPULAR A ESTRUTURA DOS GRAFOS, MAS TALVEZ USEMOS ELE COMO BASE PARA OS PROXIMOS

//  Problemas dessa forma de representacao:
//- Teremos de adcionar de dois a dois nas listas de adjascencia de cada vertice, isso eh dificil gerenciar
class Vertice {

    private:

        string nome;
        int id;
        //Essa representacao eh a melhor? Pensar a respeito e pesquisar
        vector<Vertice> adjascentes;
        bool visitado = false;

    public:

        //getters e setters
        string get_nome();
        void set_nome(string);

        int get_id();
        void set_id(int);

        vector<Vertice> get_adjascentes();

        bool get_visitado();
        void set_visitado(bool);

        void set_adjascente(Vertice&);

        //metodos gerais
        int CoefAglomeracao(); //pergunta eh possivel calcular o coeficiente de aglomeracao apenas com os dados aqui presentes
        int Grau();
        void AdicionaAdj(Vertice&);

};

/**
 * @brief Representa um grafo, como tambem eh responsavel por medidas aplicadas no contexto macro de um grafo.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a um grafo e seus subconjuntos.
 */


//  Problemas dessa forma de representacao:
//- Ao excluir um vertice, deveremos excluir o mesmo de todas as listas de adjacencia que ele possui.
class Grafo {

    private:

        string nome;
        vector<Vertice> vertices;
        vector<vector<Vertice>> cliquesMaximais;

    public:

        //getters e setters
        string get_nome();
        void set_nome();

        vector<Vertice> get_vertices();
        vector<vector<Vertice>> get_cliques();

        //getters e setters especificos
        void adicionaVertice(Vertice&);
        void retiraVertice(Vertice&);

        //metodos de leitura:
        bool leGml();
        void criaLigacao(int a, int b);

        //metodos gerais
        void grauGeralVertices();
        int coefAglomeracaoMedio();
        void bron_kerbosh(vector<Vertice> pertencentes,
                          vector<Vertice> candidatos,
                          vector<Vertice> naoPertencentes);
        vector<Vertice> intersecao(vector<Vertice> candidatos, vector<Vertice> adjascentes);
        vector<Vertice> retiraVertice(vector<Vertice> vertices, Vertice vertice);

};

#endif // ESTRUTURA_HPP
