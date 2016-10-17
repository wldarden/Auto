//
//  Order.hpp
//  
//
//  Created by Will Darden on 10/2/16.
//
//

#ifndef Order_hpp
#define Order_hpp

#include "std_lib_facilities.h"
#include "Date.hpp"

#include "Associate.hpp"
#include "Customer.hpp"
#include "Status.hpp"
#include "Robot.hpp"



class Order{
private:
    int number;
    Date date;
    Customer customer;
    Robot* robot;
    Associate associate;
    Status status;
    
public:
    //constructors
    Order(int n,Date d, Customer c, Robot* r, Associate a): number(n), date(d), customer(c), robot(r), associate(a) {
        status.set_value(0);
    }
    
    //getters
    int get_number();
    Date get_date();
    Customer get_customer();
    Robot* get_robot();
    Associate get_associate();
    Status get_status();
    string to_string();
    
    //setters
    void set_status(Status s);
    
    //methods
    double get_total();
};

#endif /* Order_hpp */
