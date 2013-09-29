/**
 * @file AbstractDevice.h Header for abstract device class.
 * @author t.j.
 * @version 2013-09
 */
#ifndef ABSTRACT_DEVICE_H
#define ABSTRACT_DEVICE_H

#include <string>   // std::string lib
#include <iostream> // input/output

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

    virtual void send( T signal ) = 0;
    virtual T receive() = 0;

protected:                                            // INHERITING MEMBERS //
    /**
     * @brief   String as identifier for this instance.
     */
    std::string _identifier;
private:                                                 // PRIVATE MEMBERS //

    
};

// TEST CLASS //
// Template on how to realize chararacter devices on unix machines. //
class XDevice : AbstractDevice<std::string>
{
public:
    XDevice( std::string str ) : AbstractDevice<std::string>( str )
    { /* nothing to do so far */ }
    ~XDevice() {}

    virtual void send_signal( std::string signalstr )
    {
        std::cout << this->_identifier <<":\tsending " << signalstr << std::endl;
    }
    virtual std::string receive_signal()
    {
        std::cout << this->_identifier <<":\treceiving ... " << std::endl;
        return std::string("bla");
    }
protected:
private:
};

#endif