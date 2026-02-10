cmp [var], [var2]
je .if
jmp .if_end
.if:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, len
    int 0x80

.if_end:
; The rest of the code...