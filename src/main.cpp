#include <iostream>
#include <thread>   // Required for std::this_thread::sleep_for
#include <chrono>   // Required for std::chrono::seconds
#include "config_manager.h"  // Assuming this includes the database logic
#include "database/postgresql_database.h"

int main(int argc, char** argv) {
    // Load config and connect to the database
    std::string environment = "development";  // Default environment

    // Parse command-line arguments to get the environment
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--env" && i + 1 < argc) {
            environment = argv[++i];
        }
    }

    ConfigManager configManager;
    if (!configManager.loadConfig(environment)) {
        std::cerr << "Failed to load configuration for environment: " << environment << "\n";
        return 1;
    }

    std::cout << "Running in " << environment << " environment." << std::endl;

    PostgreSQLDatabase db(configManager.dbHost, configManager.dbPort, configManager.dbName, configManager.dbUser, configManager.dbPassword);
    if (!db.connect()) {
        std::cerr << "Failed to connect to PostgreSQL database\n";
        return 1;
    }
    std::cout << "Connected to PostgreSQL database successfully!\n";

    // Keep the program running
    while (true) {
        // Simulate program activity or add logic here
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Sleep to prevent high CPU usage
    }

    return 0;
}
