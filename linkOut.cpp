#include "linkOut.hpp"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

LinkOut::LinkOut(int numPessoas, int numVagas){
    this->quali = Grafo(numPessoas + numVagas);
    this->pessoas.clear();
    this->vagas.clear();
    this->quantP = numPessoas;
    this->quantV = numVagas;
}

void LinkOut::adicionaQuali(string pessoa, string vaga){
    int indP, indV;

    //caso a pessoa não exista na lista adiciona
    auto endP = find(this->pessoas.begin(), this->pessoas.end(), pessoa);
    if(this->pessoas.empty() || (endP == end(this->pessoas))){
        if((int)this->pessoas.size()<this->quantP){
            this->pessoas.push_back(pessoa);
        }else{
            return;
        }

        indP = this->pessoas.size();
    }else{
        indP = endP - this->pessoas.begin() + 1;
    }
    
    //caso a vaga não exista na lista adiciona
    auto endV = find(this->vagas.begin(), this->vagas.end(), vaga);
    if(this->vagas.empty() || (endV == end(this->vagas))){
        if((int)this->vagas.size()<this->quantV){
            this->vagas.push_back(vaga);
        }else{
            return;
        }

        indV = this->vagas.size() + this->quantP;
    }else{
        indV = endV - this->vagas.begin() + 1 + this->quantP;
    }

    this->quali.adicionaAresta(indP, indV, 1);
}

void LinkOut::mostraQuali(){
    int i = 0; 
    for(i = 0; i < (int)this->pessoas.size(); i++){
        cout << i + 1 << " " << this->pessoas[i] << endl;
    }

    for(int j = 0; j < (int)this->vagas.size(); j++){
        cout << i + j << " " << this->vagas[j] << endl;
    }

    this->quali.mostraGrafo();
}

int LinkOut::quantiaDuplasRapido(){
    return this->quali.quantiaDuplasGuloso();
}

int LinkOut::quantiaDuplasExato(){
    return this->quali.quantiaDuplasPD();
}