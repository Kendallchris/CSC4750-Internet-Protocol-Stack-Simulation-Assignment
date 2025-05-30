/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */
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