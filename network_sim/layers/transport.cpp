#include "transport.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string TransportLayer::Encapsulate(string input) {
    string result = "TRANS_HDR|" + input;
    cout << "[Transport Layer] Sending: " << result << endl;
    return result;
}

string TransportLayer::Decapsulate(string input) {
    cout << "[Transport Layer] Received: " << input << endl;
    const string prefix = "TRANS_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
