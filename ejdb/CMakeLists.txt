cmake_minimum_required(VERSION 3.10)
project(sensor_db)
add_executable(${PROJECT_NAME}_open "main.cpp" )
target_link_libraries (${PROJECT_NAME}_open sqlite3 )
