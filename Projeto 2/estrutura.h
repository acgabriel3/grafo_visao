#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "bits/stdc++.h"

using namespace std;

/**
 * @file estrutura.h
 * @author Thiago Santos Matos - 170063666
 * @author Gabriel Alves Castro - 170033813
 * @date 07 de outubro de 2018
 *
 * @brief Descricao acerca do aquivo estrutura, que possui todas as estruturas necessarias para montar um grafo.
 *
 * As estrutura presentes aqui, foram construidas com o objetivo de construir grafos que representem os fluxos
 * dos cursos da universidade de Brasilia. Podendo ser uteis no auxilio ao planejamento dos curriculos dos alunos
 * dessa universidade.
 */


/**
 * @brief Representa o vertice de um grafo, como tambem todos os vertices adjascentes a este.
 *
 * A classe Vertice eh o mais baixo nivel de abstracao deste projeto, representa um Vertice no seu conceito matematico
 * da teoria dos grafos, sendo responsavel por administrar funcionalidades referentes a este nivel.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a somente um vertice.
 *
 */
class Vertice {

    private:

        string nome;
        int creditos;
        int dificuldade;
        bool visitado;

        vector<Vertice*> adjascentes;
        vector<Vertice*> requisitos;
        Vertice* antecedente;
        int pesoCritico;

    public:

        Vertice() {
            this->visitado = false;
        }
        Vertice(string nome, int creditos, int dificuldade) {
            this->set_nome(nome);
            this->set_creditos(creditos);
            this->set_dificuldade(dificuldade);
            this->visitado = false;
        }

    /**
     * @brief metodo set para o nome do Vertice
     *
     * @param r recebe um nome para ser dado ao vertice
     */
        void set_nome(string);
    /**
     * @brief metodo set para os creditos (referente a carga horaria de uma disciplina da unb)
     *
     * @param recebe um valor inteiro que indica os creditos referentes a disciplina
     */
        void set_creditos(int);
    /**
     * @brief metodo set para a dificuldade
     *
     * @param recebe um valor inteiro que indica uma valoracao pessoal acerca de uma estimativa da dificuldade de uma disciplina do curriculo
     */
        void set_dificuldade(int);
    /**
     * @brief metodo set para visitado
     *
     * este metodo serve de auxilio as buscas no grafo
     *
     */
        void set_visitado();
    /**
     * @brief metodo set para o pesoCritico
     *
     * @param adminsitra o valor da variavel auxiliar de Vertice reservada para indicar o maior peso de chegada ate um dado Vertice
     */
        void set_pesoCritico(int);
    /**
     * @brief metodo set para antecedente
     *
     * @param recebe um vertice anterior ao vertice atual em um DAG, serve como auxiliar para diversas funcoes
     *
     * Obs: Nesta biblioteca existem duas aplicacoes da ordenacao topologica, esta funcao seria utilizada na segunda, no entanto a mesmo nao
     * foi completada ainda, e por este motivo se encontra comentada
     */
        void set_antecedente(Vertice&);

    /**
     * @brief metodo get para nome
     */
        string get_nome();
    /**
     * @brief metodo get para creditos
     */
        int get_creditos();
    /**
     * @brief metodo get para dificuldade
     *
     * A dificuldade em um vertice
     */
        int get_dificuldade();
    /**
     * @brief metodo get para visitado
     */
        bool get_visitado();
    /**
     * @brief metodo get para peso
     *
     * O peso eh definido como a dificuldade vezes os creditos
     */
        int get_peso();
    /**
     * @brief metodo get para pesoCritico
     */
        int get_pesoCritico();

    /**
     * @brief metodo set para adicionar um vertice a lista de adjacencia do vertice atual
     *
     * @param recebe o ponteiro para um vertice a ser colocado na lista de adjacencia do vertice que chama a funcao
     */
        void set_adjascente(Vertice&);
    /**
     * @brief metodo get para lista de vertices adjascentes ao vertice atual
     */
        vector<Vertice*> get_adjascentes();
    /**
     * @brief metodo set para requisito
     *
     * @param recebe um vertice de uma materia que eh pre-requisito a outra
     */
        void set_requisito(Vertice&);
    /**
     * @brief metodo get para requisitos
     *
     * Retorna uma lista de todas as materias que sao pre-requisito para a materia representada no vertice atual
     */
        vector<Vertice*> get_requisitos();
    /**
     * @brief retorna a quantidade de vertices para os quais o vertice atual aponta
     */
        int grau_entrada();
    /**
     * @brief retorna a quantidade de vertices que o vertice atual recebe
     */
        int grau_saida();
};

