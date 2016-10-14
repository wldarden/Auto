//
//  Part.hpp
//  
//
//  Created by Will Darden on 10/1/16.
//
//

#ifndef Part_hpp
#define Part_hpp

#include "std_lib_facilities.h"
#include "PartType.hpp"

class Part {
protected:
    string name;
    int part_number;
    PartType type;
    double weight;
    double cost;
    string description;
    
public:
    //constructors
    Part(string n, int p_num, PartType t, double w, double c, string d){
        name = n;
        part_number = p_num;
        type = t;
        weight = w;
        cost = c;
        description = d;
        
    }
    
    //getters
    string get_name();
    int get_part_number();
    PartType get_type();
    double get_weight();
    double get_cost();
    string get_description();
    
    //methods
    virtual string to_string();

};

#endif /* Part_hpp */
