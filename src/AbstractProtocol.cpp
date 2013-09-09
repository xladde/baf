#include "AbstractProtocol.h"

AbstractProtocol::AbstractProtocol()
    { /* nothing to do so far */ }
AbstractProtocol::~AbstractProtocol()
    { /* nothing to do so far */ }
std::string AbstractProtocol::encode( std::string ) { return std::string(); }
std::string AbstractProtocol::decode( std::string ) { return std::string(); }


// EXAMPLE
XProtocol::XProtocol() : AbstractProtocol()
    { /* nothing to do in example */ }
XProtocol::XProtocol( XProtocol& ex ) : AbstractProtocol()
    { /* nothing to do in example */ }
XProtocol::~XProtocol() 
    { /* nothing to do in example */ }
XProtocol& XProtocol::operator=( const XProtocol& ex )
    { return *this; }
std::string XProtocol::encode( std::string str )
    { return str+="ENC"; }
std::string XProtocol::decode( std::string str )
    { return str+="DEC"; }