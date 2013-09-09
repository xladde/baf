/**
 * @file        AbstractDevice.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#ifndef _ABSTRACT_DEVICE_H_
#define _ABSTRACT_DEVICE_H_

#include <string>
#include "AbstractDriver.h"



/** 
 * @brief Forward declaration of class 'AbstractDriver'.
 * @todo resolve circular dependency in 'AbstractDriver' and 'AbstractDevcie'.  
 */
class AbstractDriver;


class AbstractDevice
{
public:
    // ------------------------------------------------- Instance handling
    AbstractDevice();
    virtual ~AbstractDevice();
    /*struct cmpstruct
    {
        bool operator( AbstractDevice* a1, AbstractDevice* a2 )
            { return a1==a2?true:false; }
    };*/

    // -------------------------------------------------- Member Functions
    virtual void open();
    virtual bool is_open();
    virtual void close();
    virtual std::string read_device( void );
    virtual void write_device( std::string );
};

// EXAMPLE
class XDevice : public AbstractDevice
{
public:
    XDevice();
    XDevice( std::string, unsigned char, AbstractDriver* );
    XDevice(const XDevice& );
    virtual ~XDevice();
    XDevice& operator=( const XDevice& );

    void set_path( std::string );
    std::string get_path() const;

    void set_type( unsigned char );
    unsigned char get_type() const;
    
    void set_driver( AbstractDriver* );
    AbstractDriver* get_driver() const;
        
    void open();
    bool is_open();
    void close();

    std::string read_device( void );
    void write_device( std::string );

private:
    std::string     _path_m;
    unsigned char   _type_m;
    AbstractDriver *_driver_m;
};

#endif /* _ABSTRACT_DEVICE_H_ */