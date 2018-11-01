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
bool Professor::get_emparelhado() {

    if(escolaEmparelhada.getId().empty()) {
        return false;
    } else {
        return true;
    }

}


void Grafo::calculaEmparelhamentoEstavel() {

    bool professoresNaoEmparelhados = true;

    Professor professorAux;

    int contador = 0;
    int pos;

    while(professoresNaoEmparelhados) {

        contador++;
        if(contador == 100) {
            break;
        }

        professoresNaoEmparelhados = false; //Seta para falso, para que se busque em cada iteracao um professor nao emparelhado;

        //Pode virar um metodo
        for(int i = 0; i < this->professores.size(); i++) {
            if(this->professores[i].get_emparelhado()) {

                    professorAux = this->professores[i];
                    pos = i;
                    professoresNaoEmparelhados == true;

                    break;
            }
        } //Busca um professor nao emparelhado para continuar o loop (isto devera ser mudado para satisfazer
        //as condicoes das especificacoes)

        for(auto escolaID : professorAux.getInteresses()) {

            // a variavel abaixo e o for podem virar um metodo
            Escola escolaAtual;

            for(auto escola : this->escolas) {
                    if(escola.getId() == escolaID) {
                        escolaAtual = escola;
                    }
            }

            if(escolaAtual.getId().empty()) {
                continue;
            }

            if(!escolaAtual.get_emparelhado()) { // se nao estiver emparelhado (esta condicao tera de mudar pois a escola pode ter ateh dois professores

                int valor = -1;
                for(auto preferencia : escolaAtual.getHabilitacoes()) {
                    if(preferencia <= professorAux.getHabilitacoes()) {

                        valor = preferencia; // checa a quantidade de habilitacoes exigida pela escola
                        break;

                    }
                } // Checar se a escola esta entre as preferencias do professor

                if((valor > 0)) {

                    this->professores[pos].set_emparelhamento(escolaAtual); //Os emparelhamentos tambem devem ser realizados na escola. Devemos salvar o id do aux para realizar isso de maneira mais eficiente
                    break;

                } else {

                    continue;

                }

            } /*else {

                //professor.set_emparelhamento(escolaAtual); //Mudar essa funcao tambem
                //break;
                continue;
            } */
        }

    }

}
























