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

    while(file >> line) {
        if(line == "node") {
            while(file >> line && line != "id");
            file >> id;

            while(file >> line && line != "habilitacoes");
            file >> shabilitacoes;
            int habilitacoes = stof(shabilitacoes);

            while(file >> line && line != "vagas");
            file >> svagas;
            int vagas = stof(svagas);

            Escola escola(id, habilitacoes, vagas);
            this->adiciona_escola(escola);
        }
    }
    file.close();
}

//*************************************************************************************************************************
bool Professor::get_emparelhado() {
    
    if(escolaEmparelhada == NULL) {
        return false;
    } else {
        return true; 
    }

}

void Grafo::calculaEmparelhamentoEstavel() {

    //Emparelhamento emparelhamento;
    bool escolasNaoEmparelhadas = true;

   // for(auto vertice : this->vertices) {
//
   //     vertice.setNaoEmparelhado();
//
   // } //Essa parte se torna inutil, pois ao iniciar as variaveis, as mesmas comecam desemparelhadas

    Vertice aux;

    while(escolasNaoEmparelhadas) {

        escolasNaoEmparelhadas = false; //Seta para falso, para que se busque em cada iteracao um professor nao emparelhado;

        for(auto escola : this->escolas) {
            if(escola.get_emparelhado()) {

                    aux = escola;
                    escolasNaoEmparelhadas == true;

                    break;
            }
        } //Busca um professor nao emparelhado para continuar o loop (isto devera ser mudado para satisfazer 
        //as condicoes das especificacoes)

        for(auto professor : aux.get_preferencias()) { //A escola nao possui preferencias entao este laco deve ser modificado
            if(!professor.get_emparelhado()) { // se nao estiver emparelhado

                int valor;
                for(auto preferencia : professor.get_preferencias()) { //A lista de preferencias deve estar ordenada do melhor para o pior
                    if(preferencia.get_id() == aux.get_id()) {
                        valor = preferencia.get_habilitacao(); // checa a quantidade de habilitacoes exigida pela escola
                        break;
                    }
                } // Checar se a escola esta entre as preferencias do professor

                if(professor.get_habilitacao() >= valor) {
                    professor.set_emparelhamento(aux); //Os emparelhamentos tambem devem ser realizados na escola. Devemos salvar o id do aux para realizar isso de maneira mais eficiente
                    break;
                } else {

                    continue;

                }

            } else {
                professor.set_emparelhamento(aux);
                break;
            }
        }

    }

    //return emparelhamento;
}
























