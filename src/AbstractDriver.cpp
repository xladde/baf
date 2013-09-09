/**
 * @file        AbstractDriver.cpp (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#include "AbstractDriver.h"

AbstractDriver::AbstractDriver()  { /* nothing to do so far */ }
AbstractDriver::~AbstractDriver() { /* nothing to do so far */ }

void AbstractDriver::__write_raw( AbstractDevice*, std::string ) {}
std::string AbstractDriver::__read_raw( AbstractDevice* ) { return std::string(); }


// XDriver defs --------------------------------------------------------------EXAMPLE
XDriver::XDriver( Controller* c ) : AbstractDriver() 
    { _ctrl_m = c; } // no matter if (c == NULL)
XDriver::XDriver( const XDriver& d )  : AbstractDriver()
    { _ctrl_m = d.get_controller(); }
XDriver::~XDriver(){}
XDriver& XDriver::operator=( const XDriver& d ) 
{ 
    _ctrl_m = d.get_controller(); 
    return *this;
}

void XDriver::set_controller( Controller *c )   { if( c ) _ctrl_m = c; }
Controller* XDriver::get_controller() const     { return _ctrl_m; }

// USING 'XDevice' instead of Abstract Class/Interface.
void XDriver::__write_raw( XDevice* d, std::string str )
{
    std::ofstream      out;
    AbstractConverter *p;
    std::string        buf;
    if( d &&_ctrl_m )
    { // check whether 'd' and the controller are valid
        out.open( d->get_path() );
        if( out.is_open() )
        {
            /**
             * @todo Get Type of device (+ Test).
             * @todo Get corresponding Converter (Type AbstractProtocol (+ Test)).
             * @todo Encode string (+ Test).
             */
            p = _ctrl_m->get_converter( d->get_type() );
            if( p )
            {
                buf = p->encode( str );
                if( !buf.empty() ) { out << buf; }
                else { /* nothing to do */ }
            }
            else { /* nothing to do */ }
            out.close();
        } else { /* nothing to do */ }
    } else { /* nothing to do */ }
}

std::string XDriver::__read_raw( XDevice* d )
{
    std::ifstream     in;
    std::string       str, buf;
    AbstractProtocol *p;
    if( d &&_ctrl_m )
    { // check whether 'd' and the controller are valid
        in.open( d->get_path() );
        if( in.is_open() )
        {
            /**
             * @todo Get Type of device.
             * @todo Get corresponding Converter (Type AbstractProtocol).
             * @todo Decode string.
             */
            p = _ctrl_m->get_converter( d->get_type() );
            if( p )
            {
                buf = p->decode( str );
                if( !buf.empty() )
                {
                    while( in.good() )
                    { 
                        in >> buf; 
                        in.sync();
                    }
                } else { /* nothing to do */ }
            } else { /* nothing to do */ }
            in.close();
        } else { /* nothing to do */ }
    } else { /* nothing to do */ }
    return str;
}
