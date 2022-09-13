/* Author: Jingjing Bu */

#include <iostream>
#include <mpir.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main ()
{
    steady_clock::time_point start_time = steady_clock::now();  //start time count

    int size = 6;   //Iteration time = size - 1

    int precision = 4000;   //Number precision, how many bits after decimal point

    mpf_t pi, a[size], y[size], multi[size], diff[size], oneconst, twoconst, fourconst, sixconst, opf, multi1[size], multi2[size], multi3[size];
    mpf_t initsqu, initmul, squaroot[size], quaroot[size], addl[size], subl[size], addl1[size], addl2[size], squa[size], power[size];

    for (int i = 0; i < size; i++)  //Initialize all mpf variables
    {
        mpf_init2(a[i], precision);

        mpf_init2(y[i], precision);

        mpf_init2(multi[i], precision);

        mpf_init2(diff[i], precision);

        mpf_init2(squaroot[i], precision);

        mpf_init2(addl[i], precision);

        mpf_init2(subl[i], precision);

        mpf_init2(quaroot[i], precision);

        mpf_init2(addl1[i], precision);

        mpf_init2(addl2[i], precision);

        mpf_init2(squa[i], precision);

        mpf_init2(power[i], precision);

        mpf_init2(multi1[i], precision);

        mpf_init2(multi2[i], precision);

        mpf_init2(multi3[i], precision);

    }

    mpf_init2(oneconst, precision); //convert 1, 2, 4, 6 to mpf type variables
    mpf_set_d(oneconst, 1);

    mpf_init2(twoconst, precision);
    mpf_set_d(twoconst, 2);

    mpf_init2(fourconst, precision);
    mpf_set_d(fourconst, 4);

    mpf_init2(sixconst, precision);
    mpf_set_d(sixconst, 6);

    mpf_init2(initsqu, precision);  //calculate y0
    mpf_sqrt(initsqu, twoconst);
    mpf_sub(y[0], oneconst, initsqu);

    mpf_init2(initmul, precision);
    mpf_mul(initmul, fourconst, initsqu);

    mpf_sub(a[0], sixconst, initmul);   //calculate a0



    mpf_init2(opf, precision);
    mpf_set_d(opf, 4);

    mpf_init2(pi, 10001);

    mpir_ui op = mpf_get_ui (opf);


    for (int i = 1; i < size; i++ ) //calculate yi and ai
    {
        mpf_pow_ui (multi[i] , y[i-1] , op);
        mpf_sub(diff[i], oneconst, multi[i]);
        mpf_sqrt (squaroot[i] , diff[i]);
        mpf_sqrt (quaroot[i] , squaroot[i]);
        mpf_add (addl[i], oneconst, quaroot[i]);
        mpf_sub (subl[i], oneconst, quaroot[i]);
        mpf_div (y[i], subl[i], addl[i]);

        mpf_add(addl1[i], oneconst, y[i]);
        mpf_mul(squa[i], y[i], y[i]);
        mpf_pow_ui(power[i], addl1[i], op);
        mpf_mul(multi1[i], a[i-1], power[i]);

        mpf_add(addl2[i], addl1[i], squa[i]);
        mpf_mul(multi2[i], y[i], addl2[i]);

        mpf_mul_2exp(multi3[i], multi2[i], 2*i + 1);
        mpf_sub(a[i], multi1[i], multi3[i]);

    }

    mpf_div(pi, oneconst, a[size - 1]); //get pi value

    steady_clock::time_point end_time = steady_clock::now();    //Stop time count

    long elapsed_time = duration_cast<nanoseconds>(end_time - start_time).count();  //Get elapsed time

    char* abc = NULL;

    mp_exp_t e;

    abc = mpf_get_str (NULL, &e, 10, 1001, pi); //convert pi to string

    cout << "C API: pi to 1,000 places: " << endl;  //Output format
    cout << endl;
    cout << abc[0]<<".";

    for(int i = 1; i < 1001; i++)   //output 1000 digits
    {
        cout << abc[i];
        if (i%10 == 0)  //one space every 10 digits
            cout << " ";
        if (i%100 == 0) //change line every 100 digits
        {
            cout << endl;
            cout << "  ";
        }
        if (i%500 == 0) //one more line every 500 digits
        {
            cout << endl;
            cout << "  ";
        }
    }

    cout << "Elapsed time: " << elapsed_time <<" nsecs = " << static_cast<float>(elapsed_time)/1000000000 << " seconds";    //output elapsed time

    return 0;
}
