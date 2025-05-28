#include "application.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string ApplicationLayer::Encapsulate(string input) {
    string result = "APP_HDR|" + input;
    cout << "[Application Layer] Sending: " << result << endl;
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
