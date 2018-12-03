#include "../include/grafo.h"


// é inutil agora
int Grafo::achaPosicao(int id) {

    int pos = -1;

    for(int i = 0; i < this->vertices.size(); i++) {
        if(this->vertices[i].get_id() == id) {
            pos = i;
        }
    }

    return pos;

}


// mexi aqui nessa função e mudei pro find
void Grafo::arestaDirecionada(Vertice& origem, Vertice& destino) {
    if (find(this->vertices.begin(), this->vertices.end(), origem) == this->vertices.end()) {
        this->vertices.push_back(origem);
    }
    if (find(this->vertices.begin(), this->vertices.end(), destino) == this->vertices.end()) {
        this->vertices.push_back(destino);
    }

    vertices[find(this->vertices.begin(), this->vertices.end(), origem) - this->vertices.begin()].set_adjascente(destino);
}


void Grafo::show() {

    for(int i = 0; i < this->vertices.size(); i++) {

        cout << "[" << this->vertices[i].get_id() << "]: ";

        for(int j = 0; j < this->vertices[i].get_adjascentes().size(); j++) {
            cout << this->vertices[i].get_adjascentes()[j].get_id() << " ";
        }

        cout << endl;
    }

}

// agora vc ja manda o vertice construido pro grafo
bool Grafo::leitura() {

    fstream file;
    file.open("email-Eu-core.txt");

    if(!file.is_open()) {
        return false;
    }

    string line;
    int lin = 1;
    while (getline(file, line)) {
        if (line.find("//") != string::npos) {
            continue;
        } else {
            cout << "linha: " << lin << "\n";
            int src, dest;
            stringstream formated(line);
            formated >> src >> dest;
            // cout << src << " " << dest << "\n";
            // cout << src << "\n";

            Vertice origem = Vertice();
            origem.set_id(src);
            Vertice destino = Vertice();
            destino.set_id(dest);
            this->arestaDirecionada(origem, destino);
            ++lin;
        }
    }

    return true;
}

void Grafo::calculaTotalArestas() {

    this->totalArestas = 0;

    for(auto vertice : this->vertices) {
        this->totalArestas += vertice.get_adjascentes().size();
    }

}

double Grafo::computaEIJ(Comunidade comunidadeA, Comunidade comunidadeB) {

    double porcentagemSaida;

    if(this->totalArestas == 0) {
      this->calculaTotalArestas();
    }

    vector<Vertice> verticesB = comunidadeB.get_vertices();

    int arestasSaindo = 0;

    for(auto verticeA : comunidadeA.get_vertices()) {
        if (find(verticesB.begin(), verticesB.end(), verticeA) < verticesB.end()) {
            arestasSaindo++;
        }
    }

    porcentagemSaida = arestasSaindo/this->totalArestas;

    return porcentagemSaida;

}

void Grafo::computaA(Comunidade comunidade) {

    double A = 0;

    for(auto comunidadeB : this->comunidades) {
        A += this->computaEIJ(comunidade, comunidadeB);
    }

    comunidades[find(this->comunidades.begin(), this->comunidades.end(), comunidade) - this->comunidades.begin()].set_A(A);

}

int Grafo::computaQ(vector<Comunidade> comunidade) {

    double porcentagemAtual;
    double Q;

    for(auto comunidade : this->comunidades) {
        porcentagemAtual = this->computaEIJ(comunidade, comunidade);
        Q += porcentagemAtual - (comunidade.get_A() * comunidade.get_A());
    }

    return Q;

}

void Grafo::TesteMetodos() {


}

void Grafo::encontraComunidades() {

    //Usar vetor auxiliar para Q. Portanto um vetor de comunidades auxiliar e um int Q com o peso de Q na determinada iteracao.
    //Ao final das iteracoes do algoritmo, o maior Q jah estarah selecionado

    double maiorQ = numeric_limits<double>::min();
    vector<Comunidade> comunidadesMaiorQ;
    vector<Comunidade> comunidadesMaiorQIteracao;

    int iteracoes = this->vertices.size();

    //Todo vertice eh uma comunidade:

    for(for auto vertice : this->vertices) {
        this->set_comunidade(vertice);
    }

    for(int i = 0; i < iteracoes; i++) {

        double maiorQIteracao = numeric_limits<double>::min();
        vector<Comunidade> auxComunidade = this->comunidades;

        for(int posComunidadeIteracao = 0; posComunidadeIteracao < auxComunidade.size(); posComunidadeIteracao++)   {
            Comunidade aux; //Servira para fazer a uniao das comunidades sem alterar o vetor de fato

            //Fazer a uniao somente com as comunidades que possuem Q como adjascente

            vector<Comunidade> adjascentes;


        }

    }


}


//**************************************************************Funcoes De comunidade**************************************************
//OBS: Idealmente deveria haver um arquivo para cada uma dessa classe. Treinar isso nos proximo projetos.

void Comunidade::uniaoComunidades(Comunidade comunidade) {

    for(auto vertice : comunidade.get_vertices()) {
        this->set_vertice(vertice);
    }

}




































































