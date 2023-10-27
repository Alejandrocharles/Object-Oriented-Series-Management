// ALEJANDRO CHARLES GONZALEZ - A00835903
#include "Series.h"


// Constructor default que inicializa el atributo de cantidadSeries en 0
Series::Series(){
    cantidadSeries = 0;
}


// Metodo set Cantidad series cambia el valor del atributo por el recibido 
void Series::setCantidadSeries(int _cantidadSeries){
    cantidadSeries = _cantidadSeries;
}


// getCantidadSeries retorna el valor del atributo cantidadseries
int Series::getCantidadSeries(){
    return cantidadSeries;
}


// verifica si hay espacio y añade una nueva serie 
void Series::addSerie(Serie _serie){
    if (cantidadSeries < 100){
        arrSeries[cantidadSeries++] = _serie;
    }
    else{
        cout <<"No se pudo agregar la serie";
    }
}


// Calcula el promedio, para actualizar la calificacion de la serie
void Series::calcularCalPromedioSerie(){
    for(int indexSerie = 0 ; indexSerie < cantidadSeries; indexSerie ++){
        arrSeries[indexSerie].calculaCalificacionPromedio();
    }


// metodo que nos sirve para leer los archivosde prueba un nuestro programa 
}
void Series::leerArchivo(){
    string linea, dato;
    Episodio ep;
    Serie serie;
    ifstream lectura;
    int  index, columna;

    lectura.open("Series22.csv", ios::in);
    index = 0;
    while ( getline(lectura, linea)) // lee una serie
    {
       // cout << linea << endl; //borrar
        stringstream renglon{linea};
        
        columna = 0;
        while (getline(renglon, dato, ',')) // separa los elementos,
        {
            switch (columna++)
            {
                case 0: // iD
                    serie.setID(dato);
                    break;
                case 1: // Titulo
                    serie.setTitulo(dato);
                    break;
                case 2: // duracion
                    serie.setDuracion(stoi(dato));
                    break;
                case 3: // genero
                    serie.setGenero(dato);
                    break;
                case 4: // calificación promedio
                    serie.setCalificacion(stod(dato));
                    break;
                case 5: //cant episodios - inicializar con 0 episodios todas las series
                    serie.setCantidadEpisodios(0);
                    break;
            }
        }// fin while
        
        // para verificar si se guardo correctamente
        // cout << serie.str( ) << endl;  // borrar
        addSerie(serie);
        //cout << "*********  se añadio una serie - Cantidad de series ="  <<  cantidadSeries << endl;
        
    }
    lectura.close();
    
    // LEER LOS EPISODIOS DE LAS SERIES
    index = 0;
    lectura.open("Episodios22.csv", ios::in);
    while ( getline(lectura, linea))
    {
      //  cout << linea << endl; // se borra
        std::stringstream renglon(linea);
        columna = 0;
        while (getline(renglon, dato, ',')) // separar los elementos,
        {
            switch (columna++)
            {
                case 0:
                    index = stoi(dato) - 1;  // a qué serie pertenece?
                    break;
                case 1: // Titulo
                    ep.setTitulo(dato);
                    break;
                case 2: // temporada
                    ep.setTemporada(stoi(dato)); // string to int
                    break;
                case 3: // calificacion
                    ep.setCalificacion(stod(dato)); // string to double
                    break;
            }
        } // al salir de aqui ya se separo toda la línea
        
        arrSeries[index].addEpisodio(ep);
    }
    
    lectura.close();
}


// es una funcion que revisa si existe el genero, si existe retorna el index donde se encuentra
// si no existe lo da de alta en la nueva posicion disponible en del arreglo
// retorna la posicion donde esta dado de alta, y se incrementa la cantidad de generos
int existe_genero(string arrGeneros[], int &cantidad, string genero){
    
    for (int index = 0; index < cantidad; index++)
        if (arrGeneros[index] == genero)
            return index;
    
    arrGeneros[cantidad] = genero;
    
    return cantidad++;
}


// funcion que recorre todo el arreglo con un ciclo for
// despliega la informacion de la serie usando el metodo str()
// incrementa el acumuladro promedio con la calificacion de la serie [index]
// para la serie [index] saca su genero 

void Series::reporteFrecuenciasYpromedioSeries(){

    string generos[100];
    string genero; 

    // declaramos un arreglo para contar las frecuencias, lo inicializamos con 0
    int frecuencias[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int acumPromedio, frecuenciasRelativas; 
    int cantidadGeneros, posicionGenero, acumulador; 

    cantidadGeneros = 0;
    acumPromedio = 0;
    
    cout << "Reporte" << endl;
    
    for (int index = 0; index < cantidadSeries; index++){
        acumPromedio = acumPromedio + arrSeries[index].getCalificacion();
        cout << arrSeries[index].str() << endl;

        posicionGenero = existe_genero(generos, cantidadGeneros, arrSeries[index].getGenero());
        frecuencias[posicionGenero]++;
        }    

        acumulador = 0;

    cout << "Frecuencias"<< endl;

        for(int index = 0; index < cantidadGeneros; index ++){
            frecuenciasRelativas = double(frecuencias[index]) / cantidadSeries * 100;
            acumulador = acumulador + frecuencias[index];

            cout << generos[index] <<","  << frecuencias[index] <<"," << frecuenciasRelativas  << endl;
        }

    cout << "Total="<< cantidadSeries<<endl;

        if (cantidadSeries > 0)
            cout << "Promedio=" << acumPromedio / cantidadSeries << endl;
        else{
            cout << "No se puede calcular la calificación promedio \n";
        }

        // verificar si ese genero existe en el arreglo de generos si no existe se da de alta y se incrementa el contador de cantidadGeneros
        // Una vez que sabemos la posición donde esta ese genero en el arreglo de generos se incrementa la misma posicion pero del arreglo
        // de frecuencia

        // al salir de ese ciclo se tendra:
        // el arreglo de los generos(sin repetirse)
        // el arreglo de las frecuencias ya tendra calculado la cantidad de veces que se repite cada genero

}
