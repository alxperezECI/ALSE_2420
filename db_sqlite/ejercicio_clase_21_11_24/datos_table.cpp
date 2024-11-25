#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   string sql_sensores, sql_promedio;
   float a = 0., c= 0.;
   int b = 0, g = 0;
   int d = 0, e = 0, f = 0;

   /* Open database */
   rc = sqlite3_open("registro_sensores.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   stringstream x;
   for (int j = 0; j < 100; j++ )
   {
      /*Datos a insertar en los registros*/
      /*-10 a 45*/
      a = -10. + rand() % 56;
      /*0 a 100*/
      b = 0 + rand() % 100;
      g = 0 + rand() % 100;
      /*0 a 40*/
      c = 0. + rand() % 40;
      /*-180 a 180*/
      d = -180 + rand() % 180;
      /*0 a 200*/
      e = 0 + rand() % 200;
      /*0 a 4000*/
      f = 0 + rand() % 4000;
      x << "INSERT INTO sensores (Temperatura, Humedad, Humedad_suelo, Velocidad_viento, Direccion_vient, Precipitación, intensidad_luz)" 
      <<"VALUES (" << a <<","<< b <<","<< g <<","<< c <<","<< d <<","<< e <<","<< f << ");";
   }
   sql_sensores = x.str();

   /* Create SQL statement (Segunda tabla:)*/
   stringstream y;
   for (int j = 1; j < 100; j+= 12 )
   {
      y << "INSERT INTO promedio_senso (id_min, Temperatura, Humedad, Humedad_suelo, Velocidad_viento, Direccion_vient, Precipitación, intensidad_luz) "
      << "VALUES ("<< j << ", "
      << "(SELECT AVG(Temperatura) FROM sensores WHERE id_seg BETWEEN "<< j << " AND " << (j+12)<<"), "
      << "(SELECT AVG(Humedad) FROM sensores WHERE id_seg BETWEEN "<< j <<" AND "<< (j+12)<<"), "
      << "(SELECT AVG(Humedad_suelo) FROM sensores WHERE id_seg BETWEEN "<< j <<" AND "<< (j+12)<<"), "
      << "(SELECT AVG(Velocidad_viento) FROM sensores WHERE id_seg BETWEEN "<< j <<" AND "<< (j+12)<<"), "
      << "(SELECT AVG(Direccion_vient) FROM sensores WHERE id_seg BETWEEN "<< j <<" AND "<< (j+12)<<"), "
      << "(SELECT AVG(Precipitación) FROM sensores WHERE id_seg BETWEEN "<< j <<" AND "<< (j+12)<<"), "
      << "(SELECT AVG(intensidad_luz) FROM sensores WHERE id_seg BETWEEN "<< j <<" AND "<< (j+12)<<"));";
   }
   sql_promedio = y.str();
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql_sensores.c_str(), 0, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error(sensores): %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   rc = sqlite3_exec(db, sql_promedio.c_str(), 0, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error(promedio_senso): %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }

   sqlite3_close(db);

   return 0;
}
