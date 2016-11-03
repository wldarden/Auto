//
//  MainGUI.cpp
//  
//
//  Created by Will Darden on 10/30/16.
//
//

#include "FL/Fl.H"

#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"

int main(){
    Fl_Window *win = new Fl_Window(340,180);
    
    Fl_Box *box = new Fl_Box(20,40,300,100,"Hello World!");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    
    win->end();
    win->show();
    
    return Fl::run();
}