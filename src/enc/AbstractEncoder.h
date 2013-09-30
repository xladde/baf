/**
 * @file AbstractEncoder.h
 * @author t.j.
 * @version 2013-09
 */
#ifndef ABSTRACT_ENCODER_H
#define ABSTRACT_ENCODER_H

template < typename T1, typename T2 >
class AbstractEncoder
{
public:
    //AbstractEncoder(){}
    //virtual ~AbstractEncoder(){}
    virtual T2 encode( T1 data ) = 0;
    virtual T1 decode( T2 data ) = 0;
protected:
private:
};

#endif