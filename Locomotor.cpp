//
//  Locomotor.cpp
//
//
//  Created by Will Darden on 10/2/16.
//
//

#include "Locomotor.hpp"
#include "PartType.hpp"

int Locomotor::power_consumed(int speed){
    if(speed > 0 && speed <= max_speed){
        cout << "Locomotor::power_consumed() returning dummy value\n";
        return 0;
    } else if(speed <= 0){
        return 0;
    } else {
        speed = max_speed;
        cout << "Locomotor::power_consumed() returning dummy value\n";
        return 1000;
    }
}

double Locomotor::get_max_speed(){
  return max_speed;
}
