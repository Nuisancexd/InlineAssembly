#include <iostream>


int arith_inst()
{
    int x;
    __asm
    {
        mov eax, 30000h     ; 196608
        sub eax, 10000h     ; eax - 10000h = 65536

        mov x, eax          ; x = 20000h = 131072
        neg x               ; x = -131072

        mov eax, -2
        mul x               ; eax * x =  262144
        mov x, eax
    }
    return x;
}

int main()
{

    std::cout << arith_inst();

    return 0;
}
