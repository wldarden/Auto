//
//  Battery.cpp
//  
//
//  Created by Will Darden on 10/1/16.
//
//

#include "Battery.hpp"
#include "std_lib_facilities.h"

double Battery::get_energy(){
        return energy;
}

double Battery::get_max_power(){
        return max_power;
}

string Battery::to_string(){
    string bat =
    "Name       : " + name + "\n" +
    "Part Number: " + std::to_string(part_number) + "\n" +
    "Weight     : " + std::to_string(weight) + "\n" +
    "Cost       : " + std::to_string(cost) + "\n" +
    "Description: " + description + "\n" +
    "Max Power  : " + std::to_string(max_power) + "\n";
    return bat;
}
