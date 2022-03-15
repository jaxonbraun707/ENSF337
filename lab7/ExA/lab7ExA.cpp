// ENSF 337 - Lab 7 exercise A

#include "cplx.h"
#include <iostream>
using namespace std;

void global_print(const Cplx& n);

int main(void)
{
    Cplx num1;
    global_print(num1);
    num1.setRealPart(666);
    
    Cplx num2(34, 5);

    num1.setImaginaryPart(500);

    global_print(num1);
    global_print(num2);
    
    return 0;
}

void global_print(const Cplx& n){
    cout << n.getRealPart() << "+" << n.getImaginaryPart() << "i" << endl;
}

