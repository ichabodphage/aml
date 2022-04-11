#include "../include/tint.hpp"

using namespace aml;

float Tint::normalize(float value){
    if(value != 0){
        return value/255.0f;
    }
    return 0;
}

Tint::Tint(float red,float green,float blue){
    colors[0] = normalize(red);
    std::cout << colors[0] << ", ";
    colors[1] = normalize(green);
    std::cout << colors[1] << ", ";
    colors[2] = normalize(blue);
    std::cout << colors[2] << "\n";
}


Tint::Tint(float lightness){
    float normalLight = normalize(lightness);
    colors[0] = normalLight;
    colors[1] = normalLight;
    colors[2] = normalLight;
  
};
