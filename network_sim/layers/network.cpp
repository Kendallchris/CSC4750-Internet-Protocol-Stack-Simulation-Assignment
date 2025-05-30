/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */
#include "network.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
 * Network layer encapsulation implementation
 * Appends the network layer header.
 */
string NetworkLayer::Encapsulate(string input) {
    cout << "[Network Layer] Sending: " << input << endl;
    string result = "NET_HDR|" + input;
    return result;
}

/**
 * Network layer decapsulation
 * Decapsulates, removing the layer header
 */
string NetworkLayer::Decapsulate(string input) {
    cout << "[Network Layer] Received: " << input << endl;
    const string prefix = "NET_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
