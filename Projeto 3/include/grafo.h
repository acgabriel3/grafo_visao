#ifndef GRAFO_H
#define GRAFO_H

#include <bits/stdc++.h>

using namespace std;

class Professor;

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

        void setId(string id) {
            this->id = id;
        }
        void setHabilitacoes(vector<int> habilitacoes) {
            this->habilitacoes = habilitacoes;
        }
        void setVagas(int vagas) {
            this->vagas = vagas;
        }

        string getId() {
            return this->id;
        }
        vector<int> getHabilitacoes() {
            return this->habilitacoes;
        }
        int getVagas() {
            return this->vagas;
        }

        void set_emparelhamento(Professor &professor, int pos);

        bool get_emparelhado(int pos);

        vector<Professor> get_emparelhados() {
            return this->professoresEmparelhados;
        }
};

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

        void set_emparelhamento(Escola &escola) {
            cout << "Passei aqui: " << escola.getId() << endl;
            this->escolaEmparelhada = escola;
        }

        Escola get_emparelhamento() {
            return this->escolaEmparelhada;
        }

        bool get_emparelhado();
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
        void calculaEmparelhamentoEscola();
        void checaDiferenca();

};

#endif
