//
//  Shop.cpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Shop.hpp"
#include "std_lib_facilities.h"

void Shop::add_model(Robot r){
    robot_models.push_back(r);
}

void Shop::add_customer(string n){
    customers.push_back(Customer(n,customers.size()+1));
}

void Shop::add_associate(string n){
    associates.push_back(Associate(n,associates.size()+1));
}

void Shop::add_part(Part p){
    parts.push_back(p);
}

void Shop::add_order(Order o){
    orders.push_back(o);
}

vector<Customer> Shop::get_customers(){
    return customers;
}

Customer Shop::get_customer(int i){
    if(i < 0 || i > customers.size()){
        //throw out of bounds error
    } else {
        return customers[i];
    }
}

vector<Associate> Shop::get_associates(){
    return associates;
}

Associate Shop::get_associate(int i){
    if(i < 0 || i > associates.size()){
        //throw out of bounds error
    } else {
        return associates[i];
    }
}

vector<Part> Shop::get_parts(){
    return parts;
}

vector<Order> Shop::get_orders(){
    return orders;
}

int Shop::get_nparts(){
    return parts.size();
}

int Shop::get_norders(){
    return orders.size();
}