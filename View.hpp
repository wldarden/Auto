//
//  View.hpp
//  
//
//  Created by Will Darden on 10/3/16.
//
//

#ifndef View_hpp
#define View_hpp

#include "Shop.hpp"
#include "globals.hpp"

class View{
public:
    //constructors
    View(Shop& s): shop(s) {}
    
    //methods
    void show_menu(Menu men);
    void show_list(vector<string> obj);
    
private:
    Shop& shop;
};

#endif /* View_hpp */
