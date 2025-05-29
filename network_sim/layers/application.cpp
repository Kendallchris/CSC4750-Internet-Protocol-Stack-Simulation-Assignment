#include "application.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string ApplicationLayer::Encapsulate(string input) {
    cout << "[Application Layer] Sending: " << input << endl;
    string result = "APP_HDR|" + input;
    return result;
}

std::string ApplicationLayer::Decapsulate(string input) {
    cout << "[Application Layer] Received: " << input << endl;
    const string prefix = "APP_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
