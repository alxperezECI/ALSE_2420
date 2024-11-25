#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   string sqlstr;

   /* Open database */
   rc = sqlite3_open("registro_sensores.db", &db);
   
   if( rc != 0 ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(1);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sqlstr = "CREATE TABLE IF NOT EXISTS sensores (id_seg INTEGER PRIMARY KEY NOT NULL," \
      "Temperatura REAL NOT NULL, Humedad INT NOT NULL," \
      "Humedad_suelo INT NOT NULL, Velocidad_viento REAL NOT NULL"\
      ", Direccion_vient INT NOT NULL, Precipitación INT NOT NULL, intensidad_luz INT NOT NULL"\
      ");";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }

   /* Create SQL statement */
   sqlstr = "CREATE TABLE IF NOT EXISTS promedio_senso (id_min INTEGER PRIMARY KEY NOT NULL," \
      "Temperatura REAL NOT NULL, Humedad INT NOT NULL," \
      "Humedad_suelo INT NOT NULL, Velocidad_viento REAL NOT NULL"\
      ", Direccion_vient INT NOT NULL, Precipitación INT NOT NULL, intensidad_luz INT NOT NULL"\
      ");";

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
   return 0;
}