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
   int rc,rc2;
   string sqlstr,sqlstr2;

   /* abrir database */
   rc = sqlite3_open("sensor.db", &db);
   
   if( rc != 0 ) {
      fprintf(stderr, "Can't open sensor database: %s\n", sqlite3_errmsg(db));
      return(1);
   } else {
      fprintf(stdout, "Opened sensor database successfully\n");
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
      fprintf(stdout, "Sensor table created successfully\n");
   }

//---------tabla promedio-----------------------------------------------------------------------
   // crear tabla
   sqlstr = "CREATE TABLE IF NOT EXISTS promedio (id_medida INTEGER PRIMARY KEY NOT NULL," \
            "Fecha TEXT NOT NULL, Temperatura REAL NOT NULL, Humedad REAL NOT NULL, Humedad_Suelo REAL NOT NULL," \
            "velocidad REAL NOT NULL, direccion_viento REAL NOT NULL, precipitacion REAL NOT NULL," \
            "intensidad_luz REAL NOT NULL);";

   rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return(3);
   } else {
      fprintf(stdout, "Promedio_sen table created successfully\n");
   }


//--------------------------------------------------------------------------------------

   std::srand(std::time(0));
   int day = 23, month = 11, year = 2024; //fecha inicial "23/11/2024"
   int hour = 10, minute = 40, second = 0; //hora inicial "10:40:00"
    int cont_registros = 0;
//--------------------------------------------------------------------------------------
    float promedio_temp = 0;
    float promedio_hume = 0;
    float promedio_hume_s = 0;
    float promedio_vel = 0;
    float promedio_dir_vel = 0;
    float promedio_prec = 0;
    float promedio_int_Luz = 0;


   // Generar 100 los registros
   
   for (int i = 0; i < 100; ++i) {

      int temp = -10 + (std::rand() % 46); // Temperatura entre -10 y 45 °C
      int hume = (std::rand() % 101); // Humedad entre 0 y 100 %
      int hume_s = (std::rand() % 101); // Humedad del suelo entre 0 y 100 %
      int vel = (std::rand() % 41); // Velocidad entre 0.00 y 40 m/s
      int dir_vel = -180 + (std::rand() % 361); // Dirección del viento entre -180 y 180 grados
      int prec = (std::rand() % 201);       // Precipitación entre 0 y 200 mm
      int int_Luz = (std::rand() % 40001) ;     // Intensidad de luz entre 0 y 4000 lumenes

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
    // promedio de los valores
    promedio_temp = promedio_temp + temp;
    promedio_hume = promedio_hume + hume;
    promedio_hume_s = promedio_hume_s + hume_s;
    promedio_vel = promedio_vel + vel;
    promedio_dir_vel = promedio_dir_vel + dir_vel;
    promedio_prec = promedio_prec + prec;
    promedio_int_Luz = promedio_int_Luz + int_Luz;
    cont_registros++;

    // si ya se tienen 12 registros se calcula el promedio y se inserta en la tabla promedio. (60seg / 5seg = 12)
    if (cont_registros == 12){
        sqlstr2 = "INSERT INTO promedio (Fecha, Temperatura, Humedad, Humedad_Suelo, velocidad, direccion_viento, precipitacion, intensidad_luz) "  \
               "VALUES ('" + fecha + "', " + to_string(promedio_temp/cont_registros) + ", " + to_string(promedio_hume/cont_registros) + ", " + to_string(promedio_hume_s/cont_registros) + ", " \
               + to_string(promedio_vel/cont_registros) + ", " + to_string(promedio_dir_vel/cont_registros) + ", " + to_string(promedio_prec/cont_registros) + ", " + to_string(promedio_int_Luz/cont_registros) + ");";
    
      // Ejecutar la consulta SQL
      rc2 = sqlite3_exec(db, sqlstr2.c_str(), 0, 0, &zErrMsg);
   
      if( rc2 != SQLITE_OK ){
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         break;
      } else {
         fprintf(stdout, "Average record created successfully\n");
      }
        //reiniciar variables
        cont_registros = 0;
        promedio_temp = 0;
        promedio_hume = 0;
        promedio_hume_s = 0;
        promedio_vel = 0;
        promedio_dir_vel = 0;
        promedio_prec = 0;
        promedio_int_Luz = 0;
    }
   
   }

// Consultar todos los promedios de la tabla "promedio"
sqlstr = "SELECT * FROM promedio;";
sqlite3_stmt *stmt;

// Preparar la consulta SQL
rc = sqlite3_prepare_v2(db, sqlstr.c_str(), -1, &stmt, 0);
if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
} else {
    // Imprimir encabezado
    printf("Promedios guardados en la base de datos:\n");
    printf("ID | Fecha                 | Temperatura | Humedad | Humedad Suelo | Velocidad | Direccion Viento | Precipitacion | Intensidad Luz\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    // Iterar sobre los resultados de la consulta
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* fecha = sqlite3_column_text(stmt, 1);
        float temp = sqlite3_column_double(stmt, 2);
        float hume = sqlite3_column_double(stmt, 3);
        float hume_suelo = sqlite3_column_double(stmt, 4);
        float vel = sqlite3_column_double(stmt, 5);
        float dir_vel = sqlite3_column_double(stmt, 6);
        float prec = sqlite3_column_double(stmt, 7);
        float luz = sqlite3_column_double(stmt, 8);

        // Imprimir cada fila
        printf("%2d | %-20s | %11.2f | %7.2f | %13.2f | %9.2f | %17.2f | %13.2f | %14.2f\n",
               id, fecha, temp, hume, hume_suelo, vel, dir_vel, prec, luz);
    }
}

// Finalizar la consulta SQL
sqlite3_finalize(stmt);

//-- fin tabla sensor --------------------------------------------------------------------------------

   sqlite3_close(db);
   fprintf(stdout, "Database closed\n");

   return 0;
}