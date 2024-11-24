cmake_minimum_required(VERSION 3.10)

project(sqlitedb_testing)
add_executable(${PROJECT_NAME}_open "main.cpp" )
target_link_libraries (${PROJECT_NAME}_open sqlite3 )
