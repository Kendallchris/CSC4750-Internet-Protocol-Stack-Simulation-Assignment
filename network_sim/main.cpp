#include <iostream>
#include <queue>
#include <string.h>
#include "layers/application.h"
#include "layers/link.h"
#include "layers/network.h"
#include "layers/transport.h"
#include "custom_interfaces/layerinterface.h"

using namespace std;

queue<string> MessageQueue;
vector<LayerInterface*> NetworkStack;

void setup_network_stack() {
    NetworkStack.push_back(new ApplicationLayer());
    NetworkStack.push_back(new TransportLayer());
    NetworkStack.push_back(new NetworkLayer());
    NetworkStack.push_back(new LinkLayer());
}

void add_message_to_queue(string message) {
    cout << "Message sent: " << message << endl;
    cout << "==== Sending ====" << endl;

    for (int i = 0; i < NetworkStack.size(); i++) {
        message = NetworkStack[i]->Encapsulate(message);
    }

    MessageQueue.push(message);
}

string get_message_from_queue() {
    if (MessageQueue.empty()) return "";

    string message = MessageQueue.front();
    MessageQueue.pop();

    cout << "\n==== Receiving ====" << endl;
    for (int i = NetworkStack.size() - 1; i >= 0; i--) {
        message = NetworkStack[i]->Decapsulate(message);
    }
    cout << "\nFinal message received: " << message << endl;

    return message;
}

int main() {
    setup_network_stack();
    add_message_to_queue("Hello, World!");
    get_message_from_queue();

    for (auto* layer : NetworkStack) delete layer;
    return 0;
}
