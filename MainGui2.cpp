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
#include <FL/Fl_Browser.H>
#include <FL/Fl_Select_Browser.H>

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
int currentPartType = 0;
int nall=0,narm=1,nbat=2,nhead=3,nloco=4,ntorso=5,ncust=6,nsa=7;


// group list
list<Fl_Widget*> allWidgets;
list<Fl_Widget*> cPartView;
list<Fl_Widget*> cPartInputs;
list<Fl_Widget*> activeInputs;
list<Fl_Widget*> cCustInputs;
list<Fl_Widget*> cSAInputs;
list<Fl_Widget*> reportWidgets;

/////////////Create Part Widgets
//group drawing zero
int x = 100;
int y = 100;
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

/////////////Report Part Widgets
//group drawing zero
Fl_Select_Browser* reportBrowser = new Fl_Select_Browser(x+700,y,200,400,"Select Entity");
Fl_Input *numDisplay = new Fl_Input(x,y+30,200,20,"Number");

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

void toggleReadOnly(int readonly){
    nameInput->readonly(readonly);
    pNumInput->readonly(readonly);
    weightInput->readonly(readonly);
    costInput->readonly(readonly);
    descInput->readonly(readonly);
    batPowerInput->readonly(readonly);
    maxSpeedInput->readonly(readonly);
    batCompartmentsInput->readonly(readonly);
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
  name = to_string(nameInput->value());
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
  shop.add_customer(to_string(name));
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
  toggleReadOnly(OFF);
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
   toggleReadOnly(OFF);
}

//Create Robot callback
void createRobot_CB(Fl_Widget *w, void* p){

}

//Create Sales Associate Callback
void createSA_CB(Fl_Widget *w, void* p){
  setDefaults();
  toggleReadOnly(OFF);
  toggleView(allWidgets,0);
  activeInputs.clear();
  addToActive(cSAInputs);
  saveSAButton->show();
  toggleView(cSAInputs,1);
}

//create Customer Callback
void createCustomer_CB(Fl_Widget *w, void* p){
  setDefaults();
  toggleReadOnly(OFF);
  toggleView(allWidgets,0);
  activeInputs.clear();
  addToActive(cCustInputs);
  saveCustButton->show();
  toggleView(cCustInputs,1);
}

///////////////////////REPORT MENU CALLBACKS
//Part Report CALLBACKS
void reportPart_CB(Fl_Widget* wi, void* q){
  Fl_Select_Browser* w = (Fl_Select_Browser*) wi;
  toggleReadOnly(OFF);
  Part* p = (Part*) w->data(w->value());

  string name, desc, weight, cost, max_power, bat_comp, max_speed, id, batComp;
  PartType type;

  name = p->get_name();
  id = to_string(p->get_part_number());//.to_string();
  weight = to_string(p->get_weight());//.to_string();
  cost = to_string(p->get_cost());//.to_string();
  desc = p->get_description();

  //get input Variables
  nameInput->value( name.c_str());
  pNumInput->value( id.c_str());
  weightInput->value(weight.c_str());
  costInput->value(cost.c_str());
  descInput->value(desc.c_str());
  type = p->get_type();

  switch(type.get_value()){
    case(2):{
        //battery
        Battery* b = (Battery*) p;
        max_power = to_string(b->get_max_power());//.to_string();
        batPowerInput->value(max_power.c_str());
        break;
    }
    case(4):{
        //locomotor
        Locomotor* l = (Locomotor*) p;
        max_speed = to_string(l->get_max_speed());//.to_string();
        maxSpeedInput->value(max_speed.c_str());
        break;
    }
    case(5):{
        //torso
        Torso* t = (Torso*) p;
        bat_comp = to_string(t->get_max_batteries());//.to_string();
        batCompartmentsInput->value(bat_comp.c_str());
        break;
    }
  }
  toggleReadOnly(ON);
}

void reportCustomers_CB(Fl_Widget *wi, void* q){
  Fl_Select_Browser* w = (Fl_Select_Browser*) wi;
  toggleReadOnly(OFF);
  Customer p = *((Customer*) w->data(w->value()));

  string name, num;

  name = p.get_name();
  num = to_string(p.get_number());//.to_string();

  //get input Variables
  nameInput->value(name.c_str());
  numDisplay->value(num.c_str());

  toggleReadOnly(ON);
}

