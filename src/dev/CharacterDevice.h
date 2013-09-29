/**
 * @file CharactertDevice.cpp Header for abstract device class.
 * @author t.j.
 * @version 2013-09
 */
#include <fstream> // file input-output (CPP)
#include <stdio.h> // file input-output (C)

#include "../AbstractDevice.h"

/**
 * @brief   Class CharacterDevice is a specialization of template class
 *          AbstractDevice. 
 * This class reads files of char devices on unix systems. 
 */
class CharacterDevice : AbstractDevice< std::string >
{
public:                                                   // PUBLIC MEMBERS //
    // INSTANCE HANDLING //
    /**
     * @brief   Constructor to instanciate character devices.
     * @param id    A string to identify the device. This id is given to an
     *              instance of template class 'AbstractDevice'.
     * @param loc   Location of character device on the system.
     */
    CharacterDevice( std::string id, std::string loc );  

    /**
     * @brief   (Virtual) Destructor.
     * This destructor is virtual to be called on inherited destructors.
     */
    virtual ~CharacterDevice();

    // MEMBER HANDLING //
    /**
     * @brief   getter for location of device file.
     * @return  String representing location of file.
     * @todo    Implementaion for location getter with return type 'char*'.
     */
    std::string get_location();

    /**
     * @brief   setter for location of device file.
     * @param loc   String representing location of file.
     * @todo    Implementaion for location setter with param of type 'char*'.
     */
    void set_location( std::string loc );

    // RELEVANT STUFF //

    /**
     * @brief   Function to write a string to a device.
     * @param data  String to write.
     */
    virtual void send( std::string data );
    
    /**
     * @brief   Function to read a string from a device.
     * @return  String.
     */
    virtual std::string receive();

protected:                                            // INHERITING MEMBERS //
    // INSTANCE HANDLING //
    /**
     * @brief   Second constructor.
     * @param id    Identifier for device.
     * This constructor is only allowed for directly inheriting structures.
     */
    CharacterDevice( std::string id );
    // MEMBER HANDLING //
    // RELEVANT STUFF //
private:                                                 // PRIVATE MEMBERS //
    /**
     * @brief Location of file for this instance.
     */
    std::string _location;

};