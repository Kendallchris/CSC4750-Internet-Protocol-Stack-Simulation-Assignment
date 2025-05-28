#include "network.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string NetworkLayer::Encapsulate(string input) {
    string result = "NET_HDR|" + input;
    cout << "[Network Layer] Sending: " << result << endl;
    return result;
}

string NetworkLayer::Decapsulate(string input) {
    cout << "[Network Layer] Received: " << input << endl;
    const string prefix = "NET_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
