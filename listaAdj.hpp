#ifndef LISTAADJ_HPP
#define LISTAADJ_HPP

#include <vector>
#include "aresta.hpp"

class ListaAdj{
    public:
        ListaAdj(){};
        ListaAdj(int numV){
            this->adj.resize(numV);
        };
        void adicionaAdj(Aresta n){
            this->adj.push_back(n);
        };
        int quantAdj(){
            return this->adj.size();
        };
        Aresta getAresta(int a){
            return this->adj[a];
        };
    private:
        std::vector<Aresta> adj;
};

#endif