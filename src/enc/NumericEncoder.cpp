/**
 * @file NumericEncoder.cpp
 * @author t.j.
 * @version 2013-09
 */

#include "NumericEncoder.h"
// INSTANCE HANDLING //
/**
 * 
 */
NumericEncoder::NumericEncoder()
{
    _offset = 0;
    _factor = 1;
}

/**
 * 
 */
NumericEncoder::NumericEncoder( double o, double f )
{
    _offset = o;
    _factor = f;
}

/**
 * 
 */
NumericEncoder::NumericEncoder( const NumericEncoder &enc )
{
    _offset = enc.get_offset();
    _factor = enc.get_factor();
}

/**
 * 
 */
NumericEncoder::~NumericEncoder() { /* Nothing to do so far. */ }

/**
 * 
 */
NumericEncoder& NumericEncoder::operator=( NumericEncoder const& enc )
{
    set_offset( enc.get_offset() );
    set_factor( enc.get_factor() );
    return *this;
}

// MEMBER HANDLING //
/**
 * 
 */
double NumericEncoder::get_offset() const { return _offset; }

/**
 * 
 */
void NumericEncoder::set_offset( double d ) { _offset = d; }

/**
 * 
 */
double NumericEncoder::get_factor() const { return _factor; }

/**
 * 
 */
void NumericEncoder::set_factor( double d ) { _factor = d; }
    

// RELEVANT STUFF //
/**
 * 
 */
double NumericEncoder::encode( std::string str )
{
    std::stringstream ss;
    double            converted;

    ss << str;
    ss >> converted;
    converted = (converted + _offset) * _factor;

    /**
     * @deprecated  Switched to <code>std::stringstream</code> for 
     *              string-double conversion due to bad performance of
     *              <code>boost::lexical_cast<T1>(T2 val)</code>.
     */
    // converted = boost::lexical_cast< double >( receive() );
    return converted;
}

/**
 * 
 */
std::string NumericEncoder::decode( double dbl )
{
    std::stringstream ss;
    std::string       converted;

    dbl = (dbl * (1/_factor)) - _offset;

    /**
     * @deprecated  Switched to <code>std::stringstream</code> for 
     *              string-double conversion due to bad performance of
     *              <code>boost::lexical_cast<T1>(T2 val)</code>.
     */
    // converted = boost::lexical_cast< std::string >( receive() );
    ss << dbl;
    ss >> converted;

    return converted;
}