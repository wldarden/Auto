//
//  Torso.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Torso_hpp
#define Torso_hpp

#include "Part.hpp"
#include "Torso.hpp"
#include "Head.hpp"
#include "Locomotor.hpp"
#include "Battery.hpp"
#include "std_lib_facilities.h"
#include "Arm.hpp"

class Torso : public Part {
private:
    const int battery_compartments;
    Head head;
    vector<Arm> arms;
    Locomotor locomotor;
    vector<Battery> batteries;
    
public:
    //constructor
    Torso(string n, int p_num, double w, double c, string d, int bc) : battery_compartments(bc), head(Head("",-1,-1,-1,"")), locomotor(Locomotor("",-1,-1,-1,"",-1)), Part(n,p_num,w,c,d) { }
    //setters
    void add_head(Head h);
    void add_arm(Arm a);
    void add_locomotor(Locomotor l);
    void add_battery(Battery b);
    
};

#endif /* Torso_hpp */
