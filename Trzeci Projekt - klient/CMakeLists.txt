cmake_minimum_required(VERSION 3.17)
project(Trzeci_Projekt___klient C)

set(CMAKE_C_STANDARD 99)

add_executable(Trzeci_Projekt___klient main.c)
#target_link_libraries(${Trzeci_Projekt___klient} m pthread rt)  #Dlaczego nie działa?