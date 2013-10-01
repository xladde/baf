/**
 * \file XDevice.h
 * \author t.j.
 * \version 2013-10
 */
#ifndef XDEVICE_H
#define XDEVICE_H

//#include <boost/lexical_cast.hpp>

#include "CharacterDevice.h"
#include "../enc/NumericEncoder.h"

//#include "AbstractDevice.h"
//#include "AbstractEncoder.h"

/**
 * \brief class XDevice as Testing-Object.
 * \todo Instanciation via Factory?
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
    /**
     * \brief   Default-Constructor.
     * \param id
     * \param loc
     * \param u
     * \param o
     * \param f
     */
    XDevice( std::string id, std::string loc, std::string u, double o, double f );
    /**
     * \brief   Constructor with lesser params.
     * \param id
     * \param loc
     * \param u
     */
    XDevice( std::string id, std::string loc, std::string u );
    /**
     * \brief   Copy-Constructor.
     * \param c
     */
    XDevice( const XDevice &c );
    /**
     * \brief Destructor.
     */
    virtual ~XDevice();
    /**
     * \brief   Assignment-Operator
     * \param c
     */
    XDevice& operator=( XDevice const& c );
    
    // MEMBER HANDLING //
    /**
     * \brief   Getter for member 'unit'.
     * \return  State/value of member 'unit'
     */
    std::string get_unit() const;
    
    /**
     * \brief   Setter for member 'unit'.
     * \param u     State/value for member 'unit'
     */
    void set_unit( std::string u );

    // RELEVANT STUFF //
    /**
     * \brief   Read out XDevice.
     * \return  Current value read from XDevice.
     */
    double get_value();
    /**
     * \brief   Set the value of XDevice.
     * \param v     Value to set.
     */
    void set_value( double v );

protected:
    // INSTANCE HANDLING //
    // MEMBER HANDLING //
    // RELEVANT STUFF //
private:
    /**
     * \brief String representation of devices unit.
     */
    std::string _unit;
};

#endif