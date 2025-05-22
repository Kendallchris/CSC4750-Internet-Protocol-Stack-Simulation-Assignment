#ifndef TRANSPORT_LAYER_CLASS_H
#define TRANSPORT_LAYER_CLASS_H
#include <string>

class TransportLayer {
    public:
        TransportLayer();
        Encapsulate();
        Decapsulate();


        std::string ToString();
};