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

   /* Create table if it doesn't exist */
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
   int hour = 10, minute = 40; //hora inicial "10:40"

//--------------------------------------------------------------------------------------
   
   // Generar 100 los registros
   
   for (int i = 0; i < 100; ++i) {

      float temp = -10 + (std::rand() % 45);   // Temperatura entre -10.00 y 45.00 °C
      float hume = (std::rand() % 101);                 // Humedad entre 0 y 100 %
      float hume_s = (std::rand() % 101);               // Humedad del suelo entre 0 y 100 %
      float vel = (std::rand() % 40);         // Velocidad entre 0.00 y 40.00 m/s
      float dir_vel = -180 + (std::rand() % 360);       // Dirección del viento entre -180 y 180 grados
      float prec = (std::rand() % 200);       // Precipitación entre 0.00 y 200.00 mm
      float int_Luz = (std::rand() % 40001) ;     // Intensidad de luz entre 0.0 y 4000.0 lumenes

//--------------------------------------------------------------------------------------      
      // Incrementar la fecha y hora
      minute += 5;
      if (minute >= 60) {
         minute = 0;
         hour++;
         if (hour >= 24) {
            hour = 0;
            day++;
            if (day > 31) {
               day = 1;
               month++;
               if (month > 12) {
                  month = 1;
                  year++;
               }
            }
         }
      }

      string fecha = to_string(day) + "/" +
                     to_string(month) + "/" +
                     to_string(year) + " " +
                     to_string(hour) + ":" +
                     (minute < 10 ? "0" : "") + to_string(minute);

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
         break; // Si hay un error, detener la ejecución
      } else {
         fprintf(stdout, "Record %d created successfully\n", i + 1);
      }
   }
//--------------------------------------------------------------------------------------

   sqlite3_close(db);
   fprintf(stdout, "Database closed\n");

   return 0;
}
