//Desarrollado por Arianne Patiño y Jose Velasco
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName){ //Función callback para mostrar los datos de los promedios en pantalla
   
   for(int i = 0; i<argc; i++){
      cout << (argv[i] ? argv[i] : "NULL" )<< "       |       ";  //Espacios dejados con el fin de facilitar la visualización en la consola   
   }
   cout << endl;
   
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   const char* data;
   char *zErrMsg = 0;
   int rc;
   std::stringstream sql;
   std::stringstream sqlstr;

   //Se abre la base de datos, en este caso se llama "sensores.db"
   rc = sqlite3_open("sensores.db", &db);
   
   if( rc != 0 ) {
      fprintf(stderr, "No fue posible abrir la base de datos.: %s\n", sqlite3_errmsg(db));
      return(1);
   } else {
      fprintf(stdout, "Apertura de base de datos correcta.\n");
   }

   //Se crea la primera tabla llamada 'sensor'

   sqlstr << "CREATE TABLE IF NOT EXISTS sensor (Tiempo REAL NOT NULL, Temperatura REAL NOT NULL,"<<
      "Humedad_ambiente REAL NOT NULL, Humedad_suelo REAL NOT NULL,"<<
      "Velocidad_viento REAL NOT NULL, Direccion_viento REAL NOT NULL,"<<
      "Precipitacion REAL NOT NULL, Intensidad_luz INTEGER NOT NULL);";

   //Se ejecuta la instrucción SQL
   rc = sqlite3_exec(db, sqlstr.str().c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "Error SQL: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
   } else {
      fprintf(stdout, "Tabla 'sensor' creada correctamente.\n");
   }

   sqlstr.str(std::string());

// Se crea la segunda tabla para los promedios llamada 'promedio'

   sqlstr << "CREATE TABLE IF NOT EXISTS promedio (Tiempo_minuto REAL NOT NULL, Temperatura REAL NOT NULL,"<<
   "Humedad_ambiente REAL NOT NULL, Humedad_suelo REAL NOT NULL,"<<
   "Velocidad_viento REAL NOT NULL, Direccion_viento REAL NOT NULL,"<<
   "Precipitacion REAL NOT NULL, Intensidad_luz INTEGER NOT NULL);";

   //Se ejecuta la instrucción SQL
   rc = sqlite3_exec(db, sqlstr.str().c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "Error SQL: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
   } else {
      fprintf(stdout, "Tabla 'promedio' creada correctamente.\n");
   }

//Se realiza el llenado de la tabla sensor con 100 registros de datos en los rangos requeridos utilizando la funcion rand()

   for (int i = 0; i < 100; ++i){
         sql.str(std::string());
         sql <<"INSERT INTO sensor (Tiempo, Temperatura, " <<
         "Humedad_ambiente, Humedad_suelo, Velocidad_viento, "<<
         "Direccion_viento, Precipitacion, Intensidad_luz) VALUES (' " <<
            5*i <<" ',' "<<                  //Tiempo cada 5 segundos, haciendo uso del iterador
           -10+(rand()%56) <<" ',' "<<       //Temperatura -10 - 45°C
            (rand()%100) <<" ',' "<<         //Humedad 0 - 100%
            (rand()%100) <<" ',' "<<         //Humedad del suelo 0 - 100%
            (rand()%41) <<" ',' "<<          //Velocidad del viento 0 - 40 m/s
            -180+(rand()%361) <<" ',' "<<    //Dirección del viento -180 - 180 °Norte
            (rand()%201) <<" ',' "<<         //Precipitación 0 - 200mm
            (rand()%4001) <<"'); ";          //Intensidad de luz 0 - 4000 lumenes

      //Se ejecuta la instrucción SQL
        rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "Error SQL: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "Registro #%i creado correctamente\n",i+1); //Se investigó y actualizó la función fprintf de C para imprimir texto en el flujo de salida con el fin de verificar el estado de la creación de cada registro en la consola.
               
        }     
    }

   //Se realiza el llenado de la tabla promedio, con los promedios de los datos, agrupados por minuto.

   sqlstr.str(std::string());
   sqlstr << "INSERT INTO promedio (Tiempo_minuto, Temperatura, Humedad_ambiente,"
   <<" Humedad_suelo, Velocidad_viento, Direccion_viento, Precipitacion, Intensidad_luz) " 
   << "SELECT CAST(Tiempo/60 AS INTEGER) AS Tiempo_minuto, " //Se divide el valor de la columna tiempo de la tabla con los datos de los sensores que está en segundos entre 60 para convertirlo en minutos, con la función cast se asegura que el valor sea un numero entero, descartando los decimales, este valor se guarda en la columna Tiempo_minuto de la tabla promedios, se utiliza la instrucción "AS" debido a que en la ultima linea se van a agrupar las filas por el parametro Tiempo_minuto y la instruccion necesita encontrar esa columna.
   << "ROUND(AVG(Temperatura),1), ROUND(AVG(Humedad_ambiente),1), ROUND(AVG(Humedad_suelo),1), ROUND(AVG(Velocidad_viento),1), " //La función AVG calcula los promedios
   << "ROUND(AVG(Direccion_viento),1), ROUND(AVG(Precipitacion),1), ROUND(AVG(Intensidad_luz),1) "
   <<"FROM sensor " //Se indica que los datos que se van a promediar vienen de la tabla sensor.
   <<"Group BY Tiempo_minuto;"; //Se utiliza Group BY para agrupar las filas con valores iguales en la columna Tiempo_minuto.
   //Se realizó uso de la instrucción ROUND con el fin de redondear los datos de los promedios a un decimal para facilitar la visualización de los datos en la consola.

   //Se ejecuta la instrucción SQL
   rc = sqlite3_exec(db, sqlstr.str().c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error SQL: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Los promedios se calcularon correctamente y se agregaron a la tabla 'promedio'.\n");
    }


   //Se muestran los promedios de cada minuto en pantalla
   
    sqlstr.str(std::string());
    sqlstr << "SELECT Tiempo_minuto, Temperatura, Humedad_ambiente, Humedad_suelo, Velocidad_viento, Direccion_viento, Precipitacion, Intensidad_luz FROM promedio;";
   cout << "Tiempo (min)|Temperatura (°C)|Humedad ambiente(%)|Humedad suelo(%)|Velocidad viento(m/s)|Dirección viento(°N)|Precipitación(mm)|Intensidad luz(lumenes)" << endl;

   //Se ejecuta la instrucción SQL, haciendo uso de la función callback
    rc = sqlite3_exec(db, sqlstr.str().c_str(), callback, (void*)data, &zErrMsg);
   
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "Error SQL: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Datos mostrados satisfactoriamente.\n");
   }

   sqlite3_close(db);
   return 0;
} 