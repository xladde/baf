/**
 * @file XDevice.cpp
 * @author t.j.
 * @version 2013-09
 */

#include "XDevice.h"

// INSTANCE HANDLING //
/**
 *
 */
XDevice::XDevice( 
    std::string id, std::string loc, std::string u, double o, double f 
) : CharacterDevice( id, loc ), NumericEncoder( o, f )
{
    _unit = u;
}

/**
 *
 */
XDevice::XDevice( std::string id, std::string loc, std::string u )
    : CharacterDevice( id, loc ), NumericEncoder()
{
    _unit = u;
}

/**
 *
 */
XDevice::XDevice( const XDevice &c )
    : CharacterDevice( c.get_identifier(), c.get_location() ), 
      NumericEncoder( c.get_offset(), c.get_factor() )
{
    _unit = c.get_unit();
}

/**
 *
 */
XDevice::~XDevice() { /* nothing to do so far */ }

/**
 *
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
 *
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
 *
 */
void XDevice::set_value( double v )
{
    send( decode( v ) );
}