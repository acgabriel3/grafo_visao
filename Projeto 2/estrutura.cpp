#include "estrutura.h"

//*******************************************************Metodos da classe Vertice***************************************************

void Vertice::set_nome(string nome) {

    this->nome = nome;

}

void Vertice::set_creditos(int creditos) {

    this->creditos = creditos;

}

void Vertice::set_dificuldade(int dificuldade) {

    this->dificuldade = dificuldade;

}

string Vertice::get_nome() {

    return this->nome;

}

int Vertice::get_creditos() {

    return this->creditos;

}

int Vertice::get_dificuldade() {

    return this->dificuldade;

}

void Vertice::set_adjascente(Vertice& vertice){

    this->adjascentes.push_back(vertice);

}

vector<Vertice> Vertice::get_adjascentes() {

    return this->adjascentes;

}

//*******************************************************Metodos da classe Grafo***************************************************

void Grafo::set_vertices(string arquivo) {
    fstream file;
    file.open(arquivo);

    if(!file) {
        cout << "Falha ao abrir arquivo" << endl;
    }

    string line, nome, screditos, sdificuldade;

    while(file >> line) {
        if(line == "node") {
            while(file >> line && line != "nome");
            getline(file, nome);
            nome.erase(nome.begin(), nome.begin() + 1);

            while(file >> line && line != "creditos");
            file >> screditos;
            int creditos = stof(screditos);

            while(file >> line && line != "dificuldade");
            file >> sdificuldade;
            int dificuldade = stof(sdificuldade);

            Vertice vertice(nome, creditos, dificuldade);
            this->adiciona_vertice(vertice);
        }
    }
    file.close();
    this->set_arestas(arquivo);
}

vector<Vertice> Grafo::get_vertices() {

    return this->vertices;

}

void Grafo::adiciona_vertice(Vertice& vertice){

    this->vertices.push_back(vertice);

}

vector<Vertice> Grafo::retira_vertice(Vertice& vertice) {
    
}

void Grafo::set_arestas(string arquivo) {
    fstream file;
    file.open(arquivo);

    if(!file) {
        cout << "Falha ao abrir arquivo" << endl;
    }

    string line, source, target;

    while(file >> line) {
        if(line == "edge") {
            while(file >> line && line != "target");
            getline(file, target);
            target.erase(target.begin(), target.begin() + 1);

            while(file >> line && line != "source");
            getline(file, source);
            source.erase(source.begin(), source.begin() + 1);

            this->cria_aresta(source, target);
        }
    }
    file.close();
}

void Grafo::cria_aresta(string source, string target) {

    int i,
        j;

    for(i = 0; i < vertices.size(); i++) {
        if(vertices[i].get_nome() == source) {
            break;
        }
    }

    for(j = 0; j < vertices.size(); j++) {
        if(vertices[j].get_nome() == target) {
            break;
        }
    }
    
    vertices[i].set_adjascente(vertices[j]);
}
