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
list<Fl_Widget*> allWidgets;
list<Fl_Widget*> cPartView;
list<Fl_Widget*> cPartInputs;
list<Fl_Widget*> activeInputs;

//group drawing zero
int x = 100;
int y = 100;
int currentPartType = 0;
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
Fl_Int_Input *batCompartmentsInput = new Fl_Int_Input(x+350,y,200,20,"Bat. Slots (max 3)");

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

void addToAll(list<Fl_Widget*> toAdd){
  for(Fl_Widget* w:toAdd){
    allWidgets.push_back(w);
  }
}

void setDefaults(){
  nameInput->value("DefaultName");
  pNumInput->value("1");
  weightInput->value("1");
  costInput->value("1");
  descInput->value("DefaultDescription");
  batPowerInput->value("1");
  maxSpeedInput->value("1");
  batCompartmentsInput->value("1");
}

///////////////////////CREATE PART VIEW CallBacks
void saveInfo_CB(Fl_Widget *wid, void* p){
  //initialize input variables
  string name, desc;
  double weight, cost, max_power, bat_comp, max_speed;
  int id, batComp;
  PartType type;

  //get input Variables
  name = nameInput->value();
  id = atoi(pNumInput->value());
  weight = atof(weightInput->value());
  cost = atof(costInput->value());
  desc = descInput->value();
  max_power = atof(batPowerInput->value());
  max_speed = atof(maxSpeedInput->value());
  bat_comp = atoi(batCompartmentsInput->value());
  type = PartType(currentPartType);

  switch(currentPartType){
      case(1):{
          //Arm
          shop.add_part(new Arm(name,id,type,weight,cost,desc));
          break;
      }
      case(2):{
          //battery
          shop.add_part(new Battery(name,id,type,weight,cost,desc,max_power));
          break;
      }
      case(3):{
          //head
          shop.add_part(new Head(name,id,type,weight,cost,desc));
          break;
      }
      case(4):{
          //locomotor
          shop.add_part(new Locomotor(name,id,type,weight,cost,desc,max_speed));
          break;
      }
      case(5):{
          //torso
          shop.add_part(new Torso(name,id,type,weight,cost,desc,bat_comp));
          break;
      }
  }
  toggleView(activeInputs,0);
  toggleView(cPartView,0);
}

///////////////////////CREATE MENU CALLBACKS
//Create Part CallBacks
void createPart_CB(Fl_Widget *w, void* p){
  //reset view
  toggleView(allWidgets,0);
  //save part_type
  int part_type = *((int*) p);
  PartType type = PartType(part_type);

  //repopulate active list
  activeInputs.clear();
  addToActive(cPartInputs);
  //for all parts, get this info
  toggleView(cPartView,ON);
  setDefaults();
  currentPartType = part_type;
  switch(part_type){
    case(1):{
        //Arm
        break;
    }
    case(2):{
        //battery
        batPowerInput->show();
        activeInputs.push_back(batPowerInput);
        break;
    }
    case(3):{
        //head
        break;
    }
    case(4):{
        //locomotor
        maxSpeedInput->show();
        activeInputs.push_back(maxSpeedInput);
        break;
    }
    case(5):{
        //torso
        batCompartmentsInput->show();
        activeInputs.push_back(batCompartmentsInput);
        break;
    }
   }
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
  //create Main Screen
  int narm=1,nbat=2,nhead=3,nloco=4,ntorso=5;
  menu->add("File/Quit",   FL_CTRL+'q', Quit_CB);
  menu->add("Create/Part/Arm","+a",createPart_CB, &narm);
  menu->add("Create/Part/Battery","+b",createPart_CB, &nbat);
  menu->add("Create/Part/Head","+h",createPart_CB,(void*) &nhead);
  menu->add("Create/Part/Locomotor","+l",createPart_CB, &nloco);
  menu->add("Create/Part/Torso","+t",createPart_CB, &ntorso);
  menu->add("Create/Robot",FL_CTRL+'r', createRobot_CB);
  menu->add("Create/Sales Associate",FL_CTRL+'s', createSA_CB);
  menu->add("Create/Customer",FL_CTRL+'c', createCustomer_CB);
  menu->add("Reports/Part");

  //////////Initiate part screen
  //add parts to group list handles
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
  saveButton->callback(saveInfo_CB);
  //set view
  batPowerInput->hide();
  maxSpeedInput->hide();
  batCompartmentsInput->hide();
  toggleView(cPartView, 0);

  /////////////////set global list
  addToAll(cPartView);
  allWidgets.push_back(batPowerInput);
  allWidgets.push_back(maxSpeedInput);
  allWidgets.push_back(batCompartmentsInput);



  win->end();
  win->show();

  return Fl::run();
}
