// ALEJANDRO CHARLES GONZALEZ - A00835903
#ifndef Series_hpp
#define Series_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Serie.h"

using namespace std;


class Series{

    private:
        Serie arrSeries[100];
        int cantidadSeries;

    public:
        Series();

        void setCantidadSeries(int _cantidadSeries);
        int getCantidadSeries();

        void addSerie(Serie _serie);
        void calcularCalPromedioSerie();
        void leerArchivo();
        void reporteFrecuenciasYpromedioSeries();
        

};
#endif // Series_hpp