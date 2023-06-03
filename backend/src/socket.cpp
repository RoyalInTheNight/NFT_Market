#include <Socket.h>

u32 Socket::strlen(const _s8 message) {
    _s8 s;

    for (s = message; *s; s++);
    return s - message;
}

void Socket::socket(SOCKET *fd, u32 mode) {
    switch (mode) {
        case IPPROTO_TCP:
            if (fd == nullptr)
                fd = new SOCKET(::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
            
            else
                *fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        case IPPROTO_UDP:
            if (fd == nullptr)
                fd = new SOCKET(::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP));

            else
                *fd = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        default:
            ferr_buffer = 0x31;
    }
}

void Socket::bind(SOCKET fd, const __sock sockt, sslen size_sockt) {
    if (::bind(fd, sockt, size_sockt) < 0)
        ferr_buffer = 0x32;
}

void Socket::send(SOCKET fd, _s8 message) {
    u32 size_message = strlen(message);
    u64 take_p       = (u64)message;

    if (size_message > __INT32_MAX__) {
        while (size_message) {
            if (::send(fd, message, __INT32_MAX__, 0) < 0) {
                ferr_buffer = 0x35;

                return;
            }

            else {
                message = &message[__INT32_MAX__];
                size_message -=    __INT32_MAX__ ;
            }
        }

        message = (_s8)take_p;
    }

    else
        if (::send(fd, message, size_message, 0) < 0)
            ferr_buffer = 0x35;
}

void Socket::sendto(SOCKET fd, _s8 message, const __sock client_sock, sslen client_sock_size) {
    u32 size_message = strlen(message);
    u64 take_p       = (u64)message;

    if (size_message > __INT32_MAX__) {
        while (size_message) {
            if (::sendto(fd, message, __INT32_MAX__, 0, client_sock, client_sock_size) < 0) {
                ferr_buffer = 0x35;

                return;
            }

            else {
                message = &message[__INT32_MAX__];
                size_message -=    __INT32_MAX__ ;
            }
        }

        message = (_s8)take_p;
    }

    else
        if (::sendto(fd, message, size_message, 0, client_sock, client_sock_size) < 0)
            ferr_buffer = 0x35;
}

void Socket::recv(SOCKET fd, _s8 message, u64 size_message) {
    if (size_message > __INT32_MAX__) {
        u32 bytes_read = 0;
        u64 take_p = (u64)message;

        while (size_message) {
            bytes_read = ::recv(fd, message, __INT32_MAX__, 0);

            if (bytes_read) {
                message = &message[bytes_read];
                size_message -= bytes_read;
            }

            else
                ferr_buffer = 0x34;
        }
    }

    else
        if (::recv(fd, message, size_message, 0) < 0)
            ferr_buffer = 0x34;
}