//
//  Shop.cpp
//
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Shop.hpp"
#include "PartType.hpp"

void Shop::add_model(Robot* r){
    robot_models.push_back(r);
}

void Shop::add_customer(string n){
    customers.push_back(new Customer(n,customers.size()+1));
}

void Shop::add_associate(string n){
    associates.push_back(new Associate(n,associates.size()+1));
}

void Shop::add_part(Part* p){
    parts.push_back(p);
}

void Shop::add_order(Date d, Customer c, Robot* r, Associate a){
    Order* o = new Order(orders.size()+1,d,c,r,a);
    orders.push_back(o);
}

vector<Customer*> Shop::get_customers(){
    return customers;
}

Customer* Shop::get_customer(int i){
    if(i < 0 || i > customers.size()){
        //throw out of bounds error
    } else {
        return (customers[i]);
    }
}

vector<Associate*> Shop::get_associates(){
    return associates;
}

Associate* Shop::get_associate(int i){
    if(i < 0 || i > associates.size()){
        //throw out of bounds error
    } else {
        return (associates[i]);
    }
}

vector<Part *> Shop::get_parts(PartType t){
    //{ALL=0, ARM=1, BATTERY=2, HEAD=3, LOCOMOTOR=4, TORSO=5}
    vector<Part*> x;//x is the return vector of desired parts
    if(t.get_value() == 0){
        return parts;
    } else {
        for(Part* p:parts){
            if((p->get_type()).get_value() == t.get_value()){
                x.push_back(p);
            }
        }
        return x;
    }
}

vector<Order*> Shop::get_orders(){
    return orders;
}

vector<Robot*> Shop::get_models(){
    return robot_models;
}

int Shop::get_nparts(){
    return parts.size();
}

int Shop::get_norders(){
    return orders.size();
}
