/**
 * @file        AbstractConverter.cpp (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#include "AbstractConverter.h"

AbstractConverter::AbstractConverter()
    { /* nothing to do so far */ }
AbstractConverter::~AbstractConverter()
    { /* nothing to do so far */ }
std::string AbstractConverter::encode( std::string ) { return std::string(); }
std::string AbstractConverter::decode( std::string ) { return std::string(); }


// EXAMPLE
XConverter::XConverter() : AbstractConverter()
    { /* nothing to do in example */ }
XConverter::XConverter( XConverter& ex ) : AbstractConverter()
    { /* nothing to do in example */ }
XConverter::~XConverter() 
    { /* nothing to do in example */ }
XConverter& XConverter::operator=( const XConverter& ex )
    { return *this; }

std::string XConverter::encode( std::string str )
{ 
    str.erase( str.end()-1 );
    return str += 'E'; 
}
std::string XConverter::decode( std::string str )
{ 
    str.erase( str.end()-1 );
    return str += 'D'; 
}