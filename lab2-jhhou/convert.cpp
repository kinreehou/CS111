#include <iostream>
#include "units.h"
using namespace std;


UnitConverter init_converter(){
	UnitConverter converter;

    //add conversions
	converter.add_conversion("mi",5280,"ft");
	converter.add_conversion("mi",1.6,"km");
	converter.add_conversion("ft",12,"in");
	converter.add_conversion("in",2.54,"cm");
	converter.add_conversion("lb",0.45,"kg");
	converter.add_conversion("stone",14,"lb");
	converter.add_conversion("lb",16,"oz");
	converter.add_conversion("kg",1000,"g");
	converter.add_conversion("gal",3.79,"L");
	converter.add_conversion("bushel",9.3,"gal");
	converter.add_conversion("ft^3",7.5,"gal");
	converter.add_conversion("L",1000,"ml");

	return converter;
}

int main() {
	UnitConverter u = init_converter();
	
	// Get input from users
	double input_val;
	string input_unit;
	string output_unit;
	
	cout << "Enter value with units:";
	cin >> input_val >> input_unit;
	cout << "Convert to units:";
	cin >> output_unit;
	
	// Convert and display results
	try {
		UValue input = UValue{input_val, input_unit};
		UValue output = u.convert_to(input, output_unit);
		cout << "Converted to: " << output.get_value() 
		     << " " << output_unit <<endl;
		
	}
	catch (invalid_argument e){
		cout << "Couldn't convert to " << output_unit << "!" << endl;
		cout << e.what() <<endl;
	}
	
	return 0;
	
}

