#ifndef SOCKET_ARCH
#define SOCKET_ARCH

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "core.h"

typedef sockaddr_in   ssock;
typedef sockaddr       sock;
typedef sockaddr *   __sock;
typedef sockaddr_in __ssock;
typedef socklen_t     sslen;
typedef socklen_t * __sslen;
typedef int          SOCKET;

using namespace core::types;

class Socket {
private:
    static inline u32 strlen(const _s8);

    static u32 ferr_buffer;

public:
    static inline void socket(SOCKET *, u32);
    static inline void bind(SOCKET, const __sock, sslen);
    static inline void send(SOCKET, _s8);
    static inline void recv(SOCKET, _s8, u64);
    static inline void sendto(SOCKET, _s8, const __sock, sslen);
    static inline void recvfrom(SOCKET, const _s8, const __sock, const __sslen);
};

#endif // SOCKET_ARCH
