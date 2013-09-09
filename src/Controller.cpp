/**
 * @file        controller.cpp (GNU GPL3)
 * @author      t.j.
 * @version     2013-09
 */
#include "Controller.h"

/**
 *
 */
Controller::Controller() 
{
    /**
     * @todo Init Protocols.
     * @todo init Drivers.
     * ...
     */
}

/**
 *
 */
Controller::Controller( const Controller& c )
{
    this->__devices_M   = c.get_devicelist();
    this->__protocols_M = c.get_protocollist();
    this->__drivers_M   = c.get_driverlist();
}

/**
 *
 */
Controller::~Controller()
    { /* Nothing todo so far */ }

/**
 *
 */
Controller& Controller::operator=( const Controller& c )
{

    this->__devices_M   = c.get_devicelist();
    this->__protocols_M = c.get_protocollist();
    this->__drivers_M   = c.get_driverlist();
    return *this;
}


std::map< std::string, AbstractDevice* > Controller::get_devicelist() const
    { return this->__devices_M; }

void Controller::set_devicelist( std::map< std::string, AbstractDevice* > m )
    { this->__devices_M = m; }

std::map< std::string, AbstractDriver* > Controller::get_driverlist() const
    { return this->__drivers_M; }

void Controller::set_driverlist( std::map< std::string, AbstractDriver* > m )
    { this->__drivers_M = m; }

std::map< std::string, AbstractProtocol* > Controller::get_protocollist() const
    { return this->__protocols_M; }

void Controller::set_protocollist( std::map< std::string, AbstractProtocol* > m )
    { this->__protocols_M = m; }


/**
 * ** Negative Tested.
 */
std::vector< std::string >
Controller::list_devices( unsigned char t, std::string p, bool rec=true )
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
                else if( dir_ent->d_type == DT_DIR && rec )
                {
                    std::vector< std::string > tmp_v;
                    v_dev.push_back( std::string( tmp_str ) );
                    tmp_v = list_devices( t, tmp_str, rec );
                    v_dev.insert( v_dev.end(), tmp_v.begin(), tmp_v.end() );
                } else { continue; /* ignore + jump to next */ }
            } // end pathcheck if
        } // end while loop
        closedir( dir );
    } else { /* nothing to do */ }
    return v_dev;
}

/**
 * Internally calls 'std::vector< std::string > 
 * Controller::list_devices( unsigned char t, std::string p, bool rec=true )'
 * ** Negative Tested.
 */
std::map< unsigned char, std::vector< std::string > >
Controller::map_devices( std::string p, bool rec=true )
{
    std::map< unsigned char, std::vector< std::string > > m_dev;
    // optionally correction of path param
    if( p.at( p.length()-1 ) != '/' ) { p += '/'; }
    m_dev.insert( make_pair( DT_DIR, list_devices( DT_DIR, p, rec ) ) );
    m_dev.insert( make_pair( DT_REG, list_devices( DT_REG, p, rec ) ) );
    m_dev.insert( make_pair( DT_BLK, list_devices( DT_BLK, p, rec ) ) );
    m_dev.insert( make_pair( DT_LNK, list_devices( DT_LNK, p, rec ) ) );
    m_dev.insert( make_pair( DT_CHR, list_devices( DT_CHR, p, rec ) ) );
    m_dev.insert( make_pair( DT_SOCK, list_devices( DT_SOCK, p, rec ) ) );
    m_dev.insert( make_pair( DT_FIFO, list_devices( DT_FIFO, p, rec ) ) );
    m_dev.insert( make_pair( DT_UNKNOWN, list_devices( DT_UNKNOWN, p, rec ) ) );
    return m_dev;
}

std::map<std::string, AbstractDevice* > 
init_devicemap( std::map< unsigned char, std::vector< std::string > > m )
{
    std::map<std::string, AbstractDevice* >                         dev_map;
    std::map< unsigned char, std::vector< std::string > >::iterator it;
    std::vector< std::string >::iterator                            jt;

    for( it = m.begin(); it != m.end(); i++ )
    {
        for( jt = it->second.begin(); jt != it->second.end(); jt++ )
        {
            AbstractDevice *tmp = new XDevice()
        }
    }

    return dev_map;
}