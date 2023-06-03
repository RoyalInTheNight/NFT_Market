#ifndef SOCKET_ARCH
#define SOCKET_ARCH

#include <thread_arch.h>

class Socket {
private:
    typedef int __It;

    __sock        sock_main;
    __sock     sock_reserve;
    __sslen       sock_size;

    __It              _part;

public:

};

#endif // SOCKET_ARCH