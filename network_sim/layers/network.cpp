#include "network.h"

using std::string;

string NetworkLayer::Encapsulate(string input) {
    return input.insert(0, "NET_HDR|");
}

string NetworkLayer::Decapsulate(string input) {
    const string prefix = "NET_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
