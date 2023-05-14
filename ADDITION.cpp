#include <iostream>

int ADDITION()
{
    int sum = 0;
    __asm
    {
        mov eax, 5                  ; В регистр eax помещяем 4 байта памяти
        add eax, 6                  ; Складываем в области памяти eax
        mov sum, eax                ; переводим eax в переменную sum
    }
    return sum;
}

int main()
{

    std::cout << ADDITION();

    return 0;
}
