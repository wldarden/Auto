//
//  Controller.hpp
//  
//
//  Created by Will Darden on 10/3/16.
//
//

#ifndef Controller_hpp
#define Controller_hpp

#include "View.hpp"
#include "Shop.hpp"
#include "globals.hpp"

class Controller{
public:
    Controller (Shop& s) : shop(s), view(View(s)) {
        men = MAIN;
    }
    void cli();
    Menu execute_cmd(int cmd, Menu men);
    
private:
    Shop& shop;
    View view;
    Menu men;
    void create_part();
    void create_model();
};

#endif /* Controller_hpp */
