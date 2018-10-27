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
