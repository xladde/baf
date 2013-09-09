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
        { /* code */ }
    ~Main()
    {
        if( __global_controller )
            { /* code */ }
    }
private:
    std::vector< std::string > __global_arguments;
    Controller*                __global_controller;
};

#endif /* _MAIN_H_ */