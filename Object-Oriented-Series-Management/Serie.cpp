// ALEJANDRO CHARLES GONZALEZ - A00835903
#include "Serie.h"


Serie::Serie(){
    iD = "000";
    titulo = "TU SERIE FAVORITA";
    genero = "NO";
    duracion = 0;
    calificacion = 0;
    cantEpisodios = 5;
}


Serie::Serie(string _iD,string _titulo, int _duracion,string _genero,int _calificacion,int _cantEpisodios){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
    cantEpisodios = _cantEpisodios;
}


// validar qe el episodio index exista, si no existe index = -1 y retorno epi
// si si existe el episodio index retorno episodios[index]
Episodio Serie::getEpisodio(int &index){

    Episodio epi;

    if (index >= 0 && index < cantEpisodios){
        return episodios[index];
    }
    else {
        index = -1;
        return epi;
    }
}


void Serie::setEpisodio(int &index, Episodio epi){
    // validacion de que exista el episodio index 
    if (index >= 0 && index < cantEpisodios){
        episodios[index] = epi;
    }
    else {
        // no existe este episodio entonces no se pudo cambiar 
        index = -1;
    }
}


void Serie::addEpisodio(Episodio epi){

    // validar que tenga espacio disponible
    if (cantEpisodios < 5){
        episodios[cantEpisodios++] =  epi;        
    }
}


// sumar todas la calificaciones de cada episodio de la serie
// calcula el promedio y lo asignarlo al atributo de la califacion
void Serie::calculaCalificacionPromedio(){

    int acumulador = 0;
    
    //acumula y suma las califiaciones de todos los episodios
    for (int index = 0; index < cantEpisodios; index++){
    acumulador += episodios[index].getCalificacion();
    }
    // calcula el promedio 
    if (cantEpisodios > 0){
        calificacion = acumulador / cantEpisodios;
    } 
    else{
        calificacion = 0;
    }
}


// Borra el ultimo episodio que se añadio - verifica que exista
void Serie::delEpisodio(){

    if (cantEpisodios > 0){
        cantEpisodios--;
    }
}


// Metodos modificadores
void Serie::setID(string _iD){
    iD = _iD;
}


void Serie::setTitulo(string _titulo){
    titulo = _titulo;
}


void Serie::setGenero(string _genero){
    genero = _genero;
}


void Serie::setDuracion(int _duracion){
    duracion = _duracion;
}


void Serie::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}


void Serie::setCantidadEpisodios(int _cantEpisodios){
    cantEpisodios = _cantEpisodios;
}


        // Metodos de acceso
string Serie::getID(){
    return iD;
}


string Serie::getTitulo(){
    return titulo;
}


string Serie::getGenero(){
    return genero;
}


int Serie::getDuracion(){
    return duracion;
}


int Serie::getCalificacion(){
    return calificacion;
}


int Serie::getCantidadEpisodios(){
    return cantEpisodios;
}

string Serie::str(){

    string acumulador = "\n";

    for(int index = 0; index < cantEpisodios; index++){
        acumulador += "E" + to_string(index) +  episodios[index].str() + '\n'; 
    }
    return iD + "," + titulo + "," + to_string(duracion) + ","+ genero + ","
    + to_string(calificacion)+ "," + to_string(cantEpisodios) + acumulador;
} 


