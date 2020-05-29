
section .text
	extern	ft_strlen
	extern	ft_strcpy
	extern	malloc
	global	ft_strdup

ft_strdup:
	push	rdi			;save rdi on the stack
	call	ft_strlen	;get length of s1
	inc		rax			;add 1 for \0
	mov		rdi, rax	;move s1 length in first arg
	call	malloc		;malloc size
	cmp		rax, 0		;if malloc == NULL
	je		end			;return
	pop		rdi			;get string to duplicate
	mov		rsi, rdi	;save it in second arg
	mov		rdi, rax	;save memory zone in first arg
	call	ft_strcpy	;cpy in the new memory zone

end:
	ret
