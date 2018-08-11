extern printk

extern sys_restart
	
section .data
syscall_function_array dd sys_restart,
;	dd next_syscall

arraylen equ $ - syscall_function_array

invalid_syscall_msg db "Bad syscall number", 0
caller db "addr = %p\n", 0

section .text

global syscall_handler
syscall_handler:
	push ebp
	mov ebp, esp

	; we push the register to creat function parameter
	push edi
	push esi
	push edx
	push ecx
	push ebx

	; we ccheck if the syscall number existe
	cmp eax, 0
	jl syscall_invalid
	cmp eax, arraylen / 4
	jge syscall_invalid

	; we call it
	call [syscall_function_array + eax]

	jmp syscall_end

syscall_invalid:
	lea eax, [invalid_syscall_msg]
	push eax
	call printk
	mov eax, -1

syscall_end:
	mov esp, ebp
	pop ebp
	ret

global syscall
syscall:
	push ebp
	mov ebp, esp

	mov eax, [ebp + 8 + 4 * 0]
	mov ebx, [ebp + 8 + 4 * 1]
	mov ecx, [ebp + 8 + 4 * 2]
	mov edx, [ebp + 8 + 4 * 3]
	mov esi, [ebp + 8 + 4 * 4]
	mov edi, [ebp + 8 + 4 * 5]
	;int 0x80
	call syscall_handler

	mov esp, ebp
	pop ebp
	ret
