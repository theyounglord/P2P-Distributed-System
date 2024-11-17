#ifndef PEER_DISCOVERY_H
#define PEER_DISCOVERY_H

#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include "udp_connection.h"

class PeerDiscovery {
public:
    PeerDiscovery(const std::string& broadcast_address, const std::string& port)
        : udp_connection_(broadcast_address, port) {}

    bool initialize() {
        return udp_connection_.bind();
    }

    void discoverPeers() {
        try {
            boost::asio::ip::udp::endpoint sender_endpoint;
            while (true) {
                std::string message = udp_connection_.receive(sender_endpoint);
                std::cout << "Discovered peer at " << sender_endpoint.address() << ":" << sender_endpoint.port()
                          << " - Message: " << message << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error during peer discovery: " << e.what() << std::endl;
        }
    }

private:
    UDPConnection udp_connection_;
};

#endif
