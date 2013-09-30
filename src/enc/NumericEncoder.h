/**
 * @file NumericEncoder.h
 * @author t.j.
 * @version 2013-09
 */
#ifndef NUMERIC_ENCODER
#define NUMERIC_ENCODER

#include <sstream>
//#include <boost/lexical_cast.hpp>
#include "AbstractEncoder.h"


/**
 * @brief
 */
class NumericEncoder : AbstractEncoder<std::string, double>
{
public:
    // INSTANCE HANDLING //
    /**
     * @brief
     */
    NumericEncoder();
    
    /**
     * @brief
     * @param o
     * @param f
     */
    NumericEncoder( double o, double f );
    
    /**
     * @brief
     * @param enc
     */
    NumericEncoder( const NumericEncoder &enc );
    
    /**
     * @brief
     */
    ~NumericEncoder();
    
    /**
     * @brief
     * @param enc
     */
    NumericEncoder& operator=( const NumericEncoder &enc );

    // MEMBER HANDLING //
    /**
     * @brief
     * @return
     */
    double get_offset() const;
    
    /**
     * @brief
     * @param d
     */
    void set_offset( double d );
    
    /**
     * @brief
     * @return
     */
    double get_factor() const;
    
    /**
     * @brief
     * @param d
     */
    void set_factor( double d );
    

    // RELEVANT STUFF //
    /**
     * @brief
     * @param str
     * @return
     */
    virtual double encode( std::string str );

    /**
     * @brief
     * @param dbl
     * @return
     */
    virtual std::string decode( double dbl );
protected:
private:
    /**
     * @brief
     */
    double _offset;

    /**
     * @brief
     */
    double _factor;
};

#endif