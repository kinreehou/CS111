#include<string>
using namespace std;

// A unit class storing both value and the corresponding unit
class UValue{
    // the numeric value 
    double value;   
    //  the unit of the value above
    string units;     
        
    public:                       
        UValue(double value, string units);    
        
        ~UValue();         
        
        double get_value();    
        string get_units();
        
};

// A function to convert the units
UValue convert_to(UValue input, string to_units);