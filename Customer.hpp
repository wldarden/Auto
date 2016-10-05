//
//  Customer.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Customer_hpp
#define Customer_hpp

#include "std_lib_facilities.h"


class Customer{
private:
    string name;
    int number;
    vector<int> orders;
public:
    //constructors
    Customer(): name("NULL"), number(-1) { }
    Customer(string n, int num): name(n), number(num) {}
    
    //getters
    string get_name();
    int get_number();
    vector<int> get_orders();
    
    //methods
    void add_order(int o);
    string to_string();
    
};

#endif /* Customer_hpp */
