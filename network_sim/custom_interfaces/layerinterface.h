/**
 * Networking Simulation
 * CSC4750
 * Dennis vickers
 * Kyler Veenstra, Chris Kendall
 * 2025-05-29
 */
#ifndef LAYER_H
#define LAYER_H

#include <string>

/**
 * LayerInterface
 * Custom interface to cause polymorphic behavior in the networking layers.
 * Virtual methods to encapsulate and decapsulate messages, as well as a required destructor
 */
class LayerInterface {
    public:
        virtual std::string Encapsulate(std::string input) = 0;
        virtual std::string Decapsulate(std::string input) = 0;
        virtual ~LayerInterface() {};
};

#endif