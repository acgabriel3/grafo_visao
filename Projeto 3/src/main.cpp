#include "../include/grafo.h"


using namespace std;

int main() {

    Grafo grafo;
    grafo.setProfessores();
    grafo.setEscolas();
    grafo.calculaEmparelhamentoEstavel();

    vector<Professor> professores = grafo.getProfessores();
    vector<Escola> escolas = grafo.getEscolas();

    ///*
    cout << "\tPROFESSORES\n\n";

    for(auto i : professores) {
        cout << i.getId() << endl;
        cout << "Habilitacoes: " << i.getHabilitacoes() << endl;

        vector<string> interesses = i.getInteresses();

        cout << "Interesses: ";
        for(auto j : interesses) {
            cout << j << " ";
        }
        cout << "\n\n";
    }


    cout << "\tESCOLAS\n\n";

    for(auto i : escolas) {
        cout << i.getId() << endl;
        vector<int> habilitacoes = i.getHabilitacoes();
        cout << "Habilitacoes: " ;
        for(auto habilitacao : habilitacoes) {
            cout << habilitacao << " ";
        }
        cout << endl;
        cout << "Vagas: " << i.getVagas() << "\n\n";
    }



    cout << "\tEMPARELHAMENTOS\n\n";

    for(auto i : professores) {
        cout << i.getId() << " emparelhado com: " << i.get_emparelhamento().getId() << endl;
    }




    Professor aux1;
    Professor aux2;

    for(auto i : escolas) {
        if(i.get_emparelhados().size() == 2) {
            cout << "escola: " << i.getId();
            cout << " prof 1: " << i.get_emparelhados()[0].getId();
            cout << " prof 2: " << i.get_emparelhados()[1].getId() << endl;
        } else  if(i.get_emparelhados().size() == 1) {
            cout << "escola: " << i.getId() << " prof 1: " << i.get_emparelhados()[0].getId() << endl;
        }
    }


    return 0;
}
