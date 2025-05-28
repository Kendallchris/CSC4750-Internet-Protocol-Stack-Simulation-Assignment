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
    LayerInterface* al = new NetworkLayer();

    NetworkStack.push_back(new ApplicationLayer());
    NetworkStack.push_back(new TransportLayer());
    NetworkStack.push_back(new NetworkLayer());
    NetworkStack.push_back(new LinkLayer());
}

void add_message_to_queue(string message) {
    for (int i = 0; i < NetworkStack.size(); i++) {
        message = NetworkStack[i]->Encapsulate(message);
    }

    MessageQueue.push(message);
}

string get_message_from_queue() {
    if (MessageQueue.size() > 0) {
        string ret = MessageQueue.front();
        MessageQueue.pop();
        return ret;
    }

    return "";
}

vector<string> get_messages_from_queue() {

}


int main() {
    setup_network_stack();
    add_message_to_queue("Hello, World!");
    cout << get_message_from_queue() << endl;
    return 0;
}
