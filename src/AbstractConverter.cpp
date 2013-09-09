/**
 * @file        AbstractProtocol.cpp (GNU GPL3)
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
XProtocol::XProtocol() : AbstractConverter()
    { /* nothing to do in example */ }
XProtocol::XProtocol( XProtocol& ex ) : AbstractConverter()
    { /* nothing to do in example */ }
XProtocol::~XProtocol() 
    { /* nothing to do in example */ }
XProtocol& XProtocol::operator=( const XProtocol& ex )
    { return *this; }
std::string XProtocol::encode( std::string str )
    { return str+="ENC"; }
std::string XProtocol::decode( std::string str )
    { return str+="DEC"; }