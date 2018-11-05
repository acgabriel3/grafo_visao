#include "../include/grafo.h"


using namespace std;

int main() {

    Grafo grafo;
    grafo.setProfessores();
    grafo.setEscolas();
    //grafo.calculaEmparelhamentoEstavel();
    grafo.calculaEmparelhamentoEscola();

    vector<Professor> professores = grafo.getProfessores();
    vector<Escola> escolas = grafo.getEscolas();

    ofstream x;
    x.open("imprima.txt", ios::app);
    if(!x.is_open()) {
        cout << "kkkkkkkk";
        exit(EXIT_FAILURE);
    }

    ///*
    x << "\tPROFESSORES\n\n";

    for(auto i : professores) {
        x << i.getId() << endl;
        x << "Habilitacoes: " << i.getHabilitacoes() << endl;

        vector<string> interesses = i.getInteresses();

        x << "Interesses: ";
        for(auto j : interesses) {
            x << j << " ";
        }
        x << "\n\n";
    }


    x << "\tESCOLAS\n\n";

    for(auto i : escolas) {
        x << i.getId() << endl;
        vector<int> habilitacoes = i.getHabilitacoes();
        x << "Habilitacoes: " ;
        for(auto habilitacao : habilitacoes) {
            x << habilitacao << " ";
        }
        x << endl;
        x << "Vagas: " << i.getVagas() << "\n\n";
    }



    x << "\tEMPARELHAMENTOS\n\n";

    for(auto i : professores) {
        x << i.getId() << " emparelhado com: " << i.get_emparelhamento().getId() << endl;
    }




    Professor aux1;
    Professor aux2;

    for(auto i : escolas) {
        if(i.get_emparelhados().size() == 2) {
            x << "escola: " << i.getId();
            x << " prof 1: " << i.get_emparelhados()[0].getId();
            x << " prof 2: " << i.get_emparelhados()[1].getId() << endl;
        } else  if(i.get_emparelhados().size() == 1) {
            x << "escola: " << i.getId() << " prof 1: " << i.get_emparelhados()[0].getId() << endl;
        }
    }

    grafo.checaDiferenca();

    return 0;
}
