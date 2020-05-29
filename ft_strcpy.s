
section .text
	global	ft_strcpy

ft_strcpy:
	mov		rax, rdi	;function returns dst
						;rdi == dst
						;rsi == src

loop:
	mov		cl, [rsi]	;tmp = *src
	mov		[rdi], cl	;*dst = tmp
	cmp		cl, 0		;if *src == \0
	je		end			;return
	inc		rdi			;dst++
	inc		rsi			;src++
	jmp		loop

end:
	ret
