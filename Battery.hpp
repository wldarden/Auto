//
//  Battery.hpp
//  
//
//  Created by Will Darden on 10/1/16.
//
//

#ifndef Battery_hpp
#define Battery_hpp

#include "std_lib_facilities.h"
#include "Part.hpp"

class Battery : public Part {
private:
    double energy;
    double max_power;

public:
    Battery(string n, int p_num, double w, double c, string d, double mp) : energy(mp), max_power(mp), Part(n,p_num,w,c,d) {}
    double get_energy();
    double get_max_power();
    virtual string to_string();
    
};

#endif /* Battery_hpp */
