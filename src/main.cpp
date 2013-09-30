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
    std::vector< std::string > v;
    v = list_devices(std::string( argc==2?argv[1]:"/dev" ), FT_CHR, true);
    for( std::vector< std::string >::iterator jt = v.begin();
         jt != v.end(); jt++ )
    {
        std::cout << *jt << std::endl;
    }

    return EXIT_SUCCESS;
}