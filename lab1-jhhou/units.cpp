#include "units.h"


// Two-argument constructor
UValue::UValue(double value, string units){
    this->value = value;
    this->units = units;
}

// Cleans up
UValue::~UValue(){
    // Nothing to do
}

// Access the value
double UValue::get_value(){
    return value;
}

// Access the unit
string UValue::get_units(){
    return units;
}

// convert from one unit to another, if not able to, return value in original unit
UValue convert_to(UValue input, string to_units){
    if (input.get_units() == "lb" and to_units == "kg"){
        double converted_val = input.get_value()*0.45;
        UValue output{converted_val, to_units};                //use curly braces for initialization
        return output;
    }

    else if (input.get_units() == "gal" and to_units == "L"){
        double converted_val = input.get_value()*3.79;
        UValue output{converted_val, to_units};       
        return output;

    }
    else if (input.get_units() == "mi" and to_units == "km"){
        double converted_val = input.get_value()*1.6;
        UValue output{converted_val, to_units};
        return output;
    }
    
    else{
        
        return input;
    }
}