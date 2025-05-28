#include "application.h"
using namespace std;


string ApplicationLayer::Encapsulate(string input) {
    return input.insert(0, "APP_HDR|");
}
