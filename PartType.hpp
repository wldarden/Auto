//
//  PartType.hpp
//  
//
//  Created by Will Darden on 10/12/16.
//
//

#ifndef PartType_hpp
#define PartType_hpp

class PartType{
private:
    int type;
public:
    static const int all = 0;
    static const int arm = 1;
    static const int battery = 2;
    static const int head = 3;
    static const int locomotor = 4;
    static const int torso = 5;
    
    PartType():type(-1) {}
    
    PartType(int t):type(t){
        if(type < 0 || type > 5){
            //throw bad parttype error
        }
    }
    
//    bool operator==(const PartType& p1, const PartType& p2) {
//        return (p1.type == p2.type);
//    }
    
    int get_value(){
        return type;
    }
    string to_string(){
        switch(type){
            case(-1):return "Uninitialized";
            case(0):return "All";
            case(1):return "Arm";
            case(2):return "Battery";
            case(3):return "Head";
            case(4):return "Locomotor";
            case(5):return "Torso";
        }
    }
};
#endif /* PartType_hpp */
