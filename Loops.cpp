#include <iostream>;

void Loops()
{
	int x;
	int i;
	short z;
	__asm
	{
		mov ecx, 0
		mov dword ptr[i], 0
Loop1_for:
			inc ecx
			cmp ecx, 10
			jnz Loop1_for
			mov x, ecx
Loop1_toLoop2_for:

			inc dword ptr[i]
			cmp dword ptr[i], 10
			jnz Loop1_toLoop2_for

			mov cx, 0
Loop2_toLoopz:
			cmp bx, 3					; if bx == 3 -> cx -= 1
			loopz Loop2_toLoopz
			mov z, cx
for_finish:

	}

	std::cout << i << " " << x << " " << z;
}


int main() 
{
	Loops();

	return 0;
}
