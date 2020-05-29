
section .text
	global	ft_strlen

ft_strlen:
	mov		rax, 0				;len = 0

loop:
	cmp		byte[rax + rdi], 0	;if s[len] == \0
	je		end					;return len
	inc		rax					;len++
	jmp		loop

end:
	ret
