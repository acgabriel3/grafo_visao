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
                        for(auto preferencias : this->escolas[posEscolaLoop].getHabilitacoes()) {
                            if(preferencias < this->professores[i].getHabilitacoes()) {
                                loopInfinito = false;
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
                        i++;
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



void Grafo::calculaEmparelhamentoEscola() {

    bool condicoesInsatisfeitas = true;
    int contador = 0;

    int posPreferencia = 0;

    while(condicoesInsatisfeitas) {
        contador++;
        if(contador == 5000) {
            break;
        }


        for(int escola = 0; escola < this->escolas.size(); escola++) {
            if(this->escolas[escola].get_emparelhado(posPreferencia + 1)) {
                continue;
            } else if(this->escolas[escola].getHabilitacoes().size() < (posPreferencia + 1)) {
                continue;
            }

            int preferencia = this->escolas[escola].getHabilitacoes()[posPreferencia];

            for(int professor = 0; professor < this->professores.size(); professor++) {
                if(this->professores[professor].getHabilitacoes() >= preferencia) {
                    if(this->professores[professor].get_emparelhado()) {

                        int posPreferenciaProf = -1;
                        for(int preferenciaProf = 0; preferenciaProf < this->professores[professor].getInteresses().size(); preferenciaProf++){

                            if(this->professores[professor].getInteresses()[preferenciaProf] == this->escolas[escola].getId()){
                                posPreferenciaProf = preferenciaProf;
                                break;
                            }
                        }

                        if(posPreferenciaProf > -1) {
                            int posPreferenciaAtual = -1;
                            for(int preferenciaAtual = 0; preferenciaAtual < this->professores[professor].getInteresses().size(); preferenciaAtual++){
                                if(this->professores[professor].getInteresses()[posPreferenciaProf] == this->professores[professor].get_emparelhamento().getId()){
                                    posPreferenciaAtual = preferenciaAtual;
                                    break;
                                }
                            }
                            if(posPreferenciaProf < posPreferenciaAtual) {
                                cout << "---------------Visao1" << endl;
                                this->professores[professor].set_emparelhamento(this->escolas[escola]);
                                this->escolas[escola].set_emparelhamento(this->professores[professor], posPreferencia + 1);
                                Professor vazio;
                                int posEscolaSubstituida = -1;
                                for(int escolaSubstituida = 0; escolaSubstituida < this->escolas.size(); escolaSubstituida++) {
                                    if(this->escolas[escolaSubstituida].getId() == this->professores[professor].getInteresses()[posPreferenciaAtual]) {
                                        posEscolaSubstituida = escolaSubstituida;
                                    }
                                }
                                this->escolas[posEscolaSubstituida].set_emparelhamento(vazio, posPreferencia + 1);
                                break;
                            } else {
                                continue;
                            }
                        } else {
                            continue;
                        }

                     } else { //PArece que estou fechando erroneamente da mesma maneira o loop

                        int posPreferenciaProf = -1;
                        for(int preferenciaProf = 0; preferenciaProf < this->professores[professor].getInteresses().size(); preferenciaProf++){

                            if(this->professores[professor].getInteresses()[preferenciaProf] == this->escolas[escola].getId()){
                                posPreferenciaProf = preferenciaProf;
                                break;
                            }
                        }

                        if(posPreferenciaProf > -1) {
                            cout << "---------------Visao2" << endl;
                            this->professores[professor].set_emparelhamento(this->escolas[escola]);
                            this->escolas[escola].set_emparelhamento(this->professores[professor], posPreferencia + 1);
                            break;
                        } else {
                            continue;
                        }

                        }

                    }
                }
            }


        if(posPreferencia < 1) {
            posPreferencia++;
        } else {
            posPreferencia = 0;
        }
    }

    int retiraSegunda = 1;
    int contaAteSete = 0;
    int posRetrasada = 5;
    bool naoRetirouSete = true;

    while(naoRetirouSete) {

        for(int escola = 0; escola < this->escolas.size(); escola++) {

            if(this->escolas[escola].get_emparelhados().size() < 2) {
                continue;
            } else if(this->escolas[escola].get_emparelhados()[0].getId().empty()) {
                continue;
            }

            Professor professorAtual = this->escolas[escola].get_emparelhados()[retiraSegunda];
            int posProfessor = -1;
            for(int professor = 0; professor < this->professores.size(); professor++) {
                if(this->professores[professor].getId() == professorAtual.getId()) {
                    posProfessor = professor;
                    break;
                }
            }

            int contaPreferencia = 0;
            for(auto preferenciasAtual : professorAtual.getInteresses()) {
                contaPreferencia++;
                if(preferenciasAtual == this->escolas[escola].getId()) {
                    break;
                }
            }

            if(contaPreferencia == posRetrasada && posProfessor > -1) {
                Escola vazia;
                this->professores[posProfessor].set_emparelhamento(vazia);
                Professor vazio;
                this->escolas[escola].set_emparelhamento(vazio, retiraSegunda + 1);
                contaAteSete++;
            }
            if(contaAteSete == 7) {
                naoRetirouSete = false;
                break;
            }

        }

        posRetrasada--;

    }

}

void Grafo::checaDiferenca() {

    bool professoresDiferentes = true;
    vector<Professor> profEmparelhados;

    for(int i = 0; i < this->escolas.size(); i++) {
        for(int j = 0; j < this->escolas[i].get_emparelhados().size(); j++) {
            for(auto professor : profEmparelhados) {
                if(this->escolas[i].get_emparelhados()[j].getId() == professor.getId()) {
                    professoresDiferentes = false;
                    cout << "professor repetido: " << professor.getId() << endl;
                    break;
                }
            }
            if(!professoresDiferentes) {
                break;
            }
            profEmparelhados.push_back(this->escolas[i].get_emparelhados()[j]);
        }
    }

    cout << "professores nao repetido: " << professoresDiferentes << endl;

}




















