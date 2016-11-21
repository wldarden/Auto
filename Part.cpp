//
//  Part.cpp
//
//
//  Created by Will Darden on 10/1/16.
//
//

#include "Part.hpp"
#include "PartType.hpp"
#include "std_lib_facilities.h"

string Part::get_name(){
    return name;
}

int Part::get_part_number(){
    return part_number;
}

PartType Part::get_type(){
    return type;
}

double Part::get_weight(){
    return weight;
}

double Part::get_cost(){
    return cost;
}

string Part::get_description(){
    return description;
}

string Part::to_string(){
    string p = "Name      : " + name + "\n" +
    "Part Number: " + std::to_string(part_number) + "\n" +
    "Part Type  : " + type.to_string() + "\n" +
    "Weight     : " + std::to_string(weight) + "\n" +
    "Cost       : " + std::to_string(cost) + "\n" +
    "Description: " + description + "\n";
    return p;
}
