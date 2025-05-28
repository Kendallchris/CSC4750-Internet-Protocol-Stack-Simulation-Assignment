#ifndef LAYER_H
#define LAYER_H

#include <string>

class LayerInterface {
    public:
        virtual std::string Encapsulate(std::string input) = 0;
        virtual std::string Decapsulate(std::string input) = 0;
        virtual ~LayerInterface() {};
};

#endif