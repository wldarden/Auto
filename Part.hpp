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

class Part {
protected:
    string name;
    int part_number;
    double weight;
    double cost;
    string description;
    
public:
    //constructors
    Part(string n, int p_num, double w, double c, string d){
        name = n;
        part_number = p_num;
        weight = w;
        cost = c;
        description = d;
        
    }
    
    //getters
    string get_name();
    int get_part_number();
    double get_weight();
    double get_cost();
    string get_description();
    
    //methods
    virtual string to_string();

};

#endif /* Part_hpp */
