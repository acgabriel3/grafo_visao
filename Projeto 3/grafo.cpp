#include "grafo.h"

//******************************************************* Metodos da classe Vertice ***************************************************

//******************************************************* Metodos da classe Grafo *****************************************************

void Grafo::setProfessores() {
    fstream file;
    file.open("professores.txt");

    if(!file) {
        cout << "Falha ao abrir arquivo" << endl;
    }

    string line, id, shabilitacoes, sinteresses;

    while(file >> line) {
        if(line == "node") {
            while(file >> line && line != "id");
            file >> id;

            while(file >> line && line != "habilitacoes");
            file >> shabilitacoes;
            int habilitacoes = stof(shabilitacoes);

            while(file >> line && line != "interesses");
            getline(file, sinteresses);
            sinteresses.erase(sinteresses.begin());

            vector<string> interesses;

            for(int i = 0; i < sinteresses.size(); i++) {
                if(sinteresses[i] == 'E') {
                    string escola = "E";
                    i++;
                    while(sinteresses[i] != ',' && sinteresses[i] != ' ' && i < sinteresses.size()) {
                        escola += sinteresses[i];
                        i++;
                    }
                    interesses.push_back(escola);
                }
            }

            Professor professor(id, habilitacoes, interesses);
            this->adiciona_professor(professor);
        }
    }
    file.close();
}

void Grafo::setEscolas() {
    fstream file;
    file.open("escolas.txt");

    if(!file) {
        cout << "Falha ao abrir arquivo" << endl;
    }

    string line, id, shabilitacoes, svagas;
    vector<int> habilitacoes;


    while(file >> line) {
        if(line == "vertice") {
            while(file >> line && line != "nome");
            file >> id;

            while(file >> line && line != "vagas");
            file >> svagas;
            int vagas = stof(svagas);

            vector<int> aux;
            while(file >> line && line != "habilidades_Requeridas");
                for(int i = 0; i < vagas; i++) {
                    file >> shabilitacoes;
                    if(i < vagas - 1) shabilitacoes.erase(shabilitacoes.size());
                    aux.push_back(stof(shabilitacoes));
                }

            habilitacoes = aux;

            Escola escola(id, habilitacoes, vagas);
            this->adiciona_escola(escola);
        }
    }
    file.close();
}

//*************************************************************************************************************************

void Escola::set_emparelhamento(Professor &professor, int pos) {

    if(pos == 1) {
        for(auto teste : this->professoresEmparelhados) {
            cout << teste.getId() << endl;
        }
        if(this->professoresEmparelhados.empty()) {
            this->professoresEmparelhados.push_back(professor);
        } else {
            cout << "teste1" << endl;
            this->professoresEmparelhados.at(pos - 1) = professor;
        }

    } else if(pos == 2) {

        if(this->professoresEmparelhados.empty()) {

            Professor vazio;
            this->professoresEmparelhados.push_back(vazio);
            this->professoresEmparelhados.push_back(professor);

        } else if(this->professoresEmparelhados.size() == 1) {
            this->professoresEmparelhados.push_back(professor);
        } else {
            cout << "teste2" << endl;
            this->professoresEmparelhados.at(pos - 1) = professor;
        }

    } else {
        cout << "posicao invalida" << endl;
    }

}

bool Escola::get_emparelhado(int pos) {

    if(this->professoresEmparelhados.size() < 1) {

        return false;

    } else if(this->professoresEmparelhados.size() == 1) {

        if(pos == 1 && !this->professoresEmparelhados[0].getId().empty()) {
            return true;
        } else {
            return false;
        }

    } else if(this->professoresEmparelhados.size() == 2) {

        if(pos == 1 && !this->professoresEmparelhados[0].getId().empty()) {
            return true;
        } else if(pos == 2 && !this->professoresEmparelhados[1].getId().empty()) {
            return true;
        } else {
            return false;
        }

    }

}

bool Professor::get_emparelhado() {

    if(escolaEmparelhada.getId().empty()) {
        return true;
    } else {
        return false;
    }

}


void Grafo::calculaEmparelhamentoEstavel() {

    bool professoresNaoEmparelhados = true; // teremos de mudar para checar por escola, pois eh a condicao de parada e tambem quantidade de professores emparelhados e estabilidade

    Professor professorAux;

    int contador = 0;
    int pos;

    while(professoresNaoEmparelhados) {

        contador++;
        cout << "contador: " << contador << endl;
        if(contador == 100) {
            break;
        }

        professoresNaoEmparelhados = false; //Seta para falso, para que se busque em cada iteracao um professor nao emparelhado;

        //Pode virar um metodo
        for(int i = 0; i < this->professores.size(); i++) {
            cout << this->professores[i].get_emparelhado() << endl;
            cout << this->professores.size() << endl;
            if(this->professores[i].get_emparelhado()) {
                    professorAux = this->professores[i];
                    pos = i;
                    professoresNaoEmparelhados = true;

                    break;
            }
        } //Busca um professor nao emparelhado para continuar o loop (isto devera ser mudado para satisfazer
        //as condicoes das especificacoes)

        for(auto escolaID : professorAux.getInteresses()) {

            // a variavel abaixo e o for podem virar um metodo
            Escola escolaAtual;

            int posEscola = 0;

            for(auto escola : this->escolas) {
                    posEscola++;
                    if(escola.getId() == escolaID) {
                        escolaAtual = escola;
                        break;
                    }
            }

            if(escolaAtual.getId().empty()) { //Sempre encontrarei a escola, n?
                continue;
            }


            if(!escolaAtual.get_emparelhado(1) || !escolaAtual.get_emparelhado(2)) { // se nao estiver emparelhado (esta condicao tera de mudar pois a escola pode ter ateh dois professores

                int valor = -1;
                int posPreferencia = 0;
                for(auto preferencia : escolaAtual.getHabilitacoes()) {

                    posPreferencia++;

                    if(preferencia <= professorAux.getHabilitacoes()) {

                        valor = preferencia; // checa a quantidade de habilitacoes exigida pela escola
                        break;

                    }
                } // Checar se a escola esta entre as preferencias do professor


                if((valor > 0)) {

                    this->professores[pos].set_emparelhamento(escolaAtual); //Os emparelhamentos tambem devem ser realizados na escola. Devemos salvar o id do aux para realizar isso de maneira mais eficiente
                    cout << "reulou" << endl;
                    cout << posEscola << endl;
                    cout << posPreferencia << endl;
                    this->escolas[posEscola].set_emparelhamento(this->professores[pos], posPreferencia);
                    continue;


                } else {

                    continue;

                }

            } else {

                int valor = -1;
                int posPreferencia = 0;
                for(auto professorMomentaneo : escolaAtual.get_emparelhados()) {

                    posPreferencia++;

                    if(professorMomentaneo.getHabilitacoes() <= professorAux.getHabilitacoes()) { //Essa condicao podera mudar de acordo com qual tipo de professor a escola prefere

                        valor = 1;
                        break;

                    }
                } // Checa se eh um professor melhor para a escola


                if((valor > 0)) {

                    this->professores[pos].set_emparelhamento(escolaAtual);
                    this->escolas[posEscola].set_emparelhamento(this->professores[pos], posPreferencia);
                    continue;

                }

            }
        }

    }

}
























