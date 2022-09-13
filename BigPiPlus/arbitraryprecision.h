//
// Created by Jingjing Bu on 3/28/20.
//

#ifndef BIGPIPLUS_ARBITRARYPRECISION_H
#define BIGPIPLUS_ARBITRARYPRECISION_H

#include <mpirxx.h>
#include <mpir.h>

class arbitraryprecision
{
public:
    mpf_t num{};

    arbitraryprecision();
    explicit arbitraryprecision(float number);

    friend arbitraryprecision operator + (const arbitraryprecision & ap1, const arbitraryprecision & ap2);
    friend arbitraryprecision operator - (const arbitraryprecision & ap1, const arbitraryprecision & ap2);
    friend arbitraryprecision operator * (const arbitraryprecision & ap1, const arbitraryprecision & ap2);
    friend arbitraryprecision operator / (const arbitraryprecision & ap1, const arbitraryprecision & ap2);
    friend arbitraryprecision pow (const arbitraryprecision & ap1, mpir_ui op);
    friend arbitraryprecision squrt (const arbitraryprecision & ap1);
    friend arbitraryprecision expo(const arbitraryprecision & ap1, int i);

};


#endif //BIGPIPLUS_ARBITRARYPRECISION_H
