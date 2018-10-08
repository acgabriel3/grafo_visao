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

void Vertice::set_visitado() {

    this->visitado = true;

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

bool Vertice::get_visitado() {

    return this->visitado;

}

int Vertice::get_peso() {
    return this->creditos * this->dificuldade;
}

void Vertice::set_adjascente(Vertice& vertice){

    this->adjascentes.push_back(&vertice);

}

vector<Vertice*> Vertice::get_adjascentes() {

    return this->adjascentes;

}

void Vertice::set_requisito(Vertice& vertice){

    this->requisitos.push_back(&vertice);

}

vector<Vertice*> Vertice::get_requisitos() {

    return this->requisitos;

}

int Vertice::grau_entrada() {

    return this->requisitos.size();

}

int Vertice::grau_saida() {

    return this->adjascentes.size();

}

void Vertice::set_pesoCritico(int pesoCritico) {

    this->pesoCritico = pesoCritico;

}

int Vertice::get_pesoCritico() {

    return this->pesoCritico;

}

void Vertice::set_antecedente(Vertice &antecedente) {

    this->antecedente = &antecedente;

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
    vertices[j].set_requisito(vertices[i]);
}

// void Grafo::kahns() {

//     int grau;
//     vector<int> grauVertice; //devera estar pareado com os vertices do grafo, portanto a ordem dos vertices no grafo nao deve ser mudada
//     vector<Vertice> filaVertices; //devera funcionar como uma fila
//     vector<Vertice> adjascentes;
//     int qtdVisitados = 0;
//     Vertice aux;

//     for(int i = 0; i < this->vertices.size(); i++) {
//         grau = this->vertices[i].calcula_grau();
//         grauVertice.push_back(grau);
//     }

//     for(int i = 0; i < this->vertices.size(); i++) {
//         if(grauVertice[i] == 0) {
//             filaVertices.push_back(this->vertices[i]);
//         }
//     }

//     while(!filaVertices.empty()) {

//         aux = this->retiraInicio(filaVertices);
//         this->ordem_topologica.push_back(this->retiraInicio(filaVertices));

//         qtdVisitados++;
//         adjascentes = aux.get_adjascentes();

//         for(int i = 0; i < this->vertices.size(); i++) {
//             for(int j = 0; j < adjascentes.size(); j++) {

//                 if(this->vertices[i].get_nome() == adjascentes[j].get_nome()) {

//                     grauVertice[i]--;

//                     if(grauVertice[i] == 0) {
//                         filaVertices.push_back(this->vertices[i]);
//                     }

//                 }
//             }
//         }
//     }

//     if(qtdVisitados != this->vertices.size()) {
//         cout << "nao eh possivel fazer uma ordenacao topologica com esse grafo" << endl;
//     }
// }

vector<Vertice> Grafo::ordenacao_topologica() {
    stack<Vertice> pilha;
    map<string, bool> visitados;

    for(auto i : vertices) {
        if(i.grau_entrada() == 0) {
            ordenacao_topologica_aux(i, visitados, pilha);
        }
    }

    while(!pilha.empty()) {
        this->ordem_topologica.push_back(pilha.top());
        pilha.pop();
    }

    return this->ordem_topologica;
}

void Grafo::ordenacao_topologica_aux(Vertice& v, map<string, bool>& visitados, stack<Vertice>& pilha) {
    visitados[v.get_nome()] = true;

    int pos;
    for(pos = 0; pos < vertices.size(); pos++) {
        if(vertices[pos].get_nome() == v.get_nome()) {
            break;
        }
    }

    for(auto i : vertices[pos].get_adjascentes()) {
        if(!visitados[i->get_nome()]) {
            ordenacao_topologica_aux(*i, visitados, pilha);
        }
    }

    pilha.push(v);
}

// void caminho_critico(int chave, vector<Vertice*> adjascentes) {

//     if(chave == 0) { //A chave serve para identificar no loop a primeira vez que se chamou a funcao, e portanto preencher corretamente os pesos.

//         for(auto verticeDag : adjascentes) {
//             verticeDag->set_pesoCritico(verticeDag->get_peso());
//             //pesos.push_back(verticeDag.get_pesoCritico());
//             verticeDag->set_antecedente(NULL); //errei aqui
//         }

//     } else {

//         for(auto verticeDag : adjascentes) {

//             //pesos = NULL;
//             for(auto verticeAdj : verticeDag->get_adjascentes()) {
//                 int pesoNovo = verticeDag->get_pesoCritico() + verticeAdj->get_peso();
//                 if(verticeAdj->get_pesoCritico() < pesoNovo) {
//                     verticeAdj->set_pesoCritico(pesoNovo);
//                     verticeAdj->set_antecedente(verticeDag);
//                 }
//             }

//             caminho_critico(1, verticeDag->get_adjascentes);

//         }

//     }
// }

void Grafo::computa_caminhos(Vertice& v, map<string, int>& pesos, map<string, bool>& visitados) {
    visitados[v.get_nome()] = true;
    this->caminho.push_back(v);

    int pos;
    for(pos = 0; pos < vertices.size(); pos++) {
        if(vertices[pos].get_nome() == v.get_nome()) {
            break;
        }
    }

    for(auto i : vertices[pos].get_adjascentes()) {
        pesos[i->get_nome()] = max(pesos[v.get_nome()], pesos[v.get_nome()] + i->get_peso());
        if(!visitados[i->get_nome()]) {
            this->computa_caminhos(*i, pesos, visitados);
        }
    }

    if(!v.grau_saida()) {
        caminhos.emplace_back(caminho, pesos[v.get_nome()]);
    }

    visitados.clear();
    caminho.pop_back();
}

pair<vector<Vertice>, int> Grafo::caminho_critico() {
    map<string, int> pesos;

    for(auto i : this->vertices) {
        pesos[i.get_nome()] = i.get_peso();
    }

    map<string, bool> visitados;

    if(ordem_topologica.empty()) {
        this->ordenacao_topologica();
    }

    for(auto i : this->ordem_topologica) {
        if(!i.grau_entrada()) {
            computa_caminhos(i, pesos, visitados);
        }
    }

    int pos = 0, critico = 0;
    for(int i = 0; i < caminhos.size(); i++) {
        if(caminhos[i].second > critico) {
            pos = i;
            critico = caminhos[i].second;
        }
    }

    return caminhos[pos];
}