//
//  Robot.cpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Robot.hpp"
#include "std_lib_facilities.h"
#include "Part.hpp"



//getters
string Robot::get_name(){
    return name;
}

int Robot::get_model_number(){
    return model_number;
}

double Robot::get_price(){
    price = 0;
    for(Part* p:parts){
        price += p->get_cost();
    }
    return price;
}

vector<Part*> Robot::get_parts(){
    return parts;
}

//methods
string Robot::to_string(){
    return get_name();
}
void Robot::add_part(Part* p){
    parts.push_back(p);
}




