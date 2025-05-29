#include "link.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string LinkLayer::Encapsulate(string input) {
    cout << "[Link Layer] Sending: " << input << endl;
    string result = "LINK_HDR|" + input;
    return result;
}

string LinkLayer::Decapsulate(string input) {
    cout << "[Link Layer] Received: " << input << endl;
    const string prefix = "LINK_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
