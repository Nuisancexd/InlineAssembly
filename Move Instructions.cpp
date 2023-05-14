#include <iostream>


int mov_instructions()
{
    int arrayB[] = {10, 20, 30, 40, 50};

    __asm
    {
        ; MOVZX
        mov     bx, 0A69Bh
        movzx   eax, bx         ; EAX = 0000A69Bh
        movzx   edx, bl         ; EDX = 0000009Bh
        movzx   cx, bl          ; CX = 009Bh

        ; MOVSX
        mov     bx, 0A69Bh
        movsx   eax, bx         ; EAX = FFFFA69Bh
        movsx   edx, bl         ; EDX = FFFFFF9Bh
        mov     bl, 7Bh
        movsx   cx, bl          ; CX = 007Bh

        ; Memory - to - memory exchange
        mov     al, 1000h       ; al = 1000h - 4096
        mov     ah, 2000h       ; ah = 2000h - 8192

        xchg    al, ah          ; al = 2000h, ah = 1000h

        ; Direct - Offset Addressing(4 byte array)
        mov ecx, [arrayB]       ; arrayB[0] = 10
                                ; moves integer(4 byte) from array to register
        mov ecx, [arrayB + 4]   ; arrayB[1] = 20
        mov ecx, [arrayB + 8]   ; arrayB[2] = 30
    }
}

int main()
{

    std::cout << mov_instructions();

    return 0;
}
