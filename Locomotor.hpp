//
//  Locomotor.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Locomotor_hpp
#define Locomotor_hpp

#include "std_lib_facilities.h"
#include "Part.hpp"

class Locomotor : public Part {
private:
    int max_speed;
    
public:
    //constructors
    Locomotor(string n, int p_num, PartType t,double w, double c, string d, int ms) : max_speed(ms), Part(n,p_num,t,w,c,d) {}
    
    //methods
    int power_consumed(int speed);
};

#endif /* Locomotor_hpp */
