//
//  MainGUI.cpp
//
//
//  Created by Will Darden on 10/30/16.
//
//

// //Enumerations
// #include "globals.hpp"
// #include "Date.hpp"
// #include "Status.hpp"
//
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
#include "PartType.hpp"
#include "Shop.hpp"

//FLTK files
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>

//c++ libs
#include <iostream>
#include <List>

using namespace std;

//global constants
const int WIDTH = 1020;
const int HEIGHT = 640;
const int ON = 1;
const int OFF = 0;
//Main Window Widgets
Fl_Window *win = new Fl_Window(WIDTH,HEIGHT);
Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,win->w(),25);
Shop shop;


/////////////Create Part Widgets
// group list
list<Fl_Widget*> cPartView;
list<Fl_Widget*> cPartInputs;
list<Fl_Widget*> activeInputs;

//group zero
int x = 100;
int y = 100;
Fl_Input *nameInput = new Fl_Input(x,y,200,20,"Name");
Fl_Input *pNumInput = new Fl_Input(x,y+30,200,20,"Part Number");
Fl_Int_Input *weightInput = new Fl_Int_Input(x,y+60,200,20,"Weight");
Fl_Int_Input *costInput = new Fl_Int_Input(x,y+90,200,20,"Cost");
Fl_Input *descInput = new Fl_Input(x,y+120,200,20,"Description");
Fl_Button *saveButton = new Fl_Button(x+150,y+150,50,30,"Enter");
//Special part Inputs
//batteryinputs
Fl_Int_Input *batPowerInput = new Fl_Int_Input(x+350,y,200,20,"Max Power");
//Locomotor
Fl_Int_Input *maxSpeedInput = new Fl_Int_Input(x+350,y,200,20,"Max Speed");
//Battery Compartments
Fl_Int_Input *batCompartmentsInput = new Fl_Int_Input(x+350,y,200,20,"Battery Compartments (max 3)");
// Fl_Input *costInput = new Fl_Input(x,y+90,200,20,"Cost");
// Fl_Input *descInput = new Fl_Input(x,y+120,200,20,"Description");
//Create Customer Widgets

///////////////////////MISC METHODS
void toggleView(list<Fl_Widget*> ws, int isOn){
  for(Fl_Widget* w:ws){
    if(isOn){
      w->show();
    } else {
      w->hide();
    }
  }
}

void Quit_CB(Fl_Widget *, void *) {
    exit(0);
}

void addToActive(list<Fl_Widget*> toAdd){
  for(Fl_Widget* w:toAdd){
    activeInputs.push_back(w);
  }
}

///////////////////////CREATE PART VIEW CallBacks
void saveInfo_CB(Fl_Widget *w, void* p){


}

///////////////////////CREATE MENU CALLBACKS
//Create Part CallBacks
void createPart_CB(Fl_Widget *w, void* p){
  //save part_type
  int part_type = *((int*) p);
  PartType type = PartType(part_type);

  //repopulate active list
  activeInputs.clear();
  addToActive(cPartInputs);
  //for all parts, get this info
  toggleView(cPartView,ON);

  switch(part_type){
    case(1):{
        //Arm
        break;
    }
    // case(2):{
    //     //battery
    //     double max_power;
    //     cout << "Battery max power :";
    //     cin >> max_power;
    //     cin.ignore();
    //     shop.add_part(new Battery(name,id,type,weight,cost,desc,max_power));
    //     break;
    // }
    // case(3):{
    //     //head
    //     break;
    // }
    // case(4):{
    //     //locomotor
    //     int max_speed;
    //     cout << "Locomotor max speed: ";
    //     cin >> max_speed;
    //     cin.ignore();
    //     shop.add_part(new Locomotor(name,id,type,weight,cost,desc,max_speed));
    //     break;
    // }
    // case(5):{
    //     //torso
    //     int bat_comp;
    //     cout << "Number of Battery Compartments: ";
    //     cin >> bat_comp;
    //     cin.ignore();
    //     shop.add_part(new Torso(name,id,type,weight,cost,desc,bat_comp));
    //     break;
    // }
// }
   }
  // toggleView(cPartView, ON);

}

void createTorso_CB(Fl_Widget *w, void* p){

}

void createBattery_CB(Fl_Widget *w, void* p){

}

void createArm_CB(Fl_Widget *w, void* p){

}

void createLocomotor_CB(Fl_Widget *w, void* p){

}

//Create Robot callback
void createRobot_CB(Fl_Widget *w, void* p){

}

//Create Sales Associate Callback
void createSA_CB(Fl_Widget *w, void* p){

}

//create Customer Callback
void createCustomer_CB(Fl_Widget *w, void* p){

}

int main(){
  //////////Initiate part screen
  cPartView.push_back(nameInput);
  cPartView.push_back(pNumInput);
  cPartView.push_back(weightInput);
  cPartView.push_back(costInput);
  cPartView.push_back(descInput);
  cPartView.push_back(saveButton);
  cPartInputs.push_back(nameInput);
  cPartInputs.push_back(pNumInput);
  cPartInputs.push_back(weightInput);
  cPartInputs.push_back(costInput);
  cPartInputs.push_back(descInput);
  batPowerInput->hide();
  maxSpeedInput->hide();
  batCompartmentsInput->hide();
  toggleView(cPartView, 0);

  //create menu bar
  int x = 1;
  menu->add("File/Quit",   FL_CTRL+'q', Quit_CB);
  menu->add("Create/Part/Arm","+a",createPart_CB, &x);
  x++;
  menu->add("Create/Part/Battery","+b",createPart_CB, &x);
  x++;
  menu->add("Create/Part/Head",0,createPart_CB,(void*) &x);
  x++;
  menu->add("Create/Part/Locomotor","+l",createPart_CB, &x);
  x++;
  menu->add("Create/Part/Torso","+t",createPart_CB, &x);
  menu->add("Create/Robot",FL_CTRL+'r', createRobot_CB);
  menu->add("Create/Sales Associate",FL_CTRL+'s', createSA_CB);
  menu->add("Create/Customer",FL_CTRL+'c', createCustomer_CB);
  menu->add("Reports/Part");


  win->end();
  win->show();

  return Fl::run();
}
