project(DA2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA2
        src/main.cpp src/menu.cpp src/CSVReader.cpp header/CSVReader.h header/GraphAM.h src/GraphAM.cpp header/algorithms.h src/algorithms.cpp src/vertexEdge.cpp)
