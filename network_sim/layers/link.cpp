#include "link.h"
using namespace std;

string LinkLayer::Encapsulate(string input) {
    return input.insert(0, "LINK_HDR|");
}