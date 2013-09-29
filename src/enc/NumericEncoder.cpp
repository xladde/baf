/**
 * @file NumericEncoder.cpp
 * @author t.j.
 * @version 2013-09
 */

#include "NumericEncoder.h"
// INSTANCE HANDLING //
NumericEncoder::NumericEncoder()
{
    _offset = 0;
    _factor = 1;
}
NumericEncoder::NumericEncoder( double o, double f )
{
    _offset = o;
    _factor = f;
}
NumericEncoder::NumericEncoder( const NumericEncoder &enc )
{
    _offset = enc.get_offset();
    _factor = enc.get_factor();
}
NumericEncoder::~NumericEncoder() { /* Nothing to do so far. */ }
NumericEncoder& NumericEncoder::operator=( const NumericEncoder &enc )
{
    _offset = enc.get_offset();
    _factor = enc.get_factor();
    return *this;
}

// MEMBER HANDLING //
double NumericEncoder::get_offset() const   { return _offset; }
void NumericEncoder::set_offset( double d ) { _offset = d; }
double NumericEncoder::get_factor() const   { return _factor; }
void NumericEncoder::set_factor( double d ) { _factor = d; }
    

// RELEVANT STUFF //
double NumericEncoder::encode( std::string str )
{
    double converted;
    /**
     * @todo Convert incoming string to a double value using factor and offset.
     */
    return converted;
}
std::string NumericEncoder::decode( double dbl )
{
    std::string converted;
    /**
     * @todo Convert incoming string to a double value using 1/factor and negative offset.
     */
    return converted;
}