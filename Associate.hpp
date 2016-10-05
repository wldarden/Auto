//
//  Associate.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Associate_hpp
#define Associate_hpp

#include "std_lib_facilities.h"

class Associate{
private:
    string name;
    int employee_number;
    vector<int> orders;
public:
    //constructors
    Associate(): name("NULL"), employee_number(-1) { }
    Associate(string n, int num): name(n), employee_number(num) {}
    
    //getters
    string get_name();
    int get_number();
    vector<int> get_orders();
    string to_string();
    
    //setters
    void add_order(int o);
};

#endif /* Associate_hpp */
