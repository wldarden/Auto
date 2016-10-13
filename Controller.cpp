//
//  Controller.cpp
//  
//
//  Created by Will Darden on 10/3/16.
//
//

#include "Controller.hpp"

//Enumerations
#include "globals.hpp"
#include "Date.hpp"
#include "Status.hpp"

//Robot Model Files
#include "Robot.hpp"
#include "Part.hpp"
#include "Arm.hpp"
#include "Battery.hpp"
#include "Head.hpp"
#include "Locomotor.hpp"
#include "Torso.hpp"

//Other
#include "Associate.hpp"
#include "Customer.hpp"
#include "Order.hpp"

void Controller::cli() {
    Menu men = MAIN;
    int cmd = -1;
    while (cmd != 0) {
        view.show_menu(men);
        cout << "Command? \n";
        cin >> cmd;
        cin.ignore();
        men = execute_cmd(cmd,men);
    }
}

//Menu enumerated in globals
Menu Controller::execute_cmd(int cmd,Menu men){
    if(cmd == 0){
        men = MAIN;
    }
    switch(men){
        case(MAIN):{
            switch(cmd){
                case(1):return CREATE;
                case(2):return REPORT;
                case(3):return SAVE;
                case(4):return LOAD;
                case(5):exit(0);
            }
            break;
        }
        case(CREATE):{
            switch(cmd){
                case(1):{
                    //////////////
                    //create order
                    //////////////
                    int n = shop.get_norders()+1;
                    //Date d; created later
                    int day,month,year;
                    Customer c;
                    Associate a;
                    Status status(0);
                    int choice =-1;
                    
                    //create date
                    cout << "Enter Date: \n" << "Year: ";
                    cin >> year;
                    cin.ignore();
                    cout << "Month: ";
                    cin >> month;
                    cin.ignore();
                    cout << "Day: ";
                    cin >> day;
                    cin.ignore();
                    Date d(day,month,year);
                    
                    //create or get customer
                    //get customer list
                    vector<string> all_c;
                    for(Customer cust:shop.get_customers()){
                        all_c.push_back(cust.to_string());
                    }
                    cout << "[0] New customer\n";
                    view.show_list(all_c);
                    cout << "Enter menu number: ";
                    cin >> choice;
                    cin.ignore();
                    if(choice > 0){
                        c = shop.get_customer(choice -1);
                    } else {
                        //create customer
                        string c_name;
                        cout << "Customer's Name: ";
                        getline(cin,c_name);
                        shop.add_customer(c_name);
                        c = shop.get_customer((shop.get_customers()).size());
                    }
                    
                    //create or get associate
                    //get associate list
                    vector<string> all_a;
                    for(Associate assoc:shop.get_associates()){
                        all_a.push_back(assoc.to_string());
                    }
                    cout << "[0] New associate\n";
                    view.show_list(all_a);
                    cout << "Enter menu number: ";
                    choice = -1;
                    cin >> choice;
                    cin.ignore();
                    if(choice > 0){
                        a = shop.get_associate(choice - 1);
                    } else {
                        //create associate
                        string a_name;
                        cout << "Associate's Name: ";
                        getline(cin,a_name);
                        shop.add_associate(a_name);
                        a = shop.get_associate((shop.get_associates()).size());
                    }
                    return MAIN;
                }
                case(2):{
                    //create customer
                    string c_name;
                    cout << "Customer's Name: ";
                    getline(cin,c_name);
                    shop.add_customer(c_name);
                    return MAIN;
                }
                case(3):{
                    //create sales associate
                    string a_name;
                    cout << "Associates's Name: ";
                    getline(cin,a_name);
                    shop.add_customer(a_name);
                    return MAIN;
                }
                case(4):{
                    //create model
                    create_model();
                    return MAIN;
                }
                case(5):{
                    //create part
                    create_part();
                    return MAIN;
                }
            }
            break;
        }
        case(REPORT):{
            switch(cmd){
                case(1):{
                    //Order reports
                    cout << "Order Reports \n";
                    cout << "-------------\n";
                    cout << "[1] List all orders \n";
                    cout << "[2] List open orders\n";
                    cin >> cmd;
                    cin.ignore();
                    switch(cmd){
                        case(1): {
                            vector<string> s;
                            for(Order o:shop.get_orders()){
                                s.push_back(o.to_string());
                            }
                            view.show_list(s);
                            break;
                        }
                        case(2):{
                            vector<string> s;
                            for(Order o:shop.get_orders()){
                                if(o.get_status().get_value() == 0){
                                    s.push_back(o.to_string());
                                }
                            }
                            view.show_list(s);
                            break;
                        }
                    }
                    return REPORT;
                }
                case(2):{
                    //Customer reports
                    cout << "Customer Reports \n";
                    cout << "-------------\n";
                    cout << "[1] List all customers \n";
                    cin >> cmd;
                    cin.ignore();
                    switch(cmd){
                        case(1): {
                            vector<string> s;
                            for(Customer c:shop.get_customers()){
                                s.push_back(c.to_string());
                            }
                            view.show_list(s);
                            break;
                        }
                    }
                    return REPORT;
                }
                case(3):{
                    //sales associates
                    cout << "Associates Reports \n";
                    cout << "-------------\n";
                    cout << "[1] List all Associates \n";
                    cin >> cmd;
                    cin.ignore();
                    switch(cmd){
                        case(1): {
                            vector<string> s;
                            for(Associate c:shop.get_associates()){
                                s.push_back(c.to_string());
                            }
                            view.show_list(s);
                            break;
                        }
                    }
                    return REPORT;
                }
                case(4):{
                    //robot models
                    cout << "Robot Model Reports \n";
                    cout << "-------------\n";
                    cout << "[1] List all Models \n";
                    cin >> cmd;
                    cin.ignore();
                    switch(cmd){
                        case(1): {
                            vector<string> s;
                            for(Part c:shop.get_parts()){
                                s.push_back(c.to_string());
                            }
                            view.show_list(s);
                            break;
                        }
                    }
                    return REPORT;
                }
                case(5):{
                    //Robot parts
                    cout << "Robot Component Reports \n";
                    cout << "-------------\n";
                    cout << "[1] List all Components \n";
                    cin >> cmd;
                    cin.ignore();
                    switch(cmd){
                        case(1): {
                            vector<string> s;
                            for(Part c:shop.get_parts()){
                                s.push_back(c.to_string());
                            }
                            view.show_list(s);
                            break;
                        }
                    }
                    return REPORT;
                }
            }
            break;
        }
    }
    return MAIN;
}

