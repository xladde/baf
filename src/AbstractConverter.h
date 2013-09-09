/**
 * @file        AbstractProtocol.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#ifndef _ABSTRACT_PROTOCOL_H_
#define _ABSTRACT_PROTOCOL_H_

#include "Controller.h"

class AbstractConverter
{
public:
    AbstractConverter();
    virtual ~AbstractConverter();
    virtual std::string encode( std::string );
    virtual std::string decode( std::string );

}; // end class AbstractConverter

// XConverter Definitions ----------------------------------------------------EXAMPLE
class XConverter :AbstractConverter
{
public:
    XConverter();
    XConverter(XConverter& ex );
    virtual ~XConverter();
    XConverter&operator=( const XConverter&ex );
    virtual std::string encode( std::string );
    virtual std::string decode( std::string );
}; // end of example implementation

#endif /* _ABSTRACT_PROTOCOL_H_ */