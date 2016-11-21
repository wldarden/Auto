//
//  MainGUI.cpp
//
//
//  Created by Will Darden on 10/30/16.
//
//

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <List>

using namespace std;

list<Fl_Widget*> mainWs;
list<Fl_Widget*> create1Ws;//page one of create menu.

//Screen display functions
void toggleView(list<Fl_Widget*> ws){
  for(Fl_Widget* w:ws){
    if(w->visible()){
      w->hide();
    } else {
      w->show();
    }
  }
}

//Main Create Button CallBacks
void create_CB(Fl_Widget* w, void* buttonID)
{
  toggleView(mainWs);
  toggleView(create1Ws);
  fprintf(stderr, "So you want to create something ay?\n");
}

//Main Report Button CallBacks
void report_CB(Fl_Widget* w, void* buttonID)
{
  toggleView(mainWs);
  fprintf(stderr, "Button worasdfasdfreportfailks!\n");
}

//Create Part Callbacks
void createPart_CB(Fl_Widget* w, void* buttonID)
{
  Fl_Window *createPartWin = new Fl_Window(300,200);
  createPartWin->end();
  createPartWin->show();
  fprintf(stderr, "Button worasdfasdfreportfailks!\n");
}


int main(){
    const int WIDTH = 1020;
    const int HEIGHT = 640;
    Fl_Window *win = new Fl_Window(WIDTH,HEIGHT);

    ///////////////////////////////////
    ///////////////////////////////////
    //Widgets names are formatted by (SCREEN)(subgroup_subsubgroup_)(function/id)(type)
    //so Mc_saB is on the (M)ain page, in the (c)reate subgroup, is a (s)ales (a)ssociate function, and is a (B)utton.
    ///////////////////////////////////
    ///////////////////////////////////

    //Make main Create Buttons
    Fl_Button *Mc_cB = new Fl_Button(10,10,(WIDTH-20)/3,((HEIGHT-20)/4),"Create Customer");
    Mc_cB->box(FL_UP_BOX);
    Mc_cB->labelfont(FL_BOLD+FL_ITALIC);
    Mc_cB->labelsize(18);
    Mc_cB->callback(create_CB,(void*) 0);
    mainWs.push_back(Mc_cB);

    Fl_Button *Mc_saB = new Fl_Button(10, 10+((HEIGHT-20)/4)*1,(WIDTH-20)/3,((HEIGHT-20)/4),"Create Sales Associate");
    Mc_saB->box(FL_UP_BOX);
    Mc_saB->labelfont(FL_BOLD+FL_ITALIC);
    Mc_saB->labelsize(18);
    Mc_saB->callback(create_CB,(void*) 1);
    mainWs.push_back(Mc_saB);

    Fl_Button *Mc_pB = new Fl_Button(10, 10+((HEIGHT-20)/4)*2,(WIDTH-20)/3,((HEIGHT-20)/4),"Create Part");
    Mc_pB->box(FL_UP_BOX);
    Mc_pB->labelfont(FL_BOLD+FL_ITALIC);
    Mc_pB->labelsize(18);
    Mc_pB->callback(create_CB,(void*) 2);
    mainWs.push_back(Mc_pB);

    Fl_Button *Mc_oB = new Fl_Button(10, 10+((HEIGHT-20)/4)*3,(WIDTH-20)/3,((HEIGHT-20)/4),"Create Order");
    Mc_oB->box(FL_UP_BOX);
    Mc_oB->labelfont(FL_BOLD+FL_ITALIC);
    Mc_oB->labelsize(18);
    Mc_oB->callback(create_CB,(void*) 3);
    mainWs.push_back(Mc_oB);

    //Make main Report Buttons
    Fl_Button *RcB = new Fl_Button(10+((WIDTH-20)/3)*2,10,(WIDTH-20)/3,((HEIGHT-20)/4),"Customer Reports");
    RcB->box(FL_UP_BOX);
    RcB->labelfont(FL_BOLD+FL_ITALIC);
    RcB->labelsize(18);
    RcB->callback(report_CB,(void*) 0);
    mainWs.push_back(RcB);

    Fl_Button *Mr_saB = new Fl_Button(10+((WIDTH-20)/3)*2, 10+((HEIGHT-20)/4)*1,(WIDTH-20)/3,((HEIGHT-20)/4),"Sales Associate Reports");
    Mr_saB->box(FL_UP_BOX);
    Mr_saB->labelfont(FL_BOLD+FL_ITALIC);
    Mr_saB->labelsize(18);
    Mr_saB->callback(report_CB,(void*) 1);
    mainWs.push_back(Mr_saB);

    Fl_Button *Mr_pB = new Fl_Button(10+((WIDTH-20)/3)*2, 10+((HEIGHT-20)/4)*2,(WIDTH-20)/3,((HEIGHT-20)/4),"Part Reports");
    Mr_pB->box(FL_UP_BOX);
    Mr_pB->labelfont(FL_BOLD+FL_ITALIC);
    Mr_pB->labelsize(18);
    Mr_pB->callback(report_CB,(void*) 2);
    mainWs.push_back(Mr_pB);

    Fl_Button *Mr_oB = new Fl_Button(10+((WIDTH-20)/3)*2, 10+((HEIGHT-20)/4)*3,(WIDTH-20)/3,((HEIGHT-20)/4),"Order Reports");
    Mr_oB->box(FL_UP_BOX);
    Mr_oB->labelfont(FL_BOLD+FL_ITALIC);
    Mr_oB->labelsize(18);
    Mr_oB->callback(report_CB,(void*) 3);
    mainWs.push_back(Mr_oB);

    //make create part display
    Fl_Button *C1aB = new Fl_Button(10+((WIDTH-20)/5)*1, HEIGHT-200,(WIDTH-20)/3,((HEIGHT-20)/4),"Create Part");
    C1aB->box(FL_UP_BOX);
    C1aB->labelfont(FL_BOLD+FL_ITALIC);
    C1aB->labelsize(18);
    C1aB->callback(report_CB,(void*) 3);
    create1Ws.push_back(C1aB);

    win->end();
    win->show();

    return Fl::run();
}
