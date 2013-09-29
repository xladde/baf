/**
 * @file Channel.h
 * @author t.j.
 * @version 2013-09
 */
#ifndef CHANNEL_H
#define CHANNEL_H

#include "dev/CharacterDevice.h"
#include "enc/NumericEncoder.h"

class Channel : CharacterDevice, NumericEncoder
{
public:
    // INSTANCE HANDLING //
    Channel( std::string id, std::string loc, std::string u, double o, double f );
    Channel( std::string id, std::string loc, std::string u );
    Channel( const Channel &c );
    virtual ~Channel();
    Channel& operator=( const Channel &c );
    
    // MEMBER HANDLING //
    std::string get_unit() const;
    void set_unit( std::string u );

    // RELEVANT STUFF //
protected:
    // INSTANCE HANDLING //
    // MEMBER HANDLING //
    // RELEVANT STUFF //
private:
    std::string _unit;
};

#endif