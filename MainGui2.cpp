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



// group list
list<Fl_Widget*> allWidgets;
list<Fl_Widget*> cPartView;
list<Fl_Widget*> cPartInputs;
list<Fl_Widget*> activeInputs;
list<Fl_Widget*> cCustInputs;
list<Fl_Widget*> cSAInputs;

/////////////Create Part Widgets
//group drawing zero
int x = 100;
int y = 100;
int currentPartType = 0;
Fl_Input *nameInput = new Fl_Input(x,y,200,20,"Name");
Fl_Input *pNumInput = new Fl_Input(x,y+30,200,20,"Part Number");
Fl_Int_Input *weightInput = new Fl_Int_Input(x,y+60,200,20,"Weight");
Fl_Int_Input *costInput = new Fl_Int_Input(x,y+90,200,20,"Cost");
Fl_Input *descInput = new Fl_Input(x,y+120,200,20,"Description");
Fl_Button *saveButton = new Fl_Button(x+150,y+150,50,30,"Create");
//Special part Inputs
//batteryinputs
Fl_Int_Input *batPowerInput = new Fl_Int_Input(x+350,y,200,20,"Max Power");
//Locomotor
Fl_Int_Input *maxSpeedInput = new Fl_Int_Input(x+350,y,200,20,"Max Speed");
//Battery Compartments
Fl_Int_Input *batCompartmentsInput = new Fl_Int_Input(x+350,y,200,20,"Bat. Slots (max 3)");

//Create Customer Widgets (also used for sales associate)
Fl_Button *saveCustButton = new Fl_Button(x+150,y+150,50,30,"Create");
Fl_Button *saveSAButton = new Fl_Button(x+150,y+150,50,30,"Create");

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

void toggleEnable(list<Fl_Widget*> ws, int isOn){
  for(Fl_Widget* w:ws){
    w = (Fl_Input*) w;
    //w->readonly(isOn);
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
  toggleEnable(cPartInputs, ON);
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
  type = PartType(currentPartType);

  switch(currentPartType){
      case(1):{
          shop.add_part(new Arm(name,id,type,weight,cost,desc));
          break;
      }
      case(2):{
          max_power = atof(batPowerInput->value());
          shop.add_part(new Battery(name,id,type,weight,cost,desc,max_power));
          break;
      }
      case(3):{
          shop.add_part(new Head(name,id,type,weight,cost,desc));
          break;
      }
      case(4):{
          max_speed = atof(maxSpeedInput->value());
          shop.add_part(new Locomotor(name,id,type,weight,cost,desc,max_speed));
          break;
      }
      case(5):{
          bat_comp = atoi(batCompartmentsInput->value());
          shop.add_part(new Torso(name,id,type,weight,cost,desc,bat_comp));
          break;
      }
  }
  toggleView(activeInputs,0);
  toggleView(cPartView,0);
}

void saveCust_CB(Fl_Widget *w, void* p){
  string name;

  name = nameInput->value();

  shop.add_customer(name);
  toggleView(allWidgets,0);
}

void saveSA_CB(Fl_Widget *w, void* p){
  string name;

  name = nameInput->value();

  shop.add_associate(name);
  toggleView(allWidgets,0);
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

//Create Robot callback
void createRobot_CB(Fl_Widget *w, void* p){

}

//Create Sales Associate Callback
void createSA_CB(Fl_Widget *w, void* p){
  setDefaults();
  toggleView(allWidgets,0);
  activeInputs.clear();
  addToActive(cSAInputs);
  saveSAButton->show();
  toggleView(cSAInputs,1);
}

//create Customer Callback
void createCustomer_CB(Fl_Widget *w, void* p){
  setDefaults();
  toggleView(allWidgets,0);
  activeInputs.clear();
  addToActive(cCustInputs);
  saveCustButton->show();
  toggleView(cCustInputs,1);
}

///////////////////////REPORT MENU CALLBACKS
//Part Report CALLBACKS
void reportParts_CB(Fl_Widget *w, void* p){
  int part_type = *((int*)p);
  vector<Part*> allParts = shop.get_parts(part_type);
  for(Part* p:allParts){
    cout << p->to_string();
  }
}

int main(){
  //create Main Screen
  int nall=0,narm=1,nbat=2,nhead=3,nloco=4,ntorso=5;
  menu->add("File/Quit",   FL_CTRL+'q', Quit_CB);
  menu->add("Create/Part/Arm","+a",createPart_CB, &narm);
  menu->add("Create/Part/Battery","+b",createPart_CB, &nbat);
  menu->add("Create/Part/Head","+h",createPart_CB, &nhead);
  menu->add("Create/Part/Locomotor","+l",createPart_CB, &nloco);
  menu->add("Create/Part/Torso","+t",createPart_CB, &ntorso);
  menu->add("Create/Robot","+r", createRobot_CB);
  menu->add("Create/Sales Associate","+s", createSA_CB);
  menu->add("Create/Customer","+c", createCustomer_CB);
  menu->add("Reports/Parts/All",FL_CTRL+'a', reportParts_CB, &nall);
  menu->add("Reports/Parts/Arms",FL_CTRL+'a', reportParts_CB, &narm);
  menu->add("Reports/Parts/Batteries",FL_CTRL+'a', reportParts_CB, &nbat);
  menu->add("Reports/Parts/Heads",FL_CTRL+'a', reportParts_CB, &nhead);
  menu->add("Reports/Parts/Locomotors",FL_CTRL+'a', reportParts_CB, &nloco);
  menu->add("Reports/Parts/Torso",FL_CTRL+'a', reportParts_CB, &ntorso);
  
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

  //////////Initiate create Customer screen
  //add parts to group list handles
  cCustInputs.push_back(nameInput);
  saveCustButton->callback(saveCust_CB);

  //////////Initiate create SA screen
  //add parts to group list handles
  cSAInputs.push_back(nameInput);
  saveSAButton->callback(saveSA_CB);

  /////////////////set global list
  addToAll(cPartView);
  addToAll(cCustInputs);
  allWidgets.push_back(saveCustButton);
  allWidgets.push_back(saveSAButton);
  allWidgets.push_back(batPowerInput);
  allWidgets.push_back(maxSpeedInput);
  allWidgets.push_back(batCompartmentsInput);



  toggleView(allWidgets,0);
  win->end();
  win->show();

  return Fl::run();
}
