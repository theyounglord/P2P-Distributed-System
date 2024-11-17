#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <boost/asio.hpp>

class TCPConnection {
public:
    TCPConnection(const std::string& host, const std::string& port)
        : host_(host), port_(port), io_context_(), socket_(io_context_) {}

    bool connect() {
        try {
            boost::asio::ip::tcp::resolver resolver(io_context_);
            boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host_, port_);
            boost::asio::connect(socket_, endpoints);
            std::cout << "TCP connection established with " << host_ << ":" << port_ << std::endl;
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error connecting to " << host_ << ":" << port_ << " - " << e.what() << std::endl;
            return false;
        }
    }

    bool send(const std::string& message) {
        try {
            boost::asio::write(socket_, boost::asio::buffer(message));
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error sending message: " << e.what() << std::endl;
            return false;
        }
    }

    std::string receive() {
        try {
            boost::asio::streambuf buffer;
            boost::asio::read_until(socket_, buffer, "\n");
            std::istream stream(&buffer);
            std::string received_message;
            std::getline(stream, received_message);
            return received_message;
        } catch (const std::exception& e) {
            std::cerr << "Error receiving message: " << e.what() << std::endl;
            return "";
        }
    }

    void disconnect() {
        try {
            socket_.close();
            std::cout << "TCP connection closed." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error disconnecting: " << e.what() << std::endl;
        }
    }

private:
    std::string host_;
    std::string port_;
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
};

#endif
