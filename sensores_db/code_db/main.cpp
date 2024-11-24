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

   /* abrir database */
   rc = sqlite3_open("sensor.db", &db);
   
   if( rc != 0 ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(1);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* crear tabla*/
   sqlstr = "CREATE TABLE IF NOT EXISTS sensor (id_medida INTEGER PRIMARY KEY NOT NULL," \
            "Fecha TEXT NOT NULL, Temperatura REAL NOT NULL, Humedad REAL NOT NULL, Humedad_Suelo REAL NOT NULL," \
            "velocidad REAL NOT NULL, direccion_viento REAL NOT NULL, precipitacion REAL NOT NULL," \
            "intensidad_luz REAL NOT NULL);";

   rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return(3);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }

   std::srand(std::time(0));
   int day = 23, month = 11, year = 2024;   //fecha inicial "23/11/2024"
   int hour = 10, minute = 40, second = 0; //hora inicial "10:40:00"

//--------------------------------------------------------------------------------------
   
   // Generar 100 los registros
   
   for (int i = 0; i < 100; ++i) {

   float temp = (-100 + (std::rand() % 450)) / 10.0;   // Temperatura entre -10.00 y 45.00 °C
   float hume = ((std::rand() % 1001)) / 10.0;         // Humedad entre 0.0 y 100.0 %
   float hume_s = (std::rand() % 1001) / 10.0;         // Humedad del suelo entre 0.0 y 100.0 %
   float vel = (std::rand() % 400) / 10.0;             // Velocidad entre 0.0 y 40.0 m/s
   float dir_vel = (-1800 + (std::rand() % 3600)) / 10.0; // Dirección del viento entre -180.0 y 180.0 grados
   float prec = (std::rand() % 2000) / 10.0;           // Precipitación entre 0.0 y 200.0 mm
   float int_Luz = (std::rand() % 400001) / 10.0;      // Intensidad de luz entre 0.0 y 4000.0 lumenes

//--------------------------------------------------------------------------------------      
      // Incrementar la fecha y hora
      second += 5;
      if (second >= 60) {
         second = 0;
         minute++;
         if (minute >= 60) {
            minute = 0;
            hour++;
            if (hour >= 24) {
               hour = 0;
               day++;
            }
         }
      }
      string fecha = to_string(day) + "/" +
                     to_string(month) + "/" +
                     to_string(year) + " " +
                     to_string(hour) + ":" +
                     (minute < 10 ? "0" : "") + to_string(minute) + ":" +
                     (second < 10 ? "0" : "") + to_string(second);

//--------------------------------------------------------------------------------------

      // Crear la consulta SQL con los valores generados
      sqlstr = "INSERT INTO sensor (Fecha, Temperatura, Humedad, Humedad_Suelo, velocidad, direccion_viento, precipitacion, intensidad_luz) "  \
               "VALUES ('" + fecha + "', " + to_string(temp) + ", " + to_string(hume) + ", " + to_string(hume_s) + ", " \
               + to_string(vel) + ", " + to_string(dir_vel) + ", " + to_string(prec) + ", " + to_string(int_Luz) + ");";

      // Ejecutar la consulta SQL
      rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
      if( rc != SQLITE_OK ){
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         break;
      } else {
         fprintf(stdout, "Record %d created successfully\n", i + 1);
      }
   }
//--------------------------------------------------------------------------------------

   sqlite3_close(db);
   fprintf(stdout, "Database closed\n");

   return 0;
}