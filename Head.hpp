//
//  Head.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Head_hpp
#define Head_hpp

#include "std_lib_facilities.h"
#include "Part.hpp"
#include "PartType.hpp"

class Head : public Part {
private:
    
public:
    Head(string n, int p_num, PartType t, double w, double c, string d) :  Part(n,p_num,t,w,c,d) {}
};

#endif /* Head_hpp */
