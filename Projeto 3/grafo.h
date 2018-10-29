#ifndef GRAFO_H
#define GRAFO_H

#include <bits/stdc++.h>

using namespace std;

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

        void setId(string id) {
            this->id = id;
        }
        void setHabilitacoes(int habilitacoes) {
            this->habilitacoes = habilitacoes;
        }
        void setInteresses(vector<string> interesses) {
            this->interesses = interesses;
        }

        string getId() {
            return this->id;
        }
        int getHabilitacoes() {
            return this->habilitacoes;
        }
        vector<string> getInteresses() {
            return this->interesses;
        }

        void set_emparelhamento(Escola escola) {
            this->escolaEmparelhada = escola;
        }

        Escola get_emparelhamento() {
            return this->escolaEmparelhada;$
        }

        bool get_emparelhado();
};

class Escola {

    private:

        string id;
        int habilitacoes;
        int vagas;

    public:

        Escola() {}
        Escola(string id, int habilitacoes, int vagas) {
            this->setId(id);
            this->setHabilitacoes(habilitacoes);
            this->setVagas(vagas);
        }

        void setId(string id) {
            this->id = id;
        }
        void setHabilitacoes(int habilitacoes) {
            this->habilitacoes = habilitacoes;
        }
        void setVagas(int vagas) {
            this->vagas = vagas;
        }

        string getId() {
            return this->id;
        }
        int getHabilitacoes() {
            return this->habilitacoes;
        }
        int getVagas() {
            return this->vagas;
        }
};

class Grafo { //Pensar em comos sera formado um emparelhamento

    private:

        vector<Professor> professores;
        vector<Escola> escolas;

    public:

        void setProfessores();
        void setEscolas();

        vector<Professor> getProfessores() {
            return this->professores;
        }
        vector<Escola> getEscolas() {
            return this->escolas;
        }

        void adiciona_professor(Professor& professor) {
            this->professores.push_back(professor);
        }
        void adiciona_escola(Escola& escola) {
            this->escolas.push_back(escola);
        }

        void calculaEmparelhamentoEstavel();
};

#endif
