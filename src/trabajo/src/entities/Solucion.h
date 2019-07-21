#ifndef AED3_TP3_SOLUCION_H
#define AED3_TP3_SOLUCION_H

class Solucion {

public:
    Solucion(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9);
    Solucion(Solucion& anotherSolucion); // constructor por copia

    // parametros a optimizar:
    int horizontal_ofensivo;
    int horizontal_defensivo;
    int vertical_ofensivo;
    int vertical_defensivo;
    int diagonal_45_ofensivo;
    int diagonal_45_defensivo;
    int diagonal_315_ofensivo;
    int diagonal_315_defensivo;
    int jugada_aleatoria;

};

#endif //AED3_TP3_SOLUCION_H
