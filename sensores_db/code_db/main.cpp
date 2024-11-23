#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   string sqlstr;

   /* Open database */
   rc = sqlite3_open("sensor.db", &db);
   
   if( rc != 0 ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(1);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sqlstr = "CREATE TABLE IF NOT EXISTS sensor (id_medida INTEGER PRIMARY KEY NOT NULL," \
      "Fecha TEXT NOT NULL, Temperatura REAL NOT NULL, Humedad REAL NOT NULL, Humedad_Suelo REAL NOT NULL," \
      "velocidad REAL NOT NULL, direccion_viento REAL NOT NULL, precipitacion REAL NOT NULL," \
      "intensidad_luz REAL NOT NULL);";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (3);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }

   sqlite3_close(db);
   fprintf(stdout, "cerrado\n");
//------------------------------------------------------------------------------------
   
   string sql;

   /* Open database */
   rc = sqlite3_open("sensor.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
    std::srand(std::time(0));

   for (int i=0; i<100; ++i){
    float temp= std::rand();
    float hume;
    float hume_s;
    float vel;
    float dir_vel;
    float prec;
    float int_Luz;
    sql = "INSERT INTO sensor (Fecha, Temperatura, Humedad, Humedad_Suelo,velocidad,direccion_viento,precipitacion,intensidad_luz) "  \
         "VALUES ('10:47',temp,hume,hume_s,vel,dir_vel,prec,int_Luz); ";
   }
   //sql = "INSERT INTO sensor (Fecha, Temperatura, Humedad, Humedad_Suelo,velocidad,direccion_viento,precipitacion,intensidad_luz) "  \
         "VALUES ('10:47',35,40.5,50,54,52,2,60); " \
         "INSERT INTO sensor (Fecha, Temperatura, Humedad, Humedad_Suelo,velocidad,direccion_viento,precipitacion,intensidad_luz) "  \
         "VALUES ('10:48',35,40.5,55,24,55,3,6); " \
	     "INSERT INTO sensor (Fecha, Temperatura, Humedad, Humedad_Suelo,velocidad,direccion_viento,precipitacion,intensidad_luz) "  \
         "VALUES ('10:49',25,40.5,20,84,52,4,80); " \
	     "INSERT INTO sensor (Fecha, Temperatura, Humedad, Humedad_Suelo,velocidad,direccion_viento,precipitacion,intensidad_luz) "  \
         "VALUES ('10:50',50,40.5,30,4,56,5,50); " ;

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }

   sqlite3_close(db);
   fprintf(stdout, "cerrado\n");

   return 0;
}
