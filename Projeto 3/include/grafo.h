#ifndef GRAFO_H
#define GRAFO_H

#include <bits/stdc++.h>

using namespace std;

/**
 * @file grafo.h
 * @author Thiago Santos Matos - 170063666
 * @author Gabriel Alves Castro - 170033813
 * @date 05 de novembro de 2018
 *
 * @brief Descricao acerca do aquivo grafo, que possui todas as estruturas necessarias para montar o grafo.
 *
 * As estruturas presentes aqui foram desenvolvidas com o objetivo de construir um grafo bipartido e solucionar
 * o problema de emparelhamento estavel entre escolas e professores.
 */

class Professor;

/**
 * @brief Representa um vértice escola do grafo bipartido.
 *
 * A classe Escola representa um vertice sendo responsavel por administrar funcionalidades referentes a este nivel.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a uma escola.
 *
 */
class Escola {

    private:

        string id;
        vector<int> habilitacoes;
        int vagas;
        vector<Professor> professoresEmparelhados;

    public:

        Escola() {}
        Escola(string id, vector<int> habilitacoes, int vagas) {
            professoresEmparelhados.reserve(2);
            this->setId(id);
            this->setHabilitacoes(habilitacoes);
            this->setVagas(vagas);
        }

        /**
         * @brief Metodo set para o nome da Escola
         * 
         * @param Nome que sera atribuido a Escola
         */
        void setId(string id) {
            this->id = id;
        }
        /**
         * @brief Metodo set para a quantidade de habilitacoes que a Escola busca em um professor
         * 
         * @param Vetor com as quantidades de habilitacoes que a Escola busca
         */
        void setHabilitacoes(vector<int> habilitacoes) {
            this->habilitacoes = habilitacoes;
        }
        /**
         * @brief Metodo set para a quantidade de vagas da Escola
         * 
         * @param Quantidade de vagas que sera atribuida a Escola
         */
        void setVagas(int vagas) {
            this->vagas = vagas;
        }

        /**
         * @brief Metodo get para o nome
         * 
         * @return string nome da Esola
         */
        string getId() {
            return this->id;
        }
        /**
         * @brief Metodo get para as Habilitacoes Pretendidas
         * 
         * @return vector<int> Habilitacoes Pretendidas pela Escola
         */
        vector<int> getHabilitacoes() {
            return this->habilitacoes;
        }
        /**
         * @brief Metodo get para as vagas
         * 
         * @return int vagas da Escola
         */
        int getVagas() {
            return this->vagas;
        }

        /**
         * @brief Atribui um professor a Escola
         * 
         * @param professor que sera atribuido a escola
         * @param posicao no vetor do professor
         */
        void set_emparelhamento(Professor &professor, int pos);

        /**
         * @brief Verifica se uma vaga na escola ja foi preenchida
         * 
         * @param posicao no vetor de vagas que sera verificada
         * @return true se a vaga esta ocupada
         * @return false se a vaga nao esta ocupada
         */
        bool get_emparelhado(int pos);

        /**
         * @brief Retorna os professores ja atribuidos a escola
         * 
         * @return vector<Professor> professores atribuidos a escola
         */
        vector<Professor> get_emparelhados() {
            return this->professoresEmparelhados;
        }
};

/**
 * @brief Representa um vértice professor do grafo bipartido.
 *
 * A classe Professor representa um vertice sendo responsavel por administrar funcionalidades referentes a este nivel.
 *
 * Tambem eh responsavel por metodos que retornam medidas referentes a um professor.
 */
class Professor {

    private:

        string id;
        int habilitacoes;
        vector<string> interesses;
        Escola escolaEmparelhada;

    public:

        Professor() {}
        Professor(string id, int habilitacoes, vector<string> interesses) {
            this->setId(id);
            this->setHabilitacoes(habilitacoes);
            this->setInteresses(interesses);
        }

