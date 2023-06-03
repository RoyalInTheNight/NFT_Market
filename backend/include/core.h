#ifndef CORE
#define CORE

namespace core {
    namespace types {
        typedef signed char         s8;
        typedef unsigned char       u8;
        typedef signed short       s16;
        typedef unsigned short     u16;
        typedef signed int         s32;
        typedef unsigned int       u32;
        typedef signed long long   s64;
        typedef unsigned long long u64;

        typedef s8 *               _s8;
        typedef u8 *               _u8;
        typedef s16 *             _s16;
        typedef u16 *             _u16;
        typedef s32 *             _s32;
        typedef u32 *             _u32;
        typedef s64 *             _s64;
        typedef u64 *             _u64;
    }

    namespace tarch {
        const types::u8 opcode_sock_connect = 0x21;
        const types::u8 opcode_sock_listen  = 0x22;
        const types::u8 opcode_sock_accept  = 0x23;

        namespace flags {
            const types::u8 FLAG_DAT        = 0x41;
            const types::u8 FLAG_FAT        = 0x42;
        }
    }
}


#endif // CORE