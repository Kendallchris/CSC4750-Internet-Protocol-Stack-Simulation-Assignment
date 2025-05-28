#ifndef NETWORK_LAYER_H
#define NETWORK_LAYER_H

#include "../custom_interfaces/layerinterface.h"

class NetworkLayer : public LayerInterface { 
    public:
        std::string Encapsulate(std::string input);
        std::string Decapsulate(std::string input);
};
#endif