//
//  Torso.cpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Torso.hpp"
#include "Head.hpp"
#include "Locomotor.hpp"
#include "Battery.hpp"
#include "std_lib_facilities.h"
#include "Arm.hpp"

void Torso::add_head(Head* h){
    head = h;
}

void Torso::add_arm(Arm* a){
    if(arms.size() >= 2){
        //throw too many arms exception
    } else {
        arms.push_back(a);
    }
}

void Torso::add_locomotor(Locomotor* l){
    locomotor = l;
}

void Torso::add_battery(Battery* b){
    if(batteries.size() >= battery_compartments){
        //throw too many batteries exception
    } else {
        batteries.push_back(b);
    }
}

int Torso::get_max_batteries(){
    return battery_compartments;
}

int Torso::get_nbatteries(){
    return batteries.size();
}