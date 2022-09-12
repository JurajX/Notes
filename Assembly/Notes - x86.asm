# ==================== General-Purpose Registers

# |          RAX          |         # |<------- 64-bit ------>|
#             |    EAX    |         #             |<- 32-bit >|
#                   | AX  |         #                   |< 16>|
#                   |AH|AL|         #                      |<>|

# RAX, EAX, AX, AH, AL are accumulator registers; contains return values
# RBX, EBX, BX, BH, BL are base        registers;
# RCX, ECX, CX, CH, CL are counter     registers
# RDX, EDX, DX, DH, DL are data        registers


# ---------- Index Registers

# RSP, ESP, SP, SPL are stack     pointers (no high 8-bit version!)
# RBP, EBP, BP, BPL are base base pointers (no high 8-bit version!)
# RSI, ESI, SI, SIL are source             (no high 8-bit version!)
# RDI, EDI, DI, DIL are destination        (no high 8-bit version!)

# ---------- SSE (streaming SIMD Extensions)

# since SSE2
# XMM0 - XMM16 (128-bit words)
#  - 2 64-bit floating points (double precision)
#  - 2 64-bit integers
#  - 4 32-bit floating points (single-precision)
#  - 4 32-bit integers
#  - 8 16-bit integers
#  - 16 8-bit characters (bytes)

# since AVX
# XMM0 - XMM16 (128-bit words)
# YMM0 - YMM16 (256-bit words)
# split similar to SSE2

# since AVX-512
# XMM0 - XMM16 (128-bit words)
# YMM0 - YMM31 (256-bit words)
# ZMM0 - ZMM31 (512-bit words)
# split similar to SSE2

# ---------- Additional Registers in 64-bit

# R8,   R8D,  R8W,  R8B     # additional registers; D stands for double word, W stands for word, B stands for byte
# R15, R15D, R15W, R15B     # from 8 to 15

# ---------- Calling

# The registers RAX, RCX, RDX, R8, R9, R10, R11 are considered volatile (caller-saved).
# The registers RBX, RBP, RDI, RSI, RSP, R12, R13, R14, and R15 are considered nonvolatile (callee-saved).

# ==================== Segment Registers

# No longer used as segmented memory is no longer used. (Paging info, threading info.)

# Stack Segment (SS). Pointer to the stack             ('S' stands for 'Stack').
# Code  Segment (CS). Pointer to the code              ('C' stands for 'Code').
# Data  Segment (DS). Pointer to the data              ('D' comes after 'C').
# Extra Segment (ES). Pointer to extra data            ('E' stands for 'Extra').
# F Segment     (FS). Pointer to more extra data       ('F' comes after 'E').
# G Segment     (GS). Pointer to still more extra data ('G' comes after 'F').


# ==================== Flag Registers

# FLAGS (16-bit register)  - a collection of bits representing Boolean values to store the results of operations and the state of the processor.
# EFLAGS (32-bit register) - as above just 32-bit.
# RFLAGS (64-bit register) - as above just 64-bit.

# flags representation in the register:
# 15 | 14 | 13 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5 | 4  | 3 | 2  | 1 | 0  |
#  - | NT | IO PL | OF | DF | IF | TF | SF | ZF | - | AF | - | PF | - | CF |

# CF - carry flag
# PF - parity flag      - not useful anymore
# AF - auxiliary flag   - not useful anymore
# ZF - zero flag
# SF - sign flag
# TF - trap flag
# IF - interrupt flag
# DF - direction flag   - for string reading (up/down)
# OF - overflow flag
# IOPL - IO port privilege level flag
# NT - nested task flag


# ==================== Instruction Pointer

# IP (16-bit)  - register contains the address of the next instruction to be executed if no branching is done.
# EIP (32-bit) - as above but 32-bit.
# RIP (64-bit) - as above but 64-bit.


# ==================== Memory

# The x86 architecture is little-endian, meaning that multi-byte values are written least significant byte first.
# This refers only to the ordering of the bytes, not to the bits.
# I.e. 32 bit value 0x1BA583D4 would be represented in memory as: 0xD4 0x83 0xA5 0x1B (when doing memory dump)

# x86 uses two's complement


# ==================== Data Types

# integer:        byte, word, dword (double word), qword (quadruple word)
# floating point: real4 (32-bit), real8 (64-bit), real10 (80-bit)
# SIMD pointers:  xmmword (128-bit), ymmword (256-bit), zmmword (512-bit)

# ???
.dataName:
    .quad


# ==================== Instructions

mov dest, src               # move (copy) src into dest; at most one can be memory; supports 64-bit immediates
mov rax, rax                # interpreted as 3-bite nop (no operation)
mov al, al                  # as above but 2-bite

mov rax, -1                 # rax = 0xffffffff
mov eax, -1                 # rax = 0x0000ffff      using 32-bit registers zeros the top of the 64-bit registers
mov ax, -0                  # rax = 0x0000ff00      operations with 16-bit or 8-bit registers does not have 0-ing effect

lea dest, src               # load effective address; sets no flags
lea rax, myVar              # stores pointer to myVar in rax
mov [rax], 1                # indirectly stores 1 in myVar

add src, dest               # signed and unsigned addition of src to dest; src can be reg/mem, dest can be reg/mem/imm;
                            # flags: overflow, carry, sign, zero, auxiliary carry, parity

sub src, dest               # signed and unsigned subtraction of src from dest;
                            # flags: overflow, carry, sign, zero, auxiliary carry, parity

inc dest                    # increments the destination by 1;
                            # flags: overflow, sign, zero, auxiliary carry, parity; NO carry!

inc dest                    # increments the destination by 1; no carry flag is set when overflowing
                            # flags: overflow, sign, zero, auxiliary carry, parity; NO carry!

mul dest src                # unsigned integer multiplication
imul dest src               # signed integer multiplication

div src                     # divides compound register RDX:RAX by src; result RAX, reminder RDX; for 32-bit division EDX:EAX
idiv src                    # as above for division

# ---------- Boolean Instructions

and dest, src
or dest, src
not dest
xor dest, src

# ---------- Shift Instructions
shl dest, src               # shift logical left; shifts bits in dest to the left by src; src can be immediate of CL register
                            # flags: carry
sal dest, src               # shift arithmetic left; exactly same as shift logical left
shr dest, src               # shift logical right; as above but shifts right
sar dest, src               # shift arithmetic rigth; as above but padds negative numbers with 1 instead of 0

rol dest, src               # rotate left; as shl except that the shifted bits come back on the other side
ror dest, src               # as above; just to the right

rcl dest, src               # as rol; except that the carry bit is included as an independent bit, i.e. (65-bit word rotation)
rcr dest, src               # as above, just to the right

shrd dest, src1, src2       # double word right shift by src2; 128-bit shift of src1_dest that stores lower 64-bits of result in dest
shld dest, src1, src2       # as above but shifts left the word dest_src1 and stores higher 64-bits

# ---------- Jump Instructions
jo              # overflow
jno             # not overflow
js              # signed
jns             # not signed

jl/jnge         # less signed
jnl/jge         # not less signed
jle/jng         # not greater signed
jnle/jg         # greater signed

jb/jc/jnae      # carry unsigned
jnb/jnc/jae     # not carry unsigned

jbe/jna         # below or equal unsigned
jnbe/ja         # above unsigned

je/jz           # zero
jne/jnz         # not zero

jp/jpe          # parity even
jnp/jpo         # parity odd