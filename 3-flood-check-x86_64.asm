global flood_check_x86_64

flood_check_x86_64:
	xor  eax, eax	; clear register A, the output register
	xor  ecx, ecx	; clear register C, for our packed pattern
	mov  cl, dil	; copy pattern to C (1 byte)
	and  cl, 3	; mask out all but lower 2 bits
	mov  al, cl	; copy pattern to A where we'll pack it
	shl  al, 2	; shift left by 2
	or   al, cl	; OR with pattern. now 2 packed patterns in C
	shl  al, 2
	or   al, cl	; and again, now 3 packed patterns in C
	shl  al, 2
	or   al, cl	; and again, now 4 packed patterns in C
	cmp  al, sil	; compare with target in SI
	sete al		; 1 if equal
	ret
