/**
 * @file XDevice.h
 * @author t.j.
 * @version 2013-09
 */
#ifndef XDEVICE_H
#define XDEVICE_H

//#include <boost/lexical_cast.hpp>

#include "CharacterDevice.h"
#include "../enc/NumericEncoder.h"

//#include "AbstractDevice.h"
//#include "AbstractEncoder.h"

/**
 * @brief class XDevice as Testing-Object.
 * @todo Instanciation via Factory?
 *
 * This class is for testing purposes only. It encapsulates a Character-Device
 * with an encoder for direct access of the devices numeric value.
 */
//class XDevice : AbstractDevice< std::string >,
//                AbstractEncoder< std::string, double >
class XDevice : public CharacterDevice, 
                public NumericEncoder
{
public:
    // INSTANCE HANDLING //
    XDevice( std::string id, std::string loc, std::string u, double o, double f );
    XDevice( std::string id, std::string loc, std::string u );
    XDevice( const XDevice &c );
    virtual ~XDevice();
    XDevice& operator=( XDevice const& c );
    
    // MEMBER HANDLING //
    std::string get_unit() const;
    void set_unit( std::string u );

    // RELEVANT STUFF //
    double get_value();
    void set_value( double v );

protected:
    // INSTANCE HANDLING //
    // MEMBER HANDLING //
    // RELEVANT STUFF //
private:
    std::string _unit;
};

#endif