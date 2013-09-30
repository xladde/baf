/**
 * @file main.cpp Implementation for Main-File.
 * @author t.j.
 * @version 2013-09
 */
#include "main.h"

#include "dev/XDevice.h"

int main( int argc, char **argv )
{
    /**
     * @todo Parse arguments.
     * @todo Scan directories.
     * @todo Scan and instanciate devices and driver
     *
     */
    XDevice *dev = new XDevice( "0001", "LOREMIPSUM", "Celsius", 1, 2 );

    std::cout << dev->receive() << std::endl;
    dev->send( "0.3" );
    std::cout << dev->receive() << std::endl;
    
    dev->set_value( 0.3 );
    std::cout << dev->get_value() << std::endl;

    delete dev;
    return EXIT_SUCCESS;
}