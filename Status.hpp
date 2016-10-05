//
//  Status.hpp
//  
//
//  Created by Will Darden on 10/3/16.
//
//

#ifndef Status_hpp
#define Status_hpp

class Status{
private:
    int value;
public:
    Status() : value(0) {}
    Status(int val) : value(val) {
        
    }
    
    static const int pending = 0;
    static const int complete = 1;
    
    string to_string(){
        switch(value){
            case(pending): return "pending";
            case(complete): return "complete";
        }
    }
    
    int get_value(){
        return value;
    }

    void set_value(int v){
        //add error checking code
        value = v;
    }


};

#endif /* Status_hpp */
