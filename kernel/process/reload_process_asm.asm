global reload_process
reload_process:
	push ebp
	mov ebp, esp
	mov esp, [ebp + 4 * 2]
	mov eax, [ebp + 4 * 3]
	push eax
	mov eax, [ebp + 4 * 4]
	mov ebp, 0
	call eax
	ret

