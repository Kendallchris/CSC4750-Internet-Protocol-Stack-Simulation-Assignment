/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */

#include "application.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
 * Application layer encapsulation implementation
 * Appends the application layer header.
 */
string ApplicationLayer::Encapsulate(string input) {
    cout << "[Application Layer] Sending: " << input << endl;
    string result = "APP_HDR|" + input;
    return result;
}

/**
 * Application layer decapsulation
 * Decapsulates, removing the layer header
 */
std::string ApplicationLayer::Decapsulate(string input) {
    cout << "[Application Layer] Received: " << input << endl;
    const string prefix = "APP_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
