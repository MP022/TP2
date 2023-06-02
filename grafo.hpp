#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include "listaAdj.hpp"

class Grafo {
    public:
        Grafo();
        Grafo(int num_vertices);
        void adicionaAresta(int N1, int N2, int peso);
        void mostraGrafo();
        int menorCaminho(int origem, int destino);
        int quantiaDuplasGuloso();
        int quantiaDuplasPD();
        int getN();
    private:
        std::vector<ListaAdj> no;
};

#endif