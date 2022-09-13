#include <iostream>
#include "arbitraryprecision.h"
#include <chrono>


using namespace std;
using namespace std::chrono;


int main()
{
    steady_clock::time_point start_time = steady_clock::now();  //start time count

    int size = 6;
    arbitraryprecision a[size], y[size];
    arbitraryprecision one(1), two(2), four(4), six(6), opf(4);

    a[0] = six - four * squrt(two); //calculate a0 and y0
    y[0] = squrt(two) - one;

    mpir_ui op = mpf_get_ui (opf.num);


    for(int i = 1; i < size; i++)   //iteration to get ai and yi
    {
        y[i] = (one - squrt(squrt((one - pow(y[i - 1], op))))) / (one + squrt(squrt((one - pow(y[i - 1],op)))));
        a[i] = (a[i - 1] * pow(one + y[i] , op) - expo(y[i] * (one + y[i] + y[i] * y[i]) , i) );
    }

    mpf_t pi;

    mpf_init2(pi, 10001);

    mpf_div(pi, one.num, a[size - 1].num); //get pi value

    steady_clock::time_point end_time = steady_clock::now();    //Stop time count

    long elapsed_time = duration_cast<nanoseconds>(end_time - start_time).count();  //Get elapsed time

    char* abc = NULL;

    mp_exp_t e;

    abc = mpf_get_str (NULL, &e, 10, 1001, pi); //convert pi to string

    cout << "C++ API: pi to 1,000 places: " << endl;  //Output format
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


