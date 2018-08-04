section .text
	global get_esp
	global set_esp
	global get_ebp
	global set_ebp
	global halt

get_esp:
	mov eax, esp
	ret

set_esp:
	mov esp, eax
	ret

get_ebp:
	mov eax, ebp
	ret

set_ebp:
	mov ebp, eax
	ret

halt:
	hlt
	ret
