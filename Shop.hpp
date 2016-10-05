//
//  Shop.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Shop_hpp
#define Shop_hpp

#include "std_lib_facilities.h"
#include "Robot.hpp"
#include "Customer.hpp"
#include "Associate.hpp"
#include "Part.hpp"
#include "Order.hpp"

class Shop{
private:
    vector<Robot> robot_models;
    vector<Customer> customers;
    vector<Associate> associates;
    vector<Order> orders;
    vector<Part> parts;
    
public:
    void add_model(Robot r);
    void add_customer(string n);
    void add_associate(string n);
    void add_part(Part p);
    void add_order(Order o);
    
    //getters
    vector<Customer> get_customers();
    Customer get_customer(int i);
    vector<Associate> get_associates();
    Associate get_associate(int i);
    vector<Order> get_orders();
    vector<Part> get_parts();
    int get_nparts();
    int get_norders();
};

#endif /* Shop_hpp */
