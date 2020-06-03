#include <string>
#include <vector>
#include <set>

using namespace std;

/*! \class Uvalue
    \brief A class of value and unit

    A unit class storing both value and the corresponding unit
 */
class UValue{
	/** The numeric value */
    double value;     
	/** The unit of the value */
    string units;     
        
    public:             
		/*！ \fn UValue(double value, string units)
             \brief constructor

             \param value the numeric value 
             \param units the unit of the value
         */           
        UValue(double value, const string &units);    
        /*！\fn get_value() const
            \brief get the value
            \return the numeric value
        */
        double get_value() const;  
        /*! \fn get_units() const
            \brief get the unit
            \return the unit 
        */
        string get_units() const;
        
};

/*! \class UnitConverter 
 *  A class keeping track of all conversions */
class UnitConverter{
    struct Conversion{
        /** the unit before conversion*/
        string from_units;
        /** the multiplier of conversion*/
        double multiplier;
        /** the unit after conversion*/
        string to_units;
    };
    
    /** \params (from_units, multiplier, to_units) example: ("mi", 1.6, "km") */
    std::vector<Conversion> conversions_;
    
    public:
        /*! \fn void add_conversion(const string &from_units, 
                                double multiplier, const string &to_units)
            \brief add conversions 
            \param from_units the unit before conversion
            \param multiplier the multiplier in conversion
            \param to_units the unit after conversion
        */
        void add_conversion(const string &from_units, double multiplier, const string &to_units);
            
        /*! \fn UValue convert_to(const UValue &input_val, const string &to_units) const
            \brief Convert the original units to output units 
            \param input_val the input value and unit
            \param to_units the output unit
        */
        UValue convert_to(const UValue &input_val, const string &to_units) const;

        /*! \fn UValue convert_to(const UValue &input_val, const string &to_units, set<string> &seen) const;
            \brief Convert the original units to output units 
            \param input_val the input value and unit
            \param to_units the output unit
            \param seen the possible conversions already visited 
        */
		UValue convert_to(const UValue &input_val, const string &to_units, set<string> &seen) const;
        
        
};