#ifndef ARESTA_HPP
#define ARESTA_HPP

class Aresta {
    public:
        Aresta(){};
        Aresta(int destino, int peso){
            this->destino = destino;
            this->peso = peso;
        };
        int getDestino(){
            return destino;
        };
        int getPeso(){
            return peso;
        };
    private:
        int destino;
        int peso;
};

#endif