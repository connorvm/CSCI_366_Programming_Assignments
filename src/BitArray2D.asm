
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
        sub rdx, 8     ;rdx = rdx - 8
        neg rdx        ;negate rdx
        dec rdx        ;rdx = rdx - 1
        mov rcx, 1     ;set rcx to 00000001 to use as the mask

        cmp rdx, 1
        je one
        cmp rdx, 2
        je two
        cmp rdx, 3
        je thr
        cmp rdx, 4
        je four
        cmp rdx, 5
        je five
        cmp rdx, 6
        je six
        cmp rdx, 7
        je sev
        cmp rdx, 0
        je zero
      zero:
        sal rcx, 0    ;shift a 1 into the correct place
      one:
        sal rcx, 1    ;shift a 1 into the correct place
      two:
        sal rcx, 2    ;shift a 1 into the correct place
      thr:
        sal rcx, 3    ;shift a 1 into the correct place
      four:
        sal rcx, 4    ;shift a 1 into the correct place
      five:
        sal rcx, 5    ;shift a 1 into the correct place
      six:
        sal rcx, 6    ;shift a 1 into the correct place
      sev:
        sal rcx, 7    ;shift a 1 into the correct place

        ;now we can or the byte with the mask
        or rdi, rcx     ;byte := byte or mask -> rsi or rcx
        mov rbx, rdi
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
        sub rdx, 8     ;rdx = 8 - rdx
        neg rdx        ;rdx = -rdx
        dec rdx        ;rdx = rdx - 1
        mov rcx, 1     ;set rcx to 00000001 to use as the mask

        cmp rdx, 1
        je .one
        cmp rdx, 2
        je .two
        cmp rdx, 3
        je .thr
        cmp rdx, 4
        je .four
        cmp rdx, 5
        je .five
        cmp rdx, 6
        je .six
        cmp rdx, 7
        je .sev
        cmp rdx, 8
        je .eight
        cmp rdx, 0
        je .zero
      .zero:
        sal rcx, 0    ;shift a 1 into the correct place
      .one:
        sal rcx, 1    ;shift a 1 into the correct place
      .two:
        sal rcx, 2    ;shift a 1 into the correct place
      .thr:
        sal rcx, 3    ;shift a 1 into the correct place
      .four:
        sal rcx, 4    ;shift a 1 into the correct place
      .five:
        sal rcx, 5    ;shift a 1 into the correct place
      .six:
        sal rcx, 6    ;shift a 1 into the correct place
      .sev:
        sal rcx, 7    ;shift a 1 into the correct place
      .eight:
        sal rcx, 8    ;shift a 1 into the correct place

        ;now we can or the byte with the mask
        or rdi, rcx     ;byte := byte or mask -> rsi or rcx
        mov rbx, rdi
        mov rax, rdi
        ;mov rax, 0

        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax
