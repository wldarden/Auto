//
//  Order.cpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Order.hpp"
#include "std_lib_facilities.h"
#include "Robot.hpp"
#include "Date.hpp"
#include "Status.hpp"
#include "Customer.hpp"
#include "Associate.hpp"

//Getters
int Order::get_number(){
    return number;
}

Date Order::get_date(){
    return date;
}

Customer Order::get_customer(){
    return customer;
}

Robot Order::get_robot(){
    return robot;
}

Associate Order::get_associate(){
    return associate;
}

Status Order::get_status(){
    return status;
}

double Order::get_total(){
    return robot.get_price();
}

string Order::to_string(){
    string s = "Order Number: " + std::to_string(number) + " Date: " + date.to_string() + "\n" + " Associate: " + associate.get_name() + " Customer: " + customer.get_name() + "\n" + "Robot: \n" + robot.to_string() + "\n" + "Status: " + status.to_string();
}

//setters
void Order::set_status(Status s){
    status = s;
}







