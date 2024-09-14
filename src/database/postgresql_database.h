// src/database/postgresql_database.h
#ifndef POSTGRESQL_DATABASE_H
#define POSTGRESQL_DATABASE_H

#include <iostream>
#include <pqxx/pqxx>

class PostgreSQLDatabase {
public:
    PostgreSQLDatabase(const std::string& host, const std::string& port, const std::string& dbname,
                       const std::string& user, const std::string& password)
        : host(host), port(port), dbname(dbname), user(user), password(password) {}

    bool connect() {
        try {
            std::string conn_str = "host=" + host + " port=" + port + " dbname=" + dbname + 
                                   " user=" + user + " password=" + password;
            connection = new pqxx::connection(conn_str);
            if (connection->is_open()) {
                std::cout << "Successfully connected to the database: " << dbname << std::endl;
                return true;
            }
        } catch (const std::exception& e) {
            std::cerr << "Database connection error: " << e.what() << std::endl;
        }
        return false;
    }

    ~PostgreSQLDatabase() {
        // No need to call disconnect, the connection will be closed when the object is destroyed
        if (connection != nullptr && connection->is_open()) {
            std::cout << "Closing connection to the database." << std::endl;
        }
        delete connection;
    }

private:
    std::string host, port, dbname, user, password;
    pqxx::connection* connection = nullptr;
};

#endif
