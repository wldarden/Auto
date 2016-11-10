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


using namespace std;



int main(){
    const int WIDTH = 1020;
    const int HEIGHT = 640;
    Fl_Window *win = new Fl_Window(WIDTH,HEIGHT);

    //Make Create Buttons
    int nCreateButtons = 5;
    Fl_Button *CcB = new Fl_Button(10,10,(WIDTH-20)/3,((HEIGHT-20)/nCreateButtons),"Create Customer");
    CcB->box(FL_UP_BOX);
    CcB->labelfont(FL_BOLD+FL_ITALIC);
    CcB->labelsize(18);

    Fl_Button *CsaB = new Fl_Button(10, 10+((HEIGHT-20)/nCreateButtons)*1,(WIDTH-20)/3,((HEIGHT-20)/nCreateButtons),"Create Sales Associate");
    CsaB->box(FL_UP_BOX);
    CsaB->labelfont(FL_BOLD+FL_ITALIC);
    CsaB->labelsize(18);

    Fl_Button *CpB = new Fl_Button(10, 10+((HEIGHT-20)/nCreateButtons)*2,(WIDTH-20)/3,((HEIGHT-20)/nCreateButtons),"Create Part");
    CpB->box(FL_UP_BOX);
    CpB->labelfont(FL_BOLD+FL_ITALIC);
    CpB->labelsize(18);

    Fl_Button *CoB = new Fl_Button(10, 10+((HEIGHT-20)/nCreateButtons)*3,(WIDTH-20)/3,((HEIGHT-20)/nCreateButtons),"Create Order");
    CoB->box(FL_UP_BOX);
    CoB->labelfont(FL_BOLD+FL_ITALIC);
    CoB->labelsize(18);

    //Make Report Buttons
    int nReportButtons = 5;
    Fl_Button *RcB = new Fl_Button(10+((WIDTH-20)/3)*2,10,(WIDTH-20)/3,((HEIGHT-20)/nReportButtons),"Customer Reports");
    RcB->box(FL_UP_BOX);
    RcB->labelfont(FL_BOLD+FL_ITALIC);
    RcB->labelsize(18);

    Fl_Button *RsaB = new Fl_Button(10+((WIDTH-20)/3)*2, 10+((HEIGHT-20)/nReportButtons)*1,(WIDTH-20)/3,((HEIGHT-20)/nReportButtons),"Sales Associate Reports");
    RsaB->box(FL_UP_BOX);
    RsaB->labelfont(FL_BOLD+FL_ITALIC);
    RsaB->labelsize(18);

    Fl_Button *RpB = new Fl_Button(10+((WIDTH-20)/3)*2, 10+((HEIGHT-20)/nReportButtons)*2,(WIDTH-20)/3,((HEIGHT-20)/nReportButtons),"Part Reports");
    RpB->box(FL_UP_BOX);
    RpB->labelfont(FL_BOLD+FL_ITALIC);
    RpB->labelsize(18);

    Fl_Button *RoB = new Fl_Button(10+((WIDTH-20)/3)*2, 10+((HEIGHT-20)/nReportButtons)*3,(WIDTH-20)/3,((HEIGHT-20)/nReportButtons),"Order Reports");
    RoB->box(FL_UP_BOX);
    RoB->labelfont(FL_BOLD+FL_ITALIC);
    RoB->labelsize(18);

    win->end();
    win->show();

    return Fl::run();
}
