/**
 * @file shared.h
 * @author t.j.
 * @version 2013-09
 */
#ifndef SHARED_H
#define SHARED_H

// CPP-LIBS ------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

// C-LIBS --------------------------------------------------------------------
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

// STRUCTURES, TYPEDEFS AND ENUMS --------------------------------------------
/**
 * @brief Coding Filtetypes in extra enum.
 * This extra enum, encoding DT_Filetypes is necessary due to type problems
 * in std::map with unsigned char as key type.
 */
enum FTYPE {    FT_UKN  = 0, 
                FT_DIR  = 1, 
                FT_REG  = 2, 
                FT_BLK  = 3, 
                FT_LNK  = 4, 
                FT_CHR  = 5, 
                FT_SOCK = 6, 
                FT_FIFO = 7 
            };

// FUNCTION DECLARATIONS -----------------------------------------------------
/**
 * @brief   Getting filenames associated with a special filetype.
 * @param dir   Directory to scan.
 * @param ftype What files to list.
 * @param rec   Scan recursively. Default is false.
 * @return  Vector containing Strings containing filenames.
 *
 * This function scans a given directory for a special filetype. The filetypes
 * are defined within the 'dirent.h'
 */
std::vector<std::string> 
list_files( std::string dir, unsigned char ftype, bool rec=false );

/**
 * @brief   Map all devices of a directory, sorted by their filetype.
 * @param dir   Path to the directory to scan.
 * @param rec   Wether the path should be scanned recursively.
 * @return  A Map with int values as key and string vectors containing the 
 *          filenames of each file associated to a filetype. 
 */
std::map< int, std::vector< std::string > >
map_devices( std::string dir, bool rec=true );

#endif