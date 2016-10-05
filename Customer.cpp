//
//  Customer.cpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Customer.hpp"


string Customer::get_name(){
    return name;
}

int Customer::get_number(){
    return number;
}

vector<int> Customer::get_orders(){
    return orders;
}

void Customer::add_order(int o){
    orders.push_back(o);
}

string Customer::to_string(){
    return get_name() + ": " + std::to_string(number);
}




