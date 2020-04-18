
        global  set_bit_elem
        global  get_bit_elem
        section .text

set_bit_elem:
        push rbp            ; save the base pointer on the stack (at rsp+8)
        mov rbp, rsp        ; set up the rbp for the bottom of this frame


        ;Sets a bit in a two dimensional bit array
        ;@param array - pointer to a bit array
        ;@param row_width - the number of bits in a row of the two dimensional array
        ;@param row - row index (0 indexed)
        ;@param col - column index (0 indexed)

        ; rdi contains array pointer
        ; rsi contains row width
        ; rdx contains row
        ; rcx contains col

        ; add your code here

        ;index = row*row_width + column
        imul rdx, rsi   ;rdx = rdx * rsi -> row = row * row_width
        add rdx, rcx    ;rdx = rdx + rcx -> row = (row*row_width) + col
        mov rbx, rdx    ;rbx = rdx, need to do this for following steps

        ;byte_offset = index / 8
        sar rbx, 3      ;shift arithmetic right 3 times is same as divide by 8 :: rbx = rbx/8
        mov rsi, rbx    ;rsi = rbx is now "byte_offset"

        ;bit_offset = index - (byte_offset * 8)
        imul rbx, 8     ;rbx = rbx * 8 -> byte_offset = byte_offset*8
        sub rdx, rbx    ;rdx is still "index" :: rdx = rdx - rbx -> rdx = index - (byte_offset*8)
                        ;rdx is now "bit_offset"

        ;mask = 1 << (8 - bit_offset - 1)
        ;create a mask by shifting a 1 into the proper position
        add rdx, -8     ;rdx = 8 - rdx
        sub rdx, 1      ;rdx = rdx - 1
        imul rcx, 0     ;set rcx to zero to use as the mask
        sal rcx, rdx    ;shift a 1 into the correct place

        ;now we can or the byte with the mask
        or rsi, rcx     ;byte := byte or mask -> rsi or rcx
        ;mov rax, rsi


        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax




get_bit_elem:
        push rbp            ; save the base pointer on the stack (at rsp+8)
        mov rbp, rsp        ; set up the rbp for the bottom of this frame

        ; rdi contains array pointer
        ; rsi contains row width
        ; rdx contains row
        ; rcx contains col

        ; add your code here - for now returning 0
        ;index = row*row_width + column
        imul rdx, rsi   ;rdx = rdx * rsi -> row = row * row_width
        add rdx, rcx    ;rdx = rdx + rcx -> row = (row*row_width) + col
        mov rbx, rdx    ;rbx = rdx, need to do this for following steps

        ;byte_offset = index / 8
        sar rbx, 3      ;shift arithmetic right 3 times is same as divide by 8 :: rbx = rbx/8
        mov rsi, rbx    ;rsi = rbx is now "byte_offset"

        ;bit_offset = index - (byte_offset * 8)
        imul rbx, 8     ;rbx = rbx * 8 -> byte_offset = byte_offset*8
        sub rdx, rbx    ;rdx is still "index" :: rdx = rdx - rbx -> rdx = index - (byte_offset*8)
                        ;rdx is now "bit_offset"

        ;mask = 1 << (8 - bit_offset - 1)
        ;create a mask by shifting a 1 into the proper position
        add rdx, -8     ;rdx = 8 - rdx
        sub rdx, 1      ;rdx = rdx - 1
        imul rcx, 0     ;set rcx to zero to use as the mask
        sal rcx, rdx    ;shift a 1 into the correct place

        ;now we can or the byte with the mask
        or rsi, rcx     ;byte := byte or mask -> rsi or rcx
        mov rax, rsi
        ;mov rax, 0

        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax
