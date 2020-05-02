#include <iostream>
#include "units.h"
using namespace std;


//main entry of the program, it asks users for input value and unit before converting and the unit after converting
//it will print out the value and unit after converting if the conversion can be done
//it will print out a message if the conversion cannot be done
int main() {
    double input_val;
    string input_unit;
    string output_unit;
    
    cout << "Enter value with units:";
    cin >> input_val >> input_unit;
    cout << "Convert to units:";
    cin >> output_unit;
    UValue input(input_val, input_unit);
    UValue output = convert_to(input, output_unit);

    if (output.get_units()==input_unit){
        cout << "Couldn't convert to " << output_unit << "!" <<endl;
    }
    else{
        cout << "Converted to: " << output.get_value() << " " << output_unit << endl;
    }
    

    return 0;
}

