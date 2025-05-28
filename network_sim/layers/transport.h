#ifndef TRANSPORT_LAYER_CLASS_H
#define TRANSPORT_LAYER_CLASS_H

#include <string>
#include "../custom_interfaces/layerinterface.h"

class TransportLayer: public LayerInterface {
    public:
        std::string Encapsulate(std::string input);
        std::string Decapsulate(std::string input);
};

#endif