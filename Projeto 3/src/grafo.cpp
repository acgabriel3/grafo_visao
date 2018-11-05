#include "../include/grafo.h"

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
            cout << "posicao: " << pos << endl;
            this->professoresEmparelhados.at(pos - 1) = professor;
        }

    } else {
        cout << "posicao invalida" << endl;
    }

}

bool Escola::get_emparelhado(int pos) {

    if(this->professoresEmparelhados.empty()) {

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

    return false;

}

bool Professor::get_emparelhado() {

    if(this->escolaEmparelhada.getId().empty()) {
        return false;
    } else {
        return true;
    }

}


void Grafo::calculaEmparelhamentoEstavel() {

    bool professoresNaoEmparelhados = true; // teremos de mudar para checar por escola, pois eh a condicao de parada e tambem quantidade de professores emparelhados e estabilidade

    Professor professorAux;

    int contador = 0;
    int pos;
    vector<int> posExcluidos;

    cout << "pos 1" << endl;

    while(professoresNaoEmparelhados) {

        contador++;
        cout << "contador: " << contador << endl;
        if(contador == 100000) {
            cout << "sai da funcao" << endl;
            break;
        }
            cout << "pos 2" << endl;

        professoresNaoEmparelhados = false; //Seta para falso, para que se busque em cada iteracao um professor nao emparelhado;

        //Pode virar um metodo
        for(int i = 0; i < this->professores.size(); i++) {


            for(auto position : posExcluidos) {
                if(position == i) {
                        cout << "-----------------------------aqui" << endl;
                    i++;
                }
            }
            if(!this->professores[i].get_emparelhado()) { //Checa se nao esta emparelhado
                    if(professorAux.getId() == this->professores[i].getId()) {
                        posExcluidos.push_back(i);
                        cout << "----------------------------------pos: " << i << endl;
                        continue;
                    }

                    /* investigar porque estou obtendo um loop infinito
                    bool loopInfinito = true;

                    for(auto preferencias : this->professores[i].getInteresses()) {
                        int posEscolaLoop;
                        for(int j = 0; j < this->escolas.size(); j++) {
                            if(this->escolas[j].getId() == preferencias) {
                                posEscolaLoop = j;
                                break;
                            }
                        }
                        if(!this->escolas[posEscolaLoop].get_emparelhados().empty()) {
                            for(auto professorNaEscola : this->escolas[posEscolaLoop].get_emparelhados()) {
                                if(professorNaEscola.getHabilitacoes() < this->professores[i].getHabilitacoes()) {
                                    loopInfinito = false;
                                }
                            }
                        } else {
                            loopInfinito = false;
                        }
                    }


                    if(loopInfinito) {
                        continue;
                    }
                    */


                    professorAux = this->professores[i];
                    cout << "professor nao emparelhado: " << professorAux.getId() << endl;
                    pos = i;
                    professoresNaoEmparelhados = true;

                    break;
            }
        } //Busca um professor nao emparelhado para continuar o loop (isto devera ser mudado para satisfazer
        //as condicoes das especificacoes)

            cout << "pos 3" << endl;

        for(auto escolaID : professorAux.getInteresses()) {

                cout << "pos 4" << endl;


            if(this->professores[pos].get_emparelhado()) {
                break;
            }
            // a variavel abaixo e o for podem virar um metodo
            Escola escolaAtual;

            int posEscola = 0;

            for(int i = 0; i < this->escolas.size(); i++) {

                    if(this->escolas[i].getId() == escolaID) {

                        escolaAtual = this->escolas[i];
                        posEscola = i;
                        break;

                    }
            }

                cout << "pos 5" << endl;


            if(escolaAtual.getId().empty()) { //Sempre encontrarei a escola, n?
                cout << "PAssei pela escola vazia" << endl;
                continue;
            }

                cout << "pos 7" << endl;



            //if(!escolaAtual.get_emparelhado(1) || !escolaAtual.get_emparelhado(2)) { // se nao estiver emparelhado (esta condicao tera de mudar pois a escola pode ter ateh dois professores

                int valor = -1;
                int posPreferencia = 0;
                int retiraProf = -1;

                for(auto preferencia : escolaAtual.getHabilitacoes()) {

                    posPreferencia++;
                    cout << "------------------------" << professorAux.get_emparelhado() << endl;

                    if((preferencia <= professorAux.getHabilitacoes())) {
                        if(!escolaAtual.get_emparelhado(posPreferencia)) {
                            valor = 1;
                            break;
                        } else if(escolaAtual.get_emparelhado(posPreferencia)) {
                            if(escolaAtual.get_emparelhados()[posPreferencia - 1].getHabilitacoes() < professorAux.getHabilitacoes()) {
                                valor = 1;
                                for(int i = 0; i < this->professores.size(); i++) {
                                    if(escolaAtual.get_emparelhados()[posPreferencia - 1].getId() == this->professores[i].getId()) {
                                        retiraProf = i;
                                        break;
                                    }
                                }
                                break;
                            }
                        }

                    }
                } // Checar se a escola esta entre as preferencias do professor

                    cout << "pos 8" << endl;

                if((valor > 0)) {

                    this->professores[pos].set_emparelhamento(escolaAtual);
                    cout << "posicao da escola emparelhada: " << posEscola << endl;
                    cout << "posicao da preferencia: " << posPreferencia << endl;
                    cout << "posicao que sera emparelhada: " << pos << endl;
                    this->escolas[posEscola].set_emparelhamento(this->professores[pos], posPreferencia);

                    if(retiraProf > 0) {
                        Escola vazia;
                        this->professores[retiraProf].set_emparelhamento(vazia);
                    }
                        cout << "pos 9" << endl;

                    continue;


                } else {

                    continue;

                }

            /*}  else {

                    cout << "pos 10" << endl;

                int valor = -1;
                int posPreferencia = 0;
                int posProfMomen = 0;
                for(auto professorMomentaneo : escolaAtual.get_emparelhados()) {

                    posPreferencia++;

                    if((professorMomentaneo.getHabilitacoes() <= professorAux.getHabilitacoes())) { //Essa condicao podera mudar de acordo com qual tipo de professor a escola prefere

                        for(int i = 0; i < this->professores.size(); i++) {
                            if(this->professores[i].getId() == professorAux.getId()) {
                                posProfMomen = i;
                                break;
                            }
                        }

                        valor = 1;
                        break;

                    }
                } // Checa se eh um professor melhor para a escola

                    cout << "pos 11" << endl;

                if((valor > 0)) {

                    Escola vazia;
                    this->professores[pos].set_emparelhamento(escolaAtual);
                    this->professores[posProfMomen].set_emparelhamento(vazia);
                    cout << "2posicao da escola emparelhada: " << posEscola << endl;
                    cout << "2posicao da preferencia: " << posPreferencia << endl;
                    cout << "2posicao que sera emparelhada: " << pos << endl;
                    this->escolas[posEscola].set_emparelhamento(this->professores[pos], posPreferencia);
                        cout << "pos 12" << endl;

                    continue;

                }

            }*/
        }

    }


}
























