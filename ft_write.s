
section .text
	global	ft_write

ft_write:
	mov		rax, 1	;id of sys_write
	syscall			;system call
	jc		error	;jump if carry flag is set
	ret

error:
	mov		rax, -1
	;fixer errno
