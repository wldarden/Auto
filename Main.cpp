//
//  Main.cpp
//  
//
//  Created by Will Darden on 10/3/16.
//
//

#include "Controller.hpp"
#include "Shop.hpp"

int main(){
    Shop shop;
    Controller controller(shop);
    controller.cli();
}