void reportAssociates_CB(Fl_Widget *wi, void* q){
  Fl_Select_Browser* w = (Fl_Select_Browser*) wi;
  toggleReadOnly(OFF);
  Associate p = *((Associate*) w->data(w->value()));

  string name, num;

  name = p.get_name();
  num = to_string(p.get_number());
  cout << num << "here\n";
  //get input Variables
  nameInput->value(name.c_str());
  numDisplay->value(num.c_str());

  toggleReadOnly(ON);
}

void reportParts_CB(Fl_Widget *w, void* q){
  toggleView(allWidgets,OFF);
  reportBrowser->clear();
  setDefaults();
  toggleReadOnly(ON);
  toggleView(reportWidgets,ON);
  int part_type = *((int*)q);
  if(part_type<6){
    toggleView(cPartInputs,ON);
    switch(part_type){
      case(2):{
          //battery
          batPowerInput->show();
          break;
      }
      case(4):{
          //locomotor
          maxSpeedInput->show();
          break;
      }
      case(5):{
          //torso
          batCompartmentsInput->show();
          break;
      }
    }
    vector<Part*> allParts = shop.get_parts(part_type);
    for(Part* p:allParts){
      string s = p->get_name();
      reportBrowser->add(s.c_str(),(void*) p);
    }
    reportBrowser->callback(reportPart_CB);
  }else{
    numDisplay->show();
    if(part_type==ncust){
      toggleView(cCustInputs,ON);
      vector<Customer*> allCusts = shop.get_customers();
      for(Customer* c:allCusts){
        string s = c->get_name();
        reportBrowser->add(s.c_str(),(void*) c);
      }
      reportBrowser->callback(reportCustomers_CB);
    }else if(part_type==nsa){
      toggleView(cSAInputs,ON);
      vector<Associate*> allSAs = shop.get_associates();
      for(Associate* c:allSAs){
        string s = c->get_name();
        reportBrowser->add(s.c_str(),(void*) c);
      }
      reportBrowser->callback(reportAssociates_CB);
    }
  }

}



int main(){
  //create Main Screen

  menu->add("File/Quit",   FL_CTRL+'q', Quit_CB);
  menu->add("Create/Part/Arm","+a",createPart_CB, &narm);
  menu->add("Create/Part/Battery","+b",createPart_CB, &nbat);
  menu->add("Create/Part/Head","+h",createPart_CB, &nhead);
  menu->add("Create/Part/Locomotor","+l",createPart_CB, &nloco);
  menu->add("Create/Part/Torso","+t",createPart_CB, &ntorso);
  menu->add("Create/Robot","+r", createRobot_CB);
  menu->add("Create/Sales Associate","+s", createSA_CB);
  menu->add("Create/Customer","+c", createCustomer_CB);
  menu->add("Reports/Parts/All",FL_CTRL+'z', reportParts_CB, &nall);
  menu->add("Reports/Parts/Arms",FL_CTRL+'a', reportParts_CB, &narm);
  menu->add("Reports/Parts/Batteries",FL_CTRL+'b', reportParts_CB, &nbat);
  menu->add("Reports/Parts/Heads",FL_CTRL+'h', reportParts_CB, &nhead);
  menu->add("Reports/Parts/Locomotors",FL_CTRL+'l', reportParts_CB, &nloco);
  menu->add("Reports/Parts/Torso",FL_CTRL+'t', reportParts_CB, &ntorso);
  menu->add("Reports/Customers",FL_CTRL+'c', reportParts_CB, &ncust);
  menu->add("Reports/Sales Associates",FL_CTRL+'s', reportParts_CB, &nsa);
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

  //////////Initiate reoprt screen
  numDisplay->hide();
  reportWidgets.push_back(reportBrowser);
  reportBrowser->format_char(0);
  /////////////////set global list
  addToAll(cPartView);
  addToAll(cCustInputs);
  allWidgets.push_back(saveCustButton);
  allWidgets.push_back(saveSAButton);
  allWidgets.push_back(batPowerInput);
  allWidgets.push_back(maxSpeedInput);
  allWidgets.push_back(batCompartmentsInput);
  allWidgets.push_back(reportBrowser);
  allWidgets.push_back(numDisplay);
  toggleView(allWidgets,0);
  win->end();
  win->show();

  return Fl::run();
}
