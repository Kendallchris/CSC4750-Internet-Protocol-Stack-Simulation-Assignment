/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */

#include <iostream>
#include <queue>
#include <string.h>
#include "layers/application.h"
#include "layers/link.h"
#include "layers/network.h"
#include "layers/transport.h"
#include "custom_interfaces/layerinterface.h"

using namespace std;

// Top-level message queue and networking stack for this networking simulation
queue<string> MessageQueue;
vector<LayerInterface*> NetworkStack;

/**
 * setup_network_stack
 * Initializes the networking stack with an application, transport, network, and link layer. The result is a vector with the application layer first, and the link layer last.
 * Returns void
 */
void setup_network_stack() {
    NetworkStack.push_back(new ApplicationLayer());
    NetworkStack.push_back(new TransportLayer());
    NetworkStack.push_back(new NetworkLayer());
    NetworkStack.push_back(new LinkLayer());
}

/**
 * Add message to queue
 * Adds a message to the networking queue.
 * string: message - The message to send to the networking queue.
 * Returns void
 */
void add_message_to_queue(string message) {
    cout << "Message sent: " << message << endl;
    cout << "==== Sending ====" << endl;

    // Go through the networking layers, encapsulating using the layer_interface interface.
    for (size_t i = 0; i < NetworkStack.size(); i++) {
        message = NetworkStack[i]->Encapsulate(message);
    }

    MessageQueue.push(message);
}

/**
 * Get message from queue
 * Gets the next message from the networking queue.
 * If the message queue is empty, return an empty string.
 * Decapsulates the message using the networking layers set up earlier.
 */
string get_message_from_queue() {
    if (MessageQueue.empty()) return "";

    // Get the most recent message from the queue.
    string message = MessageQueue.front();
    MessageQueue.pop();

    // Decapsulate the message using the Networking stack, and the layer interface.
    cout << "\n==== Receiving ====" << endl;
    for (int i = NetworkStack.size() - 1; i >= 0; i--) {
        message = NetworkStack[i]->Decapsulate(message);
    }
    cout << "\nFinal message received: " << message << endl;

    return message;
}

/**
 * Main
 * Setups up the networking stack, and encapsulates and decapsulates the first three lines of "Resturaunt at the end of the universe"
 */
int main() {
    setup_network_stack();

    // Create a string to store the values from the output of the network.
    string output = "";

    // Add messages
    add_message_to_queue("The story so far: \n");
    add_message_to_queue("In the beginning the Universe was created\n");

    // Get one message from the network.
    output.insert(output.length(), get_message_from_queue());


    // Add another message to the queue.
    add_message_to_queue("This has made a lot of people very angry and has been widly regarded as a bad move.\n");

    // Get the last messages
    output.insert(output.length(), get_message_from_queue());
    output.insert(output.length(), get_message_from_queue());


    // Print the final string outputted from the networking layer.
    cout  << "Final result: \n" << output << endl;

    // Deallocate the networking stack to prevent leaks.
    for (auto* layer : NetworkStack) delete layer;
    return 0;
}
