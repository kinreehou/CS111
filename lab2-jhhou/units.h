#include <string>
#include <vector>

using namespace std;

// A unit class storing both value and the corresponding unit
class UValue{
	// the numeric value 
	double value;  
	// the unit of the value above   
	string units;     
		
	public:                          
		UValue(double value, string units);    
		
		double get_value() const;    
		string get_units() const;
		
};

// A class keeping track of all conversions
class UnitConverter{
	struct Conversion{
		// the original unit
		string from_units;
		// the multiplier to transfer from a unit to another
		double multiplier;
		// the target unit
		string to_units;
	};
	
	// @params (from_units, multiplier, to_units) example: ("mi", 1.6, "km")
	std::vector<Conversion> conversions_;
	
	public:
		void add_conversion(const 
		                    string &from_units, 
							double multiplier, 
							const string &to_units);
			
		// value and unit after conversion
		UValue convert_to(const UValue &input_val, 
		                  const string &to_units) const;
		
		
};