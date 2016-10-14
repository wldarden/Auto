//
//  View.cpp
//  
//
//  Created by Will Darden on 10/3/16.
//
//

#include "View.hpp"
#include "std_lib_facilities.h"
#include "globals.hpp"

//Menu enumerated in globals
void View::show_menu(Menu men){
    switch(men){
        case(MAIN):{
            cout << "Main Menu" << endl;
            cout << "---------" << endl;
            cout << "[1] Create" << endl;
            cout << "[2] Report" << endl;
            cout << "[3] Save" << endl;
            cout << "[4] Load" << endl;
            cout << "[5] Quit" << endl;
            break;
        }
        case(CREATE):{
            cout << "Create" << endl;
            cout << "---------" << endl;
            cout << "[1] Order" << endl;
            cout << "[2] Customer" << endl;
            cout << "[3] Sales Associate" << endl;
            cout << "[4] Robot Model" << endl;
            cout << "[5] Robot Component" << endl;
            cout << "[0] Back to Main Menu" << endl;
            break;
        }
        case(REPORT):{
            cout << "Report" << endl;
            cout << "---------" << endl;
            cout << "[1] Orders" << endl;
            cout << "[2] Customers" << endl;
            cout << "[3] Sales Associates" << endl;
            cout << "[4] Robot Models" << endl;
            cout << "[5] Robot Components" << endl;
            cout << "[0] Back to Main Menu" << endl;
            break;
        }
        case(SAVE):{
            cout << "Save" << endl;
            cout << "---------" << endl;
            cout << "[1] New File" << endl;
            cout << "---------" << endl;
            //old files for persistence
            cout << "---------" << endl;
            cout << "[0] Back to Main Menu" << endl;
            break;
            
        }
        case(LOAD):{
            cout << "Load" << endl;
            cout << "---------" << endl;
            //old files for persistence
            cout << "---------" << endl;
            cout << "[0] Back to Main Menu" << endl;
            break;
        }
    }
}

void View::show_list(vector<string> obj){
    int i = 0;
    cout << "----LIST----\n";
    for(String s:obj){
        i++;
        cout << "[" << std::to_string(i) << "] " << s << endl;
    }
    cout << "----END ----\n";
}

