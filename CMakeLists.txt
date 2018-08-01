# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.10.1)
project (CGen)

set(BOOST_ROOT D:/local/boost_1_66_0)

find_package(Boost 1.66.0 COMPONENTS regex)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(CGen Main.hpp Main.cpp CTMLCore.hpp CTMLGraph.hpp CTMLLinker.hpp CTMLGraph.cpp CTMLCompiler.hpp CTMLCore.cpp CTMLCompiler.cpp CTMLLinker.cpp CTMLManager.hpp CTMLManager.cpp FileReader.hpp FileReader.cpp FileSystem.hpp FileSystem.cpp)

target_link_libraries(CGen ${Boost_LIBRARIES})