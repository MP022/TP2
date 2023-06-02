#include "grafo.hpp"
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

Grafo::Grafo(){}

Grafo::Grafo(int num_vertices){
    this->no.resize(num_vertices);
}

void Grafo::adicionaAresta(int N1, int N2, int peso){
    this->no[N1-1].adicionaAdj(Aresta(N2 - 1, peso));
    this->no[N2-1].adicionaAdj(Aresta(N1 - 1, peso));
}

void Grafo::mostraGrafo(){
    int quantArestas = 0;
    for(int i = 0; i < (int)this->no.size(); i++){
        quantArestas += this->no[i].quantAdj();
    }
    quantArestas = quantArestas/2;

    std::cout << this->no.size() << " " << quantArestas << endl;
    
    for(int i = 0; i < (int)this->no.size(); i++){
        for(int j = 0; j < this->no[i].quantAdj(); j++){
            if(this->no[i].getAresta(j).getDestino() > i){
                std::cout << i+1 << " " 
                     << this->no[i].getAresta(j).getDestino() + 1 << " " 
                     << this->no[i].getAresta(j).getPeso() << " "
                     << endl;
            }
        }
    }
}

int Grafo::menorCaminho(int origem, int destino){
    vector<int> menorPeso (this->no.size(), INF);
    menorPeso[origem-1] = 0;

    vector<int> fila;
    fila.push_back(origem-1);

    while(!fila.empty()){
        int aux = fila.back();
        fila.pop_back();

        for(int i = 0; i < this->no[aux].quantAdj(); i++){
            Aresta adj = this->no[aux].getAresta(i);

            if(menorPeso[aux] + adj.getPeso() < menorPeso[adj.getDestino()]){
                menorPeso[adj.getDestino()] = menorPeso[aux] + adj.getPeso();
                fila.push_back(adj.getDestino());
            }
        }
    }
    
    if(menorPeso[destino-1] == INF){
        return -1;
    }
    return menorPeso[destino-1];
}

int Grafo::quantiaDuplasGuloso(){
    int dupla = 0;
    bool noEmparelhado[this->no.size()] = {};
    
    //verificar cada no
    for(int i = 0; i < (int)this->no.size(); i++){
        //caso ela nao esteja parelhado
        if(!noEmparelhado[i]){
            //verifica cada no que ele esta conectado
            for (int j = 0; j < this->no[i].quantAdj(); j++){
                if(!noEmparelhado[this->no[i].getAresta(j).getDestino()]){
                    noEmparelhado[i] = 1;
                    noEmparelhado[this->no[i].getAresta(j).getDestino()] = 1;
                    dupla++;
                    break;
                }
            }
        }
    }
    
    return dupla;
}

bool pairCamparaSegundoMaior(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int Grafo::quantiaDuplasPD(){
    int dupla = 0;
    bool noEmparelhado[this->no.size()] = {};

    //cria a lista de prioridade
    vector<pair<int, int>> noQuantAdj = {};
    noQuantAdj.resize(this->no.size());

    //inicializa a lista com o numero de arestas de cada no
    for(int i = 0; i < (int)this->no.size(); i++){
        noQuantAdj[i].first = i;
        //quantia de nos adj a i nao emparelhados
        noQuantAdj[i].second = this->no[i].quantAdj();
    }
    
    //organiza a lista comparando a quantidade de arestas de cada no
    sort(noQuantAdj.begin(), noQuantAdj.end(), pairCamparaSegundoMaior);

    //enquantoa ainda tiver no na lista de prioridade
    while(!noQuantAdj.empty()){
        //caso ela nao esteja emparelhado tenha nos adj nao emaparelhados
        int noAtual = noQuantAdj.back().first;
        if((!noEmparelhado[noAtual])){
            //verifica cada no que ele esta conectado
            for(int j = 0; j < this->no[noAtual].quantAdj(); j++){
                //caso um no conectado nao esteja emparelhado emparelha eles
                if(!noEmparelhado[this->no[noAtual].getAresta(j).getDestino()]){
                    noEmparelhado[noAtual] = 1;
                    noEmparelhado[this->no[noAtual].getAresta(j).getDestino()] = 1;
                    dupla++;

                    //atualiza a quantia de adj nos nos adj aos nos emparelhados
                    for(int t = 0; t < (int)noQuantAdj.size(); t++){
                        for(int i = 0; i < this->no[noQuantAdj[t].first].quantAdj(); i++){
                            if((this->no[noQuantAdj[t].first].getAresta(i).getDestino() == noAtual) || (this->no[noQuantAdj[t].first].getAresta(i).getDestino() == this->no[noAtual].getAresta(j).getDestino())){
                                noQuantAdj[t].second--;
                            }   
                        }
                    }

                    break;
                }
            }
        }
        //caso ele esteja emparelhado tira ele da lista
        noQuantAdj.pop_back();

        //organiza a lista comparando a quantidade de arestas de cada no
        sort(noQuantAdj.begin(), noQuantAdj.end(), pairCamparaSegundoMaior);
    }

    return dupla;
}

int Grafo::getN(){
    return (int)this->no.size();
}