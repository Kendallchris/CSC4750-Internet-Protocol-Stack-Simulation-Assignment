#include "transport.h"
using namespace std;

string TransportLayer::Encapsulate(string input) {
    return input.insert(0, "TRANS_HDR|");

}

string TransportLayer::Decapsulate(string input) {
    const string prefix = "TRANS_HDR|";
    if (input.substr(0, prefix.length()) == prefix) {
        return input.substr(prefix.length());
    }
    return input;
}