        /**
         * @brief Metodo set para o nome do Professor
         * 
         * @param Nome que sera atribuido ao Professor
         */
        void setId(string id) {
            this->id = id;
        }
        /**
         * @brief Metodo set para a quantidade de habilitacoes do Professor
         * 
         * @param Quantidade de habilitacoes que sera atribuida ao Professor
         */
        void setHabilitacoes(int habilitacoes) {
            this->habilitacoes = habilitacoes;
        }
        /**
         * @brief Metodo set para os interesses do Professor
         * 
         * @param Vetor que possui o nome das escolas nas quais o Professor esta interessado
         */
        void setInteresses(vector<string> interesses) {
            this->interesses = interesses;
        }

        /**
         * @brief Metodo get para nome
         * 
         * @return string nome do Professor
         */
        string getId() {
            return this->id;
        }
        /**
         * @brief Metodo get para habilitacoes
         * 
         * @return int quantidade de habilitacoes do Professor
         */
        int getHabilitacoes() {
            return this->habilitacoes;
        }
        /**
         * @brief Metodo get para interesses
         * 
         * @return vector<string> escolas nas quais o Professor esta interessado
         */
        vector<string> getInteresses() {
            return this->interesses;
        }

        /**
         * @brief Atribui uma escola ao Professor
         * 
         * @param escola que sera atribuida ao professor
         */
        void set_emparelhamento(Escola &escola) {
            cout << "Passei aqui: " << escola.getId() << endl;
            this->escolaEmparelhada = escola;
        }

        /**
         * @brief Retorna a escola atribuida ao professor
         * 
         * @return Escola atribuida ao professor
         */
        Escola get_emparelhamento() {
            return this->escolaEmparelhada;
        }

        /**
         * @brief Verifica se o professor ja foi atribuido a alguma escola
         * 
         * @return true se o professor ja foi atribuido a alguma escola
         * @return false se o professor nao foi atribuido a nenhuma escola
         */
        bool get_emparelhado();
};

/**
 * @brief Representa um grafo bipartido, tambem eh responsavel por medidas aplicadas no contexto macro de um grafo.
 *
 * A classe Grafo possui a funcionalidade de representar um grafo bipartido no sentido da abstracao matematica de "grafos bipartidos",
 * por meio de duas listas de Vertices, Escolas e Professores.
 */
class Grafo {

    private:

        vector<Professor> professores;
        vector<Escola> escolas;

    public:

        /**
         * @brief Metodo set para preencher os Professores do grafo
         * 
         */
        void setProfessores();
        /**
         * @brief Metodo set para preencher as Escolas do grafo
         * 
         */
        void setEscolas();

        /**
         * @brief Metodo get para professores
         * 
         * @return vector<Professor> professores
         */
        vector<Professor> getProfessores() {
            return this->professores;
        }
        /**
         * @brief Metodo get para escolas
         * 
         * @return vector<Escola> escolas
         */
        vector<Escola> getEscolas() {
            return this->escolas;
        }

        /**
         * @brief Adiciona um professor ao grafo
         * 
         * @param professor que sera adicionado
         */
        void adiciona_professor(Professor& professor) {
            this->professores.push_back(professor);
        }
        /**
         * @brief Adiciona uma escola ao grafo
         * 
         * @param escola que sera adicionado
         */
        void adiciona_escola(Escola& escola) {
            this->escolas.push_back(escola);
        }

        /**
         * @brief Computa um emparelhamento estavel entre professores e escolas
         * 
         * Computa um emparelhamento estavel entre professores e escolas favorecendo a preferencia dos professores
         * 
         */
        void calculaEmparelhamentoEstavel();
        /**
         * @brief Computa um emparelhamento estavel entre escolas e professores
         * 
         * Computa um emparelhamento estavel entre as escolas e 70 professores favorecendo a preferencia das escolas
         * 
         */
        void calculaEmparelhamentoEscola();
        /**
         * @brief Verifica se foram atribuidos professores repetidos as escolas
         * 
         */
        void checaDiferenca();

};

#endif
