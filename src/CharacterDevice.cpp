/**
 * @file CharacterDevice.cpp Implementation for abstract device class.
 * @author t.j.
 * @version 2013-09
 */

#include "CharacterDevice.h"

// INSTANCE HANDLING //
CharacterDevice::CharacterDevice( std::string id, std::string loc ) 
    : AbstractDevice( id ) 
{ 
    _location = loc; 
}

CharacterDevice::~CharacterDevice()
{
    /* nothing to do so far */
}

// MEMBER HANDLING //
std::string CharacterDevice::get_location(){ return _location; }
void CharacterDevice::set_location( std::string loc ){ _location = loc; }

// RELEVANT STUFF //
void CharacterDevice::send( std::string signal )
{
    std::ofstream out;

    out.open( _location );
    if( out.is_open() ) 
    { 
        out << signal; 
        out.close();
    } else { /* nothing to do so far. */ }
}

std::string CharacterDevice::receive()
{
    std::ifstream in;
    std::string buf;

    in.open( _location );
    if( in.is_open() )
    {
        while( in.good() )
        { 
            in >> buf; 
            in.sync();
        }
        in.close();
    } else { /* nothing to do so far. */ }
    return buf;
}
