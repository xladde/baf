/**
 * @file        AbstractDriver.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#ifndef _ABSTRACT_DRIVER_H_
#define _ABSTRACT_DRIVER_H_

#include <fstream>

#include "Controller.h"
#include "AbstractDevice.h"

/** 
 * @brief Forward declarations of class 'AbstractDriver'.
 * @todo resolve circular dependencies in 'AbstractDriver', 'AbstractDevcie',
 * 'AbstractProtocol' and 'Controller'  
 */
class Controller;
class AbstractProtocol;
class AbstractDevice;
    class XDevice;
/**
 * @brief Abstract class for 'Driver' objects.
 */
class AbstractDriver
{
public:
    // ----------------------------------------------------- Instance handling
    AbstractDriver();
    virtual ~AbstractDriver();

    // ------------------------------- Abstract ([pure] virtual) I/O-Functions
    virtual void __write_raw( AbstractDevice*, std::string );
    virtual std::string __read_raw( AbstractDevice* );
};


// XDriver declarations ------------------------------------------------------
class XDriver : AbstractDriver
{
public:
    XDriver( Controller* );
    XDriver( const XDriver& );
    virtual ~XDriver();
    XDriver& operator=( const XDriver& );

    void set_controller( Controller *c );
    Controller* get_controller() const;

    // USING 'XDevice' instead of Abstract Class/Interface.
    void __write_raw( XDevice*, std::string );
    std::string __read_raw( XDevice* );

private:
    Controller *_ctrl_m;
};


#endif /* _ABSTRACT_DRIVER_H_ */