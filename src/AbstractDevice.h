/**
 * @file AbstractDevice.h Header for abstract device class.
 * @author t.j.
 * @version 2013-09
 */
#ifndef ABSTRACT_DEVICE_H
#define ABSTRACT_DEVICE_H

#include <string>   // std::string lib

/**
 * @brief   (semi)Polymorph Class representing connected devices.
 * This class represents devices that are conneted to the pc.
 */
template <typename T>
class AbstractDevice
{
public:                                                   // PUBLIC MEMBERS //
    // INSTANCE HANDLING //
    /**
     * @brief   Constructor to instanciate general devices.
     * @param id    A string to identify the device. It's recommended
     *              to use a unique value.
     * @todo    Generate unique identifier for devices.
     */
    AbstractDevice( std::string id ){ _identifier = id; }

    /**
     * @brief   (Virtual) Destructor.
     * This destructor is virtual to be called on inherited destructors.
     */
    virtual ~AbstractDevice(){ /* nothing to do so far. */ }

    // MEMBER HANDLING //
    /**
     * @brief   Setter for identifier.
     * @param   String for new identifier.
     * @todo    Setter for identifier with char*-type param.
     */
    void set_identifier( std::string id ){ _identifier = id; }
    
    /**
     * @brief   Getter for identifier.
     * @return  Current identifier.
     */
    std::string get_identifier() const { return _identifier; }

    // RELEVANT STUFF //

    /**
     * @brief   Sending-Interface.
     * @param   What to send to device.
     * This pure virtual function declares an interface to inheriting classes. 
     */
    virtual void send( T signal ) = 0;
    
    /**
     * @brief   Receiviing-Interface.
     * @return  What to get from the devcie.
     * This pure virtual function declares an interface to inheriting classes. 
     */
    virtual T receive() = 0;

protected:                                            // INHERITING MEMBERS //
    /**
     * @brief   String as identifier for this instance.
     */
    std::string _identifier;
private:                                                 // PRIVATE MEMBERS //

    
};

#endif