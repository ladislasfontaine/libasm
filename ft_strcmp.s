
section .text
	global	ft_strcmp

ft_strcmp:
	mov		cl, [rdi]	;*s1
	mov		dl, [rsi]	;*s2
	cmp		cl, 0		;if *s1 == \0
	je		end			;end
	cmp		dl, 0		;if *s2 == \0
	je		end			;end
	cmp		cl, dl		;if *s1 != *s2
	jne		end			;end
	inc		rdi			;s1++
	inc		rsi			;s2++
	jmp		ft_strcmp

end:
	movzx	rax, cl		;convert byte in 64 bits
	movzx	rcx, dl		;convert byte in 64 bits
	sub		rax, rcx	;*s1 - *s2
	ret
