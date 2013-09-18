#ifndef _SERVICE_CLASS_H_
#define _SERVICE_CLASS_H_

#include <string>
#include <sstream>
#include <fstream>
#include <type_traits> // typeinformation


/** FORWARD DECLARATIONS */
class Service;
class Driver;
class TypeConverter;
class Device;

class Driver
{
public:
    static std::string _read_raw( Device* d )
    {
        std::string   raw;
        std::ifstream input;
        if( d )
        {
            input.open( d->get_path );
            if( input.is_open() )
            {
                while( input.good() ) 
                    { str += input.get(); }
                input.close();
            } else {}
        } else {}
        return raw;
    }

    static void _write_raw( Device* d, std::string data )
    {
        std::ofstream         out;
        std::string::iterator it;
        if( d )
        {
            out.open( d->get_path() );
            if( out.is_open() )
            {
                for( it = data.begin(); it != data.end(); it++ )
                    { out.put( *it ); }
                out.sync();
                out.close();
            } else {}
        } else {}
    }
};

template < typename T >
class TypeConverter
{ //char* typename = typeid(var).name(); /* obtain class std::type_info */
public: // both unsafe! only for testing purposes! Not compatible to base types
    static std::string encode( T data )
        { return std::dynamic_cast< std::string >( data ); }
    static T decode( std::string data )
        { return std::dynamic_cast< T >( data ); }
};

class Device
{
public:
    Device(){}
    virtual ~Device(){}

    unsigned char get_basetype() const { return _type_m; }
    void set_basetype( unsigned char t ) { _type_m = t; }

    std::string get_name() const { return _name_m; }
    void set_name( std::string n ) { _name_m = n; }

    std::string get_path() const { return _path_m; }
    void set_path( std::string n ) { _path_m = n; }



private:
    unsigned char _type_m;
    std::string   _name_m;
    std::string   _path_m;
};

class Service
{
public:
    Service();
    Service( const Service& );
    virtual ~Service();

    std::vector< Device* >* get_devices() const;
    void set_devices( std::vector< Device* >* );

    void init_devices( std::string );
    void drop_devices();

    void sync();

private:
    std::vector< Device* >* _devices*
};






int main( int argc, char const *argv[] );

#endif /* _SERVICE_CLASS_H_ */