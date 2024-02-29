cmake_minimum_required(VERSION 3.0.0)
project(sdl2-game VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()

add_executable(sdl2-game ./src/main.cpp ./src/drevo.cpp ./src/igralec.cpp ./src/ogenj.cpp ./src/sdl-window-and-renderer.cpp ./src/seznamSovraznikov.cpp ./src/seznamStaroselcev.cpp ./src/sovraznik.cpp ./src/staroselec.cpp ./src/verigaOgnjev.cpp ./src/zemljevidDreves.cpp)
target_link_libraries(sdl2-game SDL2main SDL2 SDL2_image)


#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
