/**
 * @file        AbstractDevice.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#include "AbstractDevice.h"


// AbstractDevcie defs -------------------------------------------------------
AbstractDevice::AbstractDevice()  {}
AbstractDevice::~AbstractDevice() {}

void AbstractDevice::open()                      {}
bool AbstractDevice::is_open()                   { return true; }
void AbstractDevice::close()                     {}
std::string AbstractDevice::read_device( void )  { return std::string(); }
void AbstractDevice::write_device( std::string ) {}

// XDevice defs --------------------------------------------------------------
XDevice::XDevice() { _driver_m = NULL; }

XDevice::XDevice( std::string p, unsigned char t, AbstractDriver* d ) 
: AbstractDevice() 
{ 
    _path_m = p;
    _type_m = t;
    _driver_m = d; 
}

XDevice::XDevice( const XDevice& d ) 
: AbstractDevice() 
{ 
    _path_m = d.get_path();
    _type_m = d.get_type();
    _driver_m = d.get_driver();
}

XDevice::~XDevice() {}

XDevice& XDevice::operator=( const XDevice& d )
{
    std::string buf = d.get_path();
    _path_m = d.get_path();
    _type_m = d.get_type();
    _driver_m = d.get_driver();
    return (*this);
}

void XDevice::set_path( std::string p )         { _path_m = p; }
std::string XDevice::get_path() const                { return _path_m; }

void XDevice::set_type( unsigned char t )       { _type_m = t; }
unsigned char XDevice::get_type() const               { return _type_m; }
    
void XDevice::set_driver( AbstractDriver* d )   { if( d ) _driver_m = d; }
AbstractDriver* XDevice::get_driver() const           { return _driver_m; }
    
void XDevice::open()                            {}
bool XDevice::is_open()                         { return true; }
void XDevice::close()                           {}

std::string XDevice::read_device( void ) 
{
    std::string str;
    if( _driver_m ) 
        { str = _driver_m->__read_raw( this ); }
    return str;
}

void XDevice::write_device( std::string str ) 
{ 
    if( _driver_m ) 
        { _driver_m->__write_raw( this, str ); }
}