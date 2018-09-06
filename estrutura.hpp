//#ifndef ___ESTRUTURA_HPP__
#define ___ESTRUTURA_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

/**
 * @brief Representa o vertice de um grafo, como tambem todos os vertices adjascentes a este.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a somente um vertice.
 */

//OBS: TALVEZ NESTE TRABALHO NAO SEJA NECESSARIO EXCLUIR VERTICES, NEM MANIPULAR A ESTRUTURA DOS GRAFOS, MAS TALVEZ USEMOS ELE COMO BASE PARA OS PROXIMOS

//problemas dessa forma de representacao:
//- Teremos de adcionar de dois a dois nas listas de adjascencia de cada vertice, isso eh dificil gerenciar
class Vertice {

    private:

        string nome;
        int id;
        //Essa representacao eh a melhor? Pensar a respeito e pesquisar
        vector<Vertice*> adjascentes;

    public:

        //getters e setters
        string get_nome();
        void set_nome(string);

        int get_id();
        void set_id();

        vector<Vertice*> get_adjascentes();

        //metodos gerais
        int CoefAglomeracao(); //pergunta eh possivel calcular o coeficiente de aglomeracao apenas com os dados aqui presentes
        int Grau();
        void AdicionaAdj(Vertice vertice);

};

/**
 * @brief Representa um grafo, como tambem eh responsavel por medidas aplicadas no contexto macro de um grafo.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a um grafo e seus subconjuntos.
 */


//problemas dessa forma de representacao:
//- Ao excluir um vertice, deveremos excluir o mesmo de todas as listas de adjacencia que ele possui.
class Grafo {

    private:

        string nome;
        vector<Vertice*> vertices;

    public:

        //getters e setters
        string get_nome();
        void set_nome();

        vector<Vertice*> get_vertices();

        //getters e setters especificos
        void adcionaVertice(Vertice *vertice);
        void retiraVertice(Vertice *vertice);

        //metodos gerais
        int coefAglomeracaoMedio();
        void cliquesMaximais(); //pensar em valor de retorno e tambem em entrada, pois provavelmente vai sair em arquivo texto
        void grauGeralVertices(); //pensar em valor de retorno e tambem em entrada, pois provavelmente vai sair em arquivo texto
};
