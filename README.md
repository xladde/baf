# Building Automation Framework
(c) t.j. 2013 - today

## Important
A hardware abstracting framework for embedded systems. This is developed for building automation purposes.
Note that at the current state of development the sourcecode cannot be build. 

## License
This program is published under the terms of the GNU GPL3 excluding a commercial/profit-oriented use.
If you want to use this framework in a commercial context you have to buy an individual license.
Therefore please contact the administrator of this repository.

## Requires
* Doxygen 1.7 or higher
* GCC (g++)

## (try to) Build
* '$ make documentation' builds the doc inside ./doc/html. This requires Doxygen 1.7
* '$ make quick' just compiles the sources with additional gdb infos.
* '$ make all' builds the documentation and sources and strips the final binary
* '$ make clean' cleans the directory and deletes the documentation (if no deletition error occurs).