/**
 * @brief Representa um grafo, como tambem eh responsavel por medidas aplicadas no contexto macro de um grafo.
 *
 * A classe Graph possui a funcionalidade de representar um grafo no sentido da abstracao matematica de "grafos",
 * por meio de uma lista de Vertices, tambem representados por uma classe. Deste modo,
 * todos os seus metodos referem-se a implementacao das medidas disponiveis na literatura de grafos. Sendo que
 * nessa versao 1.0 existem apenas algumas medidas implementadas.
 *
 * obs: Quando fala-se que uma funcao recebe um ponteiro para o vertice, quer-se dizer que ao passar um objeto da classe Vertice
 * para a funcao, o mesmo sera referenciado como um ponteiro.
 */
class Grafo {

    private:

        vector<Vertice> vertices;
        vector<Vertice> ordem_topologica;
        vector<Vertice> caminho;
        vector<pair<vector<Vertice>, int>> caminhos;

    public:

        /**
        * @brief metodo set que auxiliar na leitura dos Vertices de um arquivo parser
        *
        * @param recebe um string com o nome do vertice lido no parser
        */

        void set_vertices(string);
        /**
        * @brief metodo get que retorna os vertices do grafo
        */
        vector<Vertice> get_vertices();

        /**
        * @brief metodo set que adiciona um vertice a lista de vertices do grafo
        *
        * @param recebe um ponteiro para o vertice que sera adicionado a lista de vertices do grafo
        */

        void adiciona_vertice(Vertice&);

        /**
        * @brief retira um vertice do grafo
        *
        * @param recebe um ponteiro para o vertice que sera retirado da lista de vertices do grafo
        */

        vector<Vertice> retira_vertice(Vertice&);

        /**
        * @brief metodo set que adiciona uma aresta ao grafo
        *
        * @param recebe string que denomina a aresta
        */

        void set_arestas(string);

        /**
        * @brief metodo set que cria uma aresta
        *
        * @param recebe duas strings referentes ao vertices que fazem parte do grafo
        */
        void cria_aresta(string, string);

        /**
        * @brief Algoritmo conhecido Kahns, utilizado para criar um ordenacao do grafo
        *
        * Este algoritmo ainda nao foi totalmente implementado nesta estrutura, por esse motivo nao esta ativo(esta comentado)
        */
        void kahns();

        /**
        * @brief metodo para realizar uma ordenacao topologica em uma dag
        *
        * O metodo implementado utiliza-se de busca em profundidade para realizar uma ordenacao topologica em uma DAG
        * referente aos fluxos de disciplinas da Universidade de Brasilia.
        *
        * obs: O algortimo kahns realiza a mesma responsabilidade, no entanto ainda nao foi completamente implementado
        *
        */
        vector<Vertice> ordenacao_topologica();
        /**
        * @brief metodo qcriado para modularizar a ordenacao topologica, facilitando a programacao dos programadores
        *
        * @param recebe um ponteiro para o vertice
        * @param recebe um map, contituido por uma string e um bool. sendo que na realidade sera transformado um map de ponteiros
        * @param
        *
        */
        void ordenacao_topologica_aux(Vertice&, map<string, bool>&, stack<Vertice>&);

        /**
        * @brief metodo auxiliar ao metodo de caminhos criticos
        *
        * @param recebe um Vertice que sera o ponto de partida da busca
        * @param recebe um map de strings e de int que na realidade sera transformado em um map de ponteiros (indica o peso do caminho critico e o nome do vertice)
        * @param recebe um map de string e um bool que na realidade sera transformado em um map de ponteiros
        *
        * Este metodo faz uma busca em profundidade recursiva, registrando os maiores caminhos a partir de um determinado vertice
        * de uma ordenacao topologica
        */
        void computa_caminhos(Vertice&, map<string, int>&, map<string, bool>&);
        /**
        * @brief metodo retorna o caminho critico de uma DAG
        *
        * O metodo utiliza-se de do metodo auxiliar computa_caminhos que realiza uma busca em profundidade recursiva em cada um
        * dos vertices de uma ordenacao topologica previamente realizada.
        *
        */
        pair<vector<Vertice>, int> caminho_critico();
};

#endif