void Controller::create_part(){
    string input;
    string name, desc;
    double weight, cost;
    int part_type, id;
    
    cout << "Creating new part\n";
    cout << "Part Name: ";
    getline(cin,name );
    cout << "Part Number: ";
    cin >> id;
    cin.ignore();
    cout << "Part weight: ";
    cin >> weight;
    cin.ignore();
    cout << "Part cost: ";
    cin >> cost;
    cin.ignore();
    cout << "Part description: ";
    getline(cin,desc);
    cout << "Part type:\n";
    cout << "[1] Arm\n";
    cout << "[2] Battery\n";
    cout << "[3] Head\n";
    cout << "[4] Locomotor\n";
    cout << "[5] Torso\n";
    cout << "Enter menu number: ";
    cin >> part_type;
    cin.ignore();
    switch(part_type){
        case(1):{
            //Arm
            shop.add_part(Arm(name,id,weight,cost,desc));
            break;
        }
        case(2):{
            //battery
            double max_power;
            cout << "Battery max power :";
            cin >> max_power;
            cin.ignore();
            shop.add_part(Battery(name,id,weight,cost,desc,max_power));
            break;
        }
        case(3):{
            //head
            shop.add_part(Head(name,id,weight,cost,desc));
            break;
        }
        case(4):{
            //locomotor
            int max_speed;
            cout << "Locomotor max speed: ";
            cin >> max_speed;
            cin.ignore();
            shop.add_part(Locomotor(name,id,weight,cost,desc,max_speed));
            break;
        }
        case(5):{
            //torso
            int bat_comp;
            cout << "Number of Battery Compartments: ";
            cin >> bat_comp;
            cin.ignore();
            shop.add_part(Torso(name,id,weight,cost,desc,bat_comp));
            break;
        }
    }
}

void Controller::create_model(string n, double p){
    //create model
    string name;
    double price;
    cout << "Model Name: ";
    getline(cin,name);
    cout << "Price: ";
    cin >> price;
    cin.ignore();
    
}
















