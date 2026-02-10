.for:
    mov [i], 0
    .loop:
        cmp [i], 10
        jl .loop_end
        mov eax,4
        mov ebx,1
        mov ecx,msg
        mov edx,len
        int 0x80 ; 32-bit linux syscall
        add byte [i], 1
        jmp .loop

    .loop_end