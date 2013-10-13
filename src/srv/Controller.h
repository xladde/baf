/**
 * @file Controller.h
 * @author t.j.
 * @version 2013-10
 */

#include <vector>
#include <map>
#include "../dev/XDevice.h"

class Controller
{
public:
    Controller();
    ~Controller();
protected:

private:
    std::vector< XDevice* > *_devs;
};