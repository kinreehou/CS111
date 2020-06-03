#include <iostream>
#include "units.h"
#include <fstream>
using namespace std;

/** Initialize the converter */
UnitConverter init_converter(const string &filepath){
    UnitConverter converter;
	ifstream ifs{filepath};

	/** Check if reading */
    if (!ifs) {
        throw invalid_argument("Couldn't open file");
    }

    /** Read conversion data from file until we hit EOF */
    while (ifs) {
        string from_units;
        double multiplier;
        string to_units;
        ifs >> from_units >> multiplier >> to_units;

        /** Add conversion from files */
        converter.add_conversion(from_units, multiplier, to_units);
    }


    return converter;
}

int main() {
    UnitConverter u;

	/** Try initializing the unit converter */
	try {
		u = init_converter("rules.txt");
	}
	catch (const invalid_argument &e){
		cout << e.what() << endl;
        return 1;
	}
    
    /** Get input from users */
    double input_val;
    string input_unit;
    string output_unit;
    
    cout << "Enter value with units:";
    cin >> input_val >> input_unit;
    cout << "Convert to units:";
    cin >> output_unit;
    
    /** Convert and display results */
    try {
        UValue input = UValue(input_val, input_unit);
        UValue output = u.convert_to(input, output_unit);
        cout << "Converted to: " << output.get_value() << " " <<output_unit <<endl;
        
    }
    catch (const invalid_argument &e){
        cout << "Couldn't convert to " << output_unit << "!" << endl;
        cout << e.what() <<endl;
    }
    
    return 0;
    
}

