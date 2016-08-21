	.file	"hello-world.c"
	.section	.rodata
.LC0:
	.string	"I am good \n"
.LC1:
	.string	"hello, world\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$20, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	call	write
	movl	$14, %ecx
	movl	$.LC1, %edx
	movl	$1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	syscall
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-9)"
	.section	.note.GNU-stack,"",@progbits
