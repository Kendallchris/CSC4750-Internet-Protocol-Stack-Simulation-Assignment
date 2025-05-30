/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */
#ifndef LINK_LAYER_H
#define LINK_LAYER_H

#include <string>
#include "../custom_interfaces/layerinterface.h"

class LinkLayer : public LayerInterface {
    public:
        std::string Encapsulate(std::string input);
        std::string Decapsulate(std::string input);
};

#endif