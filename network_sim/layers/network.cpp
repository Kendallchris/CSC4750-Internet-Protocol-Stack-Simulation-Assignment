#include "network.h"
using namespace std;

string NetworkLayer::Encapsulate(string input) {
    return input.insert(0, "NET_HDR|");
}