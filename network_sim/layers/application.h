
#ifndef APPLICATION_LAYER_CLASS_H
#define APPLICATION_LAYER_CLASS_H
#include <string>

class ApplicationLayer {
    public:
        TransportLayer layer;
        
        std::string ToString();
};