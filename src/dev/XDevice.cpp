/**
 * @file XDevice.cpp
 * @author t.j.
 * @version 2013-09
 */

#include "XDevice.h"

// INSTANCE HANDLING //
/**
 * This constructor calls the default constructors in class 'CharacterDevice' 
 * (parameters: 'id' and 'loc') and class 'NumericEncoder' (parameters: 'o' and 'f').
 * After that the member variable 'unit' is set.
 */
XDevice::XDevice( 
    std::string id, std::string loc, std::string u, double o, double f 
) : CharacterDevice( id, loc ), NumericEncoder( o, f )
{
    _unit = u;
}

/**
 * This constructor calls the default constructors in class 'CharacterDevice' 
 * (parameters: 'id' and 'loc') and class 'NumericEncoder' (no parameters).
 * After that the member variable 'unit' is set.
 */
XDevice::XDevice( std::string id, std::string loc, std::string u )
    : CharacterDevice( id, loc ), NumericEncoder()
{
    _unit = u;
}

/**
 * The copy constructor instanciates 'this' object with the state of another
 * instance of type 'XDevice.
 */
XDevice::XDevice( const XDevice &c )
    : CharacterDevice( c.get_identifier(), c.get_location() ), 
      NumericEncoder( c.get_offset(), c.get_factor() )
{
    _unit = c.get_unit();
}

/**
 * Destructor frees ressorces.
 */
XDevice::~XDevice() { /* nothing to do so far */ }

/**
 * Assignment-Operator sets the state of 'this' instance to the state of another
 * instance of type XDevice. It returns the address in memory of 'this' object.
 */
XDevice& XDevice::operator=( const XDevice &c )
{
    set_identifier( c.get_identifier() );
    set_location(   c.get_location()   );
    set_unit(       c.get_unit()       );
    set_factor(     c.get_factor()     );
    set_offset(     c.get_offset()     );
    return *this;
}
    
// MEMBER HANDLING //
/**
 * 
 */
std::string XDevice::get_unit() const { return _unit; }

/**
 *
 */
void XDevice::set_unit( std::string u ) { _unit = u; }

// RELEVANT STUFF //
/**
 * This member reads out the raw data of the device and converts it into
 * another format. 
 */
double XDevice::get_value()
{
    std::stringstream ss;
    double            value;

    /**
     * @depricated  Switched to StringStream due to bad performance of
     *              boost::lexical_cast< T1 >( T2 arg )
     */
    // value = boost::lexical_cast< double >( receive() );
    ss << receive();
    ss >> value;
    value = encode( receive() );
    return value;
}

/**
 * This function sends the converted value to the device.
 */
void XDevice::set_value( double v )
{
    send( decode( v ) );
}