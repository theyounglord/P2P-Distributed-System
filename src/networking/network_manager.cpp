#include "tcp_connection.h"
#include "udp_connection.h"
#include "peer_discovery.h"

int main() {
    // Initialize TCP Connection
    TCPConnection tcp("127.0.0.1", "8080");
    if (!tcp.connect()) {
        std::cerr << "Failed to establish TCP connection. Exiting..." << std::endl;
        return 1;
    }

    // Send and receive via TCP
    tcp.send("Hello, Server!");
    std::string response = tcp.receive();
    std::cout << "Response from server: " << response << std::endl;

    // Initialize UDP for peer discovery
    PeerDiscovery discovery("0.0.0.0", "9090");
    if (!discovery.initialize()) {
        std::cerr << "Failed to initialize UDP connection for peer discovery. Exiting..." << std::endl;
        return 1;
    }

    // Discover peers (this runs indefinitely for demonstration purposes)
    discovery.discoverPeers();

    // Clean up
    tcp.disconnect();

    return 0;
}
