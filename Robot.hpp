//
//  Robot.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Robot_hpp
#define Robot_hpp

#include "std_lib_facilities.h"
#include "Part.hpp"

class Robot {
private:
    string name;
    int model_number;
    double price;
    vector<Part*> parts;

public:
    //constructors
    Robot(string n,int mn,double p) : name(n), price(p) {
        model_number = mn;
    }

    //getters
    string get_name();
    int get_model_number();
    double get_price();
    vector<Part*> get_parts();
    
    //methods
    string to_string();
    void add_part(Part* p);
    void remove_part();
    
};

#endif /* Robot_hpp */
