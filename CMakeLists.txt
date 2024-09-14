cmake_minimum_required(VERSION 3.10)
project(P2PFileSharing)

set(CMAKE_CXX_STANDARD 17)

# Manually specify paths for libpqxx
set(PQXX_INCLUDE_DIR /opt/homebrew/opt/libpqxx/include)
set(PQXX_LIBRARY_DIR /opt/homebrew/opt/libpqxx/lib)

# Find the libpqxx library
find_library(PQXX_LIB pqxx PATHS ${PQXX_LIBRARY_DIR})

# Find nlohmann-json (installed via Homebrew)
find_package(nlohmann_json 3.2.0 REQUIRED)

# Add the executable and link libraries
add_executable(P2PFileSharing 
    src/main.cpp 
    src/config_manager.h  # Replace .h with the actual .cpp file
    src/database/postgresql_database.h  # Replace .h with the actual .cpp file
)

# Include directories for pqxx and nlohmann-json (nlohmann-json path for Homebrew)
target_include_directories(P2PFileSharing PRIVATE ${PQXX_INCLUDE_DIR} /opt/homebrew/include)

# Link the libraries (libpqxx and nlohmann-json)
target_link_libraries(P2PFileSharing PRIVATE ${PQXX_LIB} nlohmann_json::nlohmann_json)
