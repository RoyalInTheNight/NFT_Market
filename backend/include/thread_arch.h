#ifndef THREAD_ARCH
#define THREAD_ARCH

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <buffer.h>
#include <thread>
#include <core.h>

typedef sockaddr_in   ssock;
typedef sockaddr       sock;
typedef sockaddr *   __sock;
typedef sockaddr_in __ssock;
typedef socklen_t     sslen;
typedef socklen_t * __sslen;
typedef int          SOCKET;

using namespace core::types;
using namespace core::tarch;

struct thread_sqe {
    u8 opcode;
    u8 flags;

    union {
        u64 addr;
        u64 offs;
    }

    u32 len_buffer;
    u64 user_data;
};

struct thread_cqe {
    u64 user_data;
    s32   result;
    u8     flags;
};

class thread_arch {
public:
    static inline void thread_arch_init(const thread_cqe *);
    static inline void thread_arch_socks_connect(const thread_sqe *, SOCKET, const __sock, sslen);
    static inline void thread_arch_sock_listen(const thread_sqe *, SOCKET, u32);
    static inline void thread_arch_socks_accept(const thread_sqe *, SOCKET, const __sock, const __sslen);
    static inline void thread_arch_socks_recv(const thread_sqe *, SOCKET, _s8, u32);
    static inline void thread_arch_socks_send(const thread_sqe *, SOCKET, _s8, u32);
    static inline void thread_arch_fs_write(const thread_sqe *, const sock_buffer&);
    static inline void thread_arch_fs_read(const thread_sqe *, const sock_buffer *);
    static inline void thread_arch_fs_size(const thread_sqe *, const sock_buffer&);
    static inline void thread_arch_sha2_hash(const thread_sqe *, const sock_buffer *, u32);
    static inline void thread_arch_sha2_decode(const thread_sqe *, const sock_buffer *, u32);
    static inline void thread_arch_sha3_hash(const thread_sqe *, const sock_buffer *, u32);
    static inline void thread_arch_sha3_decode(const thread_sqe *, const sock_buffer *, u32);
    static inline void thread_arch_compress(const thread_sqe *, const sock_buffer *, u32);
    static inline void thread_arch_decompress(const thread_sqe *, const sock_buffer *, u32);
};

#endif // THREAD_ARCH