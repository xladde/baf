/**
 * @file        protocol.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-08
 */
#ifndef _ABSTRACT_PROTOCOL_H_
#define _ABSTRACT_PROTOCOL_H_

#include "Controller.h"

class AbstractProtocol
{
public:
    AbstractProtocol();
    virtual ~AbstractProtocol();
    virtual std::string encode( std::string );
    virtual std::string decode( std::string );

}; // end class AbstractProtocol


class XProtocol : AbstractProtocol
{
public:
    XProtocol();
    XProtocol( XProtocol& ex );
    virtual ~XProtocol();
    XProtocol& operator=( const XProtocol& ex );
    virtual std::string encode( std::string );
    virtual std::string decode( std::string );
}; // end of example implementation

#endif /* _ABSTRACT_PROTOCOL_H_ */