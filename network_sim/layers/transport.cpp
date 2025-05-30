/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */
#include "transport.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
 * Transport layer encapsulation implementation
 * Appends the transport layer header.
 */
string TransportLayer::Encapsulate(string input) {
    cout << "[Transport Layer] Sending: " << input << endl;
    string result = "TRANS_HDR|" + input;
    return result;
}

/**
 * Transport layer decapsulation
 * Decapsulates, removing the layer header
 */
string TransportLayer::Decapsulate(string input) {
    cout << "[Transport Layer] Received: " << input << endl;
    const string prefix = "TRANS_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
