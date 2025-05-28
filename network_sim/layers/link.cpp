#include "link.h"

using std::string;

string LinkLayer::Encapsulate(string input) {
    return input.insert(0, "LINK_HDR|");
}

string LinkLayer::Decapsulate(string input) {
    const string prefix = "LINK_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
