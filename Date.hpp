//
//  Date.hpp
//
//
//  Created by Will Darden on 10/3/16.
//
//



#ifndef Date_hpp
#define Date_hpp

#include "std_lib_facilities.h"

class Date{
private:

    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        //check month
        if(m > 12 || m < 0){
            //throw bad month;
        }

        //check days
        if(d > get_ndays(m-1) || d < 0){
            //throw bad day;
        }

        //check year
        if(y > 3000 || y < 1900){
            //throw bad year;
        }
    }

    //months
    static const int jan = 1;
    static const int feb = 2;
    static const int mar = 3;
    static const int apr = 4;
    static const int may = 5;
    static const int jun = 6;
    static const int jul = 7;
    static const int aug = 8;
    static const int sep = 9;
    static const int oct = 10;
    static const int nov = 11;
    static const int dec = 12;

    //days in each month
    int get_ndays(int month){
        const int ndays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30,31,30,31};
        return ndays[month-1];
    }

    string to_string(){
        string m;
        switch(month){
            case(jan): m = "January";
            case(feb): m = "February";
            case(mar): m = "March";
            case(apr): m = "April";
            case(may): m = "May";
            case(jun): m = "June";
            case(jul): m = "July";
            case(aug): m = "August";
            case(sep): m = "September";
            case(oct): m = "October";
            case(nov): m = "November";
            case(dec): m = "December";
        }
        m = m + " " + std::to_string(day) + ", " + std::to_string(year);
        return m;
    }


};

#endif /* Date_hpp */
