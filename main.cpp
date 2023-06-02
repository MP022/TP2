#include <getopt.h>
#include <iostream>
#include "linkOut.hpp"

#define INF 0x3f3f3f3f

using namespace std;

bool guloso = 0;

void parse_args(int argc,char *argv[]){
    int c; 
    while((c = getopt(argc, argv, ":n")) != EOF){
        switch(c){
        case 'n':
            guloso = 0;
            break;
        default:
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    parse_args(argc, argv);
    int numPessoas, numVagas, numQuali;

    cin >> numPessoas >> numVagas >> numQuali;

    LinkOut link = LinkOut(numPessoas, numVagas);

    string nomePessoa, nomeVaga;
    for(int i = 0; i < numQuali; i++){
        cin >> nomePessoa >> nomeVaga;
        link.adicionaQuali(nomePessoa, nomeVaga);
    }
    
    //link.mostraQuali();

    cout << "Guloso: " << link.quantiaDuplasRapido() << endl;
    cout << "Exato: " << link.quantiaDuplasExato() << endl;

    return 0;
}
