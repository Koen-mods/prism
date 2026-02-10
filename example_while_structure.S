.while:
    .loop:
        cmp 1, 1
        jne .loop_end    ; in this case never resolves to true
        mov eax,4
        mov ebx,1
        mov ecx,msg
        mov edx,len
        int 0x80 ; 32-bit linux syscall
        jmp .loop

    .loop_end