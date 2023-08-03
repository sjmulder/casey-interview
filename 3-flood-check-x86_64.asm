flood_check:
	xor eax, eax
	xor ecx, ecx
	mov al, sil
	and al, 3
	mov cl, al
	shl cl, 2
	or  cl, al
	shl cl, 2
	or  cl, al
	shl cl, 2
	or  cl, al
	xor al, dil
	ret
