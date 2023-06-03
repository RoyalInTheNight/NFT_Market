#ifndef FS_CORE
#define FS_CORE

#include <cstdio>
#include <core.h>

using namespace core::types;

class filesystem {
private:
    static u32 strlen(const _s8);

public:
    static inline u32 size_file(const _s8);
    static inline _s8 read_file(const _s8);
    static inline void write_file(const _s8, const _s8);
    static inline void write_file_end(const _s8, const _s8);
};

#endif // FS_CORE