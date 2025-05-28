#include "application.h"

using std::string;


string ApplicationLayer::Encapsulate(string input) {
    return input.insert(0, "APP_HDR|");
}

std::string ApplicationLayer::Decapsulate(string input) {
    const string prefix = "APP_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
