// ALEJANDRO CHARLES GONZALEZ - A00835903
//  main.cpp
//  Proyecto

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Serie.h"
#include "Episodio.h"
#include "Series.h"

using namespace std;


void leerSerie(std::string &_iD, std::string &_titulo, int &_duracion, std::string &_genero, int &_calificacion, int &_cantEpisodios){
    //cout << "Ingresa el id:";
    cin >> _iD;
    
    //cout << "Ingresa el titulo:";
    cin.ignore();
    getline(cin, _titulo);
    
    //cout << "Ingresa la duracion en minutos:";
    cin >> _duracion;
    
   // cout << "Ingresa el genero:";
    cin >> _genero;
    
   // cout << "Ingresa la calificación:";
    cin >> _calificacion;
    
    //cout << "Ingresa la cantidad de episodios:";
    cin >> _cantEpisodios;
}

void leerEpisodio(std::string &_titulo, int &_temporada, int &_calificacion){
    //cout << "Ingresa titulo del Episodio:";
    cin.ignore();
    getline(cin, _titulo);
   //cout << "Ingresa temporada:";
    cin >> _temporada;
   // cout << "Ingresa calificación:";
    cin >> _calificacion;
}

int menu( ){ //: Función que despliega el siguiente menú de opciones y lee y retorna el valor leído
    int opcion;
    
    cin >> opcion;
    return opcion;
}

int main() {
    // 1º Declaración de objetos de las generos creadas, llamar a los constructores con parámatros
    // Titulo temporada calificacion
    Episodio episodio1{"GRADUACION", 1, 100}; // calificacion, episodios
    Serie serie1_22{"TEC","ITESM", 1000,"APRENDIZAJE",0,0};
    Series negocio;
    
    // 2º Declaración de variables
    int  index, opcion, temporada, duracion, calificacion, cantEpisodios;
    std::string iD,titulo,genero;

    // 3º Inicializar la vccc antes del ciclo
    opcion = menu();
    
    // 4º Incluir la vccc dentro de la condicion del ciclo
    while (opcion != 0){
        
        // 5º Determinar que hacer en cada opcion
        switch (opcion) {
            case 1:
                leerSerie(iD, titulo, duracion, genero, calificacion, cantEpisodios);
                serie1_22 = Serie(iD, titulo, duracion, genero, calificacion, cantEpisodios);
                break;
            case 2:
                //  cout << "Ingresa el nuevo id:";
                cin >> iD;
                serie1_22.setID(iD);
                break;
            case 3:
                //  cout << "Ingresa titulo:";
                cin.ignore();
                getline(cin, titulo);
                serie1_22.setTitulo(titulo);
                break;
            case 4:
                //  cout << "Ingresa duracion en minutos:";
                cin >> duracion;
                serie1_22.setDuracion(duracion);
                break;
            case 5:
                //   cout << "Ingresa genero:";
                cin >> genero;
                serie1_22.setGenero(genero);
                break;
            case 6:
                //  cout << "Ingresa calificación:";
                cin >> calificacion;
                serie1_22.setCalificacion(calificacion);
                break;
            case 7:
                //   cout << "Ingresa cantidad de episodios:";
                cin >> cantEpisodios;
                serie1_22.setCantidadEpisodios(cantEpisodios);
                break;
            case 8:
                // Desplegar la información de la serie
                cout << serie1_22.str() << endl;
                break;
            case 10:
                leerEpisodio(titulo, temporada, calificacion);
                episodio1 = Episodio(titulo, temporada, calificacion);
                break;
            case 11: // Desplegar el objeto de la generos Episodio
                cout << episodio1.str() << endl;
                break;
            case 12: // setTitulo
                cin.ignore();
                getline(cin, titulo);
                episodio1.setTitulo(titulo);
                break;
            case 13: // setTemporada
                cin >> temporada;
                episodio1.setTemporada(temporada);
                break;
            case 14: // setCalificacion
                cin >> calificacion;
                episodio1.setCalificacion(calificacion);
                break;
            case 15: // getTitulo
                cout << episodio1.getTitulo() << endl;
                break;
            case 16: // getTemporada
                cout << episodio1.getTemporada() << endl;
                break;
            case 17: // getCalificacion
                cout << episodio1.getCalificacion() << endl;
                break;
            case 18: //
                // se pide el episodio 1
                serie1_22.addEpisodio(Episodio{"Pozole Verde", 2, 100});// instancia anonima de la generos Episodio
                serie1_22.addEpisodio(Episodio{"Mangu Dominicano", 3, 100});
                serie1_22.addEpisodio(Episodio{"Machacado", 4, 100});
                break;
            case 19: //
                serie1_22.delEpisodio();
                break;
            case 20: //
                cin >> index;
                episodio1 = serie1_22.getEpisodio(index);
                if (index == -1){
                    cout << "No existe el episodio\n";
                }
                else{
                    cout << episodio1.str() << endl;
                }
                break;
            case 21: //
                serie1_22.calculaCalificacionPromedio();
                cout << serie1_22.str() << endl;
                break;
            case 22: //
                negocio.leerArchivo();
                break;
            case 23: //
                negocio.calcularCalPromedioSerie();
                negocio.reporteFrecuenciasYpromedioSeries();
                break;
            case 24: //
                cout << negocio.getCantidadSeries() << endl;
                negocio.addSerie(serie1_22);
                cout << negocio.getCantidadSeries() << endl;
                break;
            case 25: //
                negocio.reporteFrecuenciasYpromedioSeries();
                break;
            default:
                break;
        }
        // 6º Actualizar la vccc dentro del ciclo
        opcion = menu();

    }
    return 0;
}

