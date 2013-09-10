/**
 * @file        main.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#ifndef _MAIN_H_
#define _MAIN_H_

#include "Controller.h"

class Main
{
public:
    Main( int argc, char **argv )
    {
        std::string initpath;
        __global_controller = new Controller();
        if( argc < 2 )
        {
            initpath = "../";
        } else 
        {
            for( int i = 1; i < argc; i++ )
                { __global_arguments.push_back( std::string( argv[i] ) ); }
            initpath = __global_arguments[0];
        }
        /**
         * @todo Make it Work!
         */
        __global_controller->init_devicemap
            ( __global_controller->map_devices( initpath, true ) );

        std::map< std::string, AbstractDevice*> m = __global_controller->get_devicelist();
        for( std::map< std::string, AbstractDevice*>::iterator it = m.begin();
            it != m.end(); it++ )
            { std::cout << it->first << ":\t" << it->second << std::endl; }
    }
    ~Main()
    {
        if( __global_controller )
            { delete __global_controller; }
    }
private:
    std::vector< std::string > __global_arguments;
    Controller*                __global_controller;
};

#endif /* _MAIN_H_ */