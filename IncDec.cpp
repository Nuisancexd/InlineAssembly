#include <iostream>


int inc_dec()
{
    int arrayB[] = {10, 20, 30, 40, 50};
    int x;
    __asm
    {
        inc[arrayB + 8]         ; arrayB[2] = 31
        mov ecx, [arrayB + 8]
        mov x, ecx
        dec x                   ; x = 30
    }
    return x;
}

int main()
{

    std::cout << inc_dec();

    return 0;
}
