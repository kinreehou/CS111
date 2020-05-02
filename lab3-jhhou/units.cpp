#include "units.h"
#include <stdexcept>


// Two-argument constructor
UValue::UValue(double value, const string units){
    this->value = value;
    this->units = units;
}

// Access the value
double UValue::get_value() const{
    return value;
}

// Access the unit
string UValue::get_units() const{
    return units;
}


/** Add new conversion pairs
    Throw invalid_arguments when the conversion pair exists*/
void UnitConverter::add_conversion(const string &from_units, double multiplier, const string &to_units) {
    // check whether the conversion pair already exists
    // cout<<"add_called"<<endl;
    for (Conversion c: conversions_){
        if (c.from_units == from_units && c.to_units == to_units){
            string msg = "Already have a conversion from" + from_units+ "to" + to_units;
            throw invalid_argument(msg);
        }
    }
        
    // Add conversion from_units->to_units and to_units->from_units
    struct Conversion c1 = {from_units, multiplier, to_units};
    struct Conversion c2 = {to_units, 1/multiplier, from_units};
    // cout<<"c1"<<c1.from_units<<" "<<c1.multiplier<<endl;
    //cout<<"c2"<<c2.from_units<< " "<<c2.multiplier<<endl;
    conversions_.push_back(c1);
    conversions_.push_back(c2);
    //cout<<"curr conversions size:"<<conversions_.size()<<endl;
}

UValue UnitConverter::convert_to(const UValue &input, const string &to_units)const {
	set<string> seen;
    return convert_to(input, to_units, seen);
}

UValue UnitConverter::convert_to(const UValue &input, const string &to_units, set<string> &seen) const{
    string from_units = input.get_units();
    seen.insert(from_units);
    
    // Successfully find a conversion
    for (Conversion c: conversions_){
        if (c.from_units == from_units){
			if (c.to_units == to_units){
				return UValue{input.get_value() * c.multiplier, to_units};
			}
			// don't know to convert, try convert to another unit first
			else if(seen.count(c.to_units)==0){
                UValue immed{input.get_value() * c.multiplier, c.to_units};
				try {
					return convert_to(immed, to_units, seen);
				}
				catch (invalid_argument){

				}
			}
		}
    }
    // Fail to find a conversion
    string msg = "Don't know how to convert from " + from_units+ " to " + to_units;
    throw invalid_argument(msg);
        
}