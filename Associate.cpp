//
//  Associate.cpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Associate.hpp"
#include "Order.hpp"

string Associate::get_name(){
    return name;
}

int Associate::get_number(){
    return employee_number;
}

vector<int> Associate::get_orders(){
    return orders;
}

string Associate::to_string(){
    return get_name() + ": " + std::to_string(employee_number);
}

void Associate::add_order(int o){
    orders.push_back(o);
}

