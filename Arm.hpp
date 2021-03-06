//
//  Arm.hpp
//  
//
//  Created by Will Darden on 10/3/16.
//
//

#ifndef Arm_hpp
#define Arm_hpp

#include "Part.hpp"
#include "PartType.hpp"

class Arm : public Part{
private:
    
public:
    //constructors
    Arm(string n, int p_num, PartType t, double w, double c, string d) :  Part(n,p_num,t,w,c,d) {}
    
    //methods
    int power_consumed(int speed);
};

#endif /* Arm_hpp */


