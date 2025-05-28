#ifndef LAYER_H
#define LAYER_H
#include <string>
class LayerInterface {
    public:
        virtual std::string Encapsulate(std::string input) {
            return "Unimplemented";
        }
        //virtual std::string Decapsulate(std::string input);
        //virtual ~LayerInterface() {};
};

#endif