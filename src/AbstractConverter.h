/**
 * @file        AbstractConverter.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#ifndef _ABSTRACT_CONVERTER_H_
#define _ABSTRACT_CONVERTER_H_

#include "Controller.h"

template <typename T1, typename T2>
class AbstractConverter
{
public:
    AbstractConverter();
    virtual ~AbstractConverter();
    virtual T1 encode( T2 data ) = 0;
    virtual T2 decode( T1 data ) = 0;
}; // end class AbstractConverter

// XConverter Declarations ---------------------------------------------------EXAMPLE
class XConverter : public AbstractConverter< std::string, std::string >
{
public:
    XConverter();
    XConverter(XConverter& ex );
    virtual ~XConverter();
    XConverter&operator=( const XConverter& ex );
    virtual std::string encode( std::string );
    virtual std::string decode( std::string );
}; // end of example implementation




#endif /* _ABSTRACT_CONVERTER_H_ */