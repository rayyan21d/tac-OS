section .asm

global in_byte
global in_word
global out_byte
global out_word


; Always good to initialize a satck frame
in_byte:
    push ebp
    mov ebp, esp

    xor eax, eax     ; The eax is always the return value
    mov edx, [ebp+8] ; Destination
    in al, dx

    pop ebp
    ret


in_word:
    push ebp
    mov ebp, esp

    xor eax, eax
    mov edx, [ebp+8]
    in ax, dx

    pop ebp
    ret


out_byte:
    push ebp
    mov ebp, esp

    mov eax, [ebp+12]
    mov edx, [ebp+8]
    out dx, al

    pop ebp
    ret


out_word:
    push ebp
    mov ebp, esp

    mov eax, [ebp+12]
    mov edx, [ebp+8]
    out dx, ax

    pop ebp
    ret