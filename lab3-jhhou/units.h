#include <string>
#include <vector>
#include <set>

using namespace std;

// A unit class storing both value and the corresponding unit
class UValue{
	// The numeric value
    double value;     
	// The unit of the value
    string units;     
        
    public:             
		// Constructor             
        UValue(double value, string units);    
        // Getters
        double get_value() const;    
        string get_units() const;
        
};

// A class keeping track of all conversions
class UnitConverter{
    struct Conversion{
        string from_units;
        double multiplier;
        string to_units;
    };
    
    // @params (from_units, multiplier, to_units) example: ("mi", 1.6, "km")
    std::vector<Conversion> conversions_;
    
    public:
        void add_conversion(const string &from_units, double multiplier, const string &to_units);
            
        // Convert the original units to output units
        UValue convert_to(const UValue &input_val, const string &to_units) const;
		UValue convert_to(const UValue &input_val, const string &to_units, set<string> &seen) const;
        
        
};