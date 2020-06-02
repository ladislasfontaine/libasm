
section .text
	extern	__errno_location
	global	ft_write

ft_write:
	mov		rax, 1				;id of sys_write
	syscall						;system call
	cmp		rax, 0
	jl		error				;if rax < 0 error
	ret

error:
	neg		rax					;make error number positive
	mov		rdi, rax			;store error number in rdi
	call	__errno_location	;get errno location
	mov		[rax], rdi			;move number in errno
	mov		rax, -1				;return -1
	ret
