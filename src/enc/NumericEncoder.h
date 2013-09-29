/**
 * @file NumericEncoder.h
 * @author t.j.
 * @version 2013-09
 */
#ifndef NUMERIC_ENCODER
#define NUMERIC_ENCODER

#include <sstream>
#include "../AbstractEncoder.h"


class NumericEncoder : AbstractEncoder<std::string, double>
{
public:
    // INSTANCE HANDLING //
    NumericEncoder();
    NumericEncoder( double o, double f );
    NumericEncoder( const NumericEncoder &enc );
    ~NumericEncoder();
    NumericEncoder& operator=( const NumericEncoder &enc );

    // MEMBER HANDLING //
    double get_offset() const;
    void set_offset( double d );
    
    double get_factor() const;
    void set_factor( double d );
    

    // RELEVANT STUFF //
    virtual double encode( std::string str );
    virtual std::string decode( double dbl );
protected:
private:
    double _offset;
    double _factor;
};

#endif