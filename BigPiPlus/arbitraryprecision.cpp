//
// Created by Jingjing Bu on 3/28/20.
//

#include "arbitraryprecision.h"

arbitraryprecision::arbitraryprecision()    //default constructor
{
    int precision = 4000;
    mpf_init2(num, precision);
    mpf_set_d(num,0);

}

arbitraryprecision::arbitraryprecision(float number)    //constructor
{
    int precision = 4000;
    mpf_init2(num, precision);
    mpf_set_d(num, number);
}

arbitraryprecision operator + (const arbitraryprecision & ap1, const arbitraryprecision & ap2)  //overload +
{
    arbitraryprecision sum(0);
    mpf_add(sum.num, ap1.num, ap2.num);
    return sum;
}

arbitraryprecision operator - (const arbitraryprecision & ap1, const arbitraryprecision & ap2)   //overload -
{
    arbitraryprecision sub(0);
    mpf_sub(sub.num, ap1.num, ap2.num);
    return sub;
}

arbitraryprecision operator * (const arbitraryprecision & ap1, const arbitraryprecision & ap2)   //overload *
{
    arbitraryprecision multi(0);
    mpf_mul(multi.num, ap1.num, ap2.num);
    return multi;
}

arbitraryprecision operator / (const arbitraryprecision & ap1, const arbitraryprecision & ap2)   //overload /
{
    arbitraryprecision divide(0);
    mpf_div(divide.num, ap1.num, ap2.num);
    return divide;
}

arbitraryprecision pow (const arbitraryprecision & ap1, mpir_ui op) //overload pow function
{
    arbitraryprecision power(0);
    mpf_pow_ui(power.num,ap1.num, op);
    return power;
}

arbitraryprecision squrt (const arbitraryprecision & ap1)   //rewrite  sqrt function
{
    arbitraryprecision root(0);
    mpf_sqrt(root.num, ap1.num);
    return root;
}

arbitraryprecision expo(const arbitraryprecision & ap1, int i)  //num * 2^(2*i + 1)
{
    arbitraryprecision expon(0);
    mpf_mul_2exp(expon.num, ap1.num, 2*i + 1);
    return expon;
}