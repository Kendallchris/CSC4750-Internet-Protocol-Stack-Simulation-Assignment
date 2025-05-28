#include "transport.h"
using namespace std;

string TransportLayer::Encapsulate(string input) {
    return input.insert(0, "TRANS_HDR|");

}