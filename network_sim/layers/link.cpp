/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */
#include "link.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
 * Link layer encapsulation implementation
 * Appends the link layer header.
 */
string LinkLayer::Encapsulate(string input) {
    cout << "[Link Layer] Sending: " << input << endl;
    string result = "LINK_HDR|" + input;
    return result;
}

/**
 * Link layer decapsulation
 * Decapsulates, removing the layer header
 */
string LinkLayer::Decapsulate(string input) {
    cout << "[Link Layer] Received: " << input << endl;
    const string prefix = "LINK_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
