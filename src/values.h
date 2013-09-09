/**
 * @file        values.h (GNU GPL3)
 * @author      t.j.
 * @version     2013-08
 */

#ifndef _VALUES_H_
#define _VALUES_H_

#include <string.h>

struct ltstr
{
    bool operator()( char *str1, char *str2 )
    { return strcmp( str1, str2 )<0?true:false; }
};

#endif /* _VALUES_H_ */