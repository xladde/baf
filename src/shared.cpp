/**
 * @file shared.cpp
 * @author t.j.
 * @version 2013-09
 */
#include "shared.h"

/**
 *
 */
std::vector< std::string >
list_devices( std::string p, unsigned char t, bool rec )
{
    std::vector< std::string >  v_dev;
    DIR                        *dir;
    struct dirent              *dir_ent;

    // optionally correction of path param
    if( p.at( p.length()-1 ) != '/' ) { p += '/'; }

    if( (dir = opendir( p.c_str() )) )
    {
        while( (dir_ent = readdir( dir )) )
        {
            if( (strcmp( dir_ent->d_name, "." )  == 0) || 
                (strcmp( dir_ent->d_name, ".." ) == 0) 
            ) { continue; /* ignore + jump to next */ }
            else
            {
                std::string tmp_str = p;
                tmp_str += dir_ent->d_name; 

                if( dir_ent->d_type == t )
                    { v_dev.push_back( std::string( tmp_str ) ); } 
                if( (dir_ent->d_type == DT_DIR) && rec )
                {
                    std::vector< std::string > tmp_v;
                    v_dev.push_back( std::string( tmp_str ) );
                    tmp_v = list_devices( tmp_str, t, rec );
                    v_dev.insert( v_dev.end(), tmp_v.begin(), tmp_v.end() );
                } else { continue; /* ignore + jump to next */ }
            } // end pathcheck if
        } // end while loop
        closedir( dir );
    } else { /* nothing to do */ }
    return v_dev;
}

/**
 *
 */
std::map< int, std::vector< std::string > >
map_devices( std::string p, bool rec )
{
    std::map< int, std::vector< std::string > > m_dev;
    // optionally correction of path param
    if( p.at( p.length()-1 ) != '/' ) { p += '/'; }
    m_dev.insert( make_pair( (int)FT_DIR,  list_devices( p, DT_DIR,  rec )   ));
    m_dev.insert( make_pair( (int)FT_REG,  list_devices( p, DT_REG,  rec )   ));
    m_dev.insert( make_pair( (int)FT_BLK,  list_devices( p, DT_BLK,  rec )   ));
    m_dev.insert( make_pair( (int)FT_LNK,  list_devices( p, DT_LNK,  rec )   ));
    m_dev.insert( make_pair( (int)FT_CHR,  list_devices( p, DT_CHR,  rec )   ));
    m_dev.insert( make_pair( (int)FT_SOCK, list_devices( p, DT_SOCK, rec )   ));
    m_dev.insert( make_pair( (int)FT_FIFO, list_devices( p, DT_FIFO, rec )   ));
    m_dev.insert( make_pair( (int)FT_UKN,  list_devices( p, DT_UNKNOWN, rec )));
    return m_dev;
}