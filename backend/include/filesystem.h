#ifndef FS_CORE
#define FS_CORE

#include <filesystem>
#include <fstream>
#include <core.h>

namespace fs = std::filesystem;

using namespace core::types;

class filesystem {
public:
    static std::streampos file_size (const fs::path);
    static const char *   file_read (const fs::path);
    static void           file_write(const fs::path, const char *);

    static fs::path get_app_data();
    static fs::path get_tmp();
    
    static void file_remove(const fs::path);
    static void file_copy(const fs::path, const fs::path);
    static void file_move(const fs::path, const fs::path);
    static void file_create(const fs::path);
};

#endif // FS_CORE
