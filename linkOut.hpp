#ifndef LINKOUT_HPP
#define LINKOUT_HPP

#include <vector>
#include <string>
#include "grafo.hpp"

using namespace std;

class LinkOut{
    public:
        LinkOut(int numPessoas, int numVagas);
        void adicionaQuali(string pessoa, string vaga);
        void mostraQuali();
        int quantiaDuplasRapido();
        int quantiaDuplasExato();

    private:
        int quantP, quantV;
        Grafo quali;
        vector<string> pessoas; //o indice da pessoa no vector indica o seu nome no grafo
        vector<string> vagas; //o indice da vaga no vector somado com o total de pessoas indica o seu nome no grafo
};

#endif