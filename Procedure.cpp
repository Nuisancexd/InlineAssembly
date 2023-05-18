#include <iostream>

int procedure()
{  
    int x;
    __asm
    {
        mov eax, 5
        mov ebx, 3
        call sum
                            ; eax 8
        nop
        jmp next
sum: 
        add eax, ebx
        ret

next: 
        push 5              ; push in stack 5 and 6
        push 6              ; передача параметров через стек для процедуры
        call sum2
        jmp end

sum2:
        mov eax, [esp + 4]  ; указатель стека памяти
        mov ebx, [esp + 8]
        add eax, ebx
        mov x, eax          ; 11

        ret 8               ; очистка стека - 8 байт
end:
    }
    return x;
}

int main()
{
    std::cout << procedure();
    return 0;
}
