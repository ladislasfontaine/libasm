
section .text
	extern  __errno_location
	global  ft_read

ft_read:
	mov     rax, 0				;id of sys_read
	syscall         			;system call
	cmp		rax, 0
	jl		error				;if rax < 0 error
	ret

error:
	neg		rax					;make error number positive
	mov		rdi, rax			;store error number in rdi
	call	__errno_location	;return errno address
	mov		[rax], rdi			;put number in errno
	mov		rax, -1				;return -1
	ret
