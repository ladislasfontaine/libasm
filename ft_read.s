
section .text
	global ft_read

ft_read:
	mov     rax, 0	;id of sys_read
	syscall         ;system call
	jc      error	;jump if carry flag is set
	ret

error:
	mov rax, -1
	;fixer errno
