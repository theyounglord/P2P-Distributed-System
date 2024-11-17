# P2P-Distributed-Systems


It looks like your program successfully connects to the PostgreSQL database but exits right after the connection is established. This happens because, once the program executes all the instructions in `main()`, it reaches the end and exits automatically.

To keep the program running until it's manually terminated, you need to implement some logic that prevents the program from exiting immediately. This could be something like a loop, a server that listens for requests, or any other mechanism depending on the intended functionality of your application.

Here are a few approaches depending on the structure of your application:

### 1. **Basic Infinite Loop**:
You can add a simple infinite loop to keep the program running indefinitely until it's manually terminated (e.g., via `CTRL + C`).

```cpp
int main(int argc, char** argv) {
    // Load config and connect to the database
    std::string environment = "development";  // Default environment
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
```

- The `while (true)` loop keeps the program running indefinitely. Inside the loop, we use `std::this_thread::sleep_for(std::chrono::seconds(1));` to simulate some delay (and to avoid busy-waiting, which consumes a lot of CPU).
- You can replace this with more meaningful logic as you build out your program.

### 2. **Event Loop**:
If your program is a server or client waiting for connections or input, you can replace the infinite loop with an event-driven loop. For example, if you have a command-line interface or network server, you could have a loop waiting for user input or network events.

```cpp
int main(int argc, char** argv) {
    // Load config and connect to the database
    std::string environment = "development";
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

    std::string userInput;
    while (true) {
        std::cout << "Enter a command (type 'exit' to quit): ";
        std::getline(std::cin, userInput);
        if (userInput == "exit") {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        // Handle other commands here
        std::cout << "You entered: " << userInput << std::endl;
    }

    return 0;
}
```

This example simulates an interactive CLI program that waits for user input in a loop. The program will continue running until the user types "exit."

### 3. **Daemon or Server Process**:
If your application is meant to be a long-running process (like a server), you'll typically have it run in a loop handling requests, or simply waiting for incoming connections. For example, in a network-based application, you might have a loop that listens for connections:

```cpp
while (true) {
    // Accept incoming connections, process requests, etc.
}
```

This is a more specific case depending on your application's purpose.

### 4. **Signal Handling**:
You could also implement signal handling to exit gracefully when a termination signal is received. This can be done using the `<csignal>` library in C++. For example:

```cpp
#include <csignal>
#include <iostream>

volatile bool running = true;

void handleSignal(int signal) {
    std::cout << "Signal received: " << signal << ". Terminating program..." << std::endl;
    running = false;
}

int main() {
    signal(SIGINT, handleSignal);  // Handle Ctrl + C (SIGINT)

    // Load config and connect to the database as before
    // ...

    while (running) {
        // Your program logic
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Program terminated." << std::endl;
    return 0;
}
```

This will allow the program to terminate gracefully when you press `Ctrl + C`.

---

### Conclusion

You can choose any of the above methods depending on how your program is structured or what it will eventually do. For now, the easiest solution is to add a simple infinite loop to keep it running. As you add more functionality, you can replace this with more meaningful loops, like listening for user input or handling network requests.