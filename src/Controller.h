/**
 * @file        controller.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include <string>
#include <vector>
#include <map>

#include "AbstractDriver.h"
#include "AbstractDevice.h"
#include "AbstractConverter.h"

/** 
 * @brief Forward declarations of class 'AbstractDriver'.
 * @todo resolve circular dependencies in 'AbstractDriver', 'AbstractDevcie',
 * 'AbstractConverter' and 'Controller'  
 */
//class AbstractDriver;
//class AbstractDevice;
//class AbstractConverter;

/**
 *
 */
class Controller
{
public:
    // ----------------------------------------------------- Instance handling
    Controller();
    Controller( const Controller& );
    ~Controller();
    Controller& operator=( const Controller& );

    // ------------------------------------------------- Setter and Getter
    std::map<std::string, AbstractDevice* > get_devicelist() const;
    void set_devicelist( std::map<std::string, AbstractDevice* > );

    std::map< int, AbstractDriver* > get_driverlist() const;
    void set_driverlist( std::map< int, AbstractDriver* > );

    std::map< int, AbstractConverter* > get_converterlist() const;
    void set_converterlist( std::map< int, AbstractConverter* > );
 
    // ------------------------------------------------------ Member Functions
    /**
     * @brief Scans (recursively) a directory for a given filetype and stores
     *        paths in a vector.
     * @param t Identifier for filetype.
     * @param p Path to scan.
     * @param rec (Optionally) disable recursive scan (to prevent infinite loops e.g.).
     * @return a vector with filepaths of all files of the given type.
     */
    std::vector< std::string >
    list_devices( int t, std::string p, bool rec );

    /**
     * @brief Generate a Map with all possible file/device types
     * @param p Path to scan.
     * @param rec (Optionally) disable recursive scan (to prevent infinite loops e.g.). 
     * @return map with a list for each devtype.
     */
    std::map< int, std::vector< std::string > >
    map_devices( std::string p, bool rec );

    /**
     * @brief initializes Objects of Type 'AbstractDevice' from given Map.
     * @param m Sorted map of device and file paths.
     * @return corresponding object map with AbstractDevices and a name.
     */
    std::map<std::string, AbstractDevice* > 
    init_devicemap( std::map< int, std::vector< std::string > > m );

    AbstractDriver* get_driver( int );
    AbstractConverter* get_converter( int );
    AbstractDevice* get_device( std::string );

protected:
private:
    // ----------------------------------------------------- Member attributes
    std::map<std::string, AbstractDevice* >       _devices_m;
    std::map< int, AbstractDriver* >    _drivers_m;
    std::map< int, AbstractConverter* > _converter_m;
}; // end class Controller

#endif /* _CONTROLLER_H_ */