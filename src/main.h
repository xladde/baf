/**
 * @file main.h Header for Main-File.
 * @author t.j.
 * @version 2013-09
 */
#ifndef MAIN_H
#define MAIN_H

#include "shared.h"

/**
 * @brief Main function / Program entry point. (For testing purposes)
 * @param argc Number of arguments given at program start + 1 (proc alias).
 * @param argv Vector of arguments given at program start. This vector has a 
 *             size of '<code>argc</code>' and includes the alias of the process.
 * @return Indicator wether the program was closed correctly ('EXIT_SUCCESS') 
 *         or an error occured ('EXIT_FAILURE').
 */
int main( int argc, char **argv );


#endif