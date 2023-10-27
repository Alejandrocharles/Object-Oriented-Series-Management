// ALEJANDRO CHARLES GONZALEZ - A00835903
#ifndef Serie_h
#define Serie_h

#include "Episodio.h"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


class Serie{

    private:

        string iD;
        string titulo;
        string genero;  //{"innovacion","accion","documental"};
        int duracion;
        int calificacion;
        int cantEpisodios;
        Episodio episodios[5];
        

    public:

        //metodo constructor de generos
        Serie();
        Serie(string _iD,string _titulo, int _duracion,string _genero,int _calificacion,int _cantEpisodios);

        //metodo modificador que cambia el valor de los atributos
        void setID(string _iD);
        void setTitulo(string _titulo);
        void setGenero(string _genero);
        void setDuracion(int _duracion);
        void setCalificacion(int _calificacion);
        void setCantidadEpisodios(int _cantEpisodios);

        //metodo de acceso que retorna el valor del atributo
        string getID();
        string getTitulo();
        string getGenero();
        int getDuracion();
        int getCalificacion();
        int getCantidadEpisodios();
        
        Episodio getEpisodio(int &index);
        void setEpisodio(int &index, Episodio epi);
        void addEpisodio(Episodio epi);
        void calculaCalificacionPromedio();
        void delEpisodio();

        //funcionalidad
        string str();
};
#endif /* Serie_h */