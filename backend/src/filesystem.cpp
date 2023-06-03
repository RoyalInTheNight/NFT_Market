#include <filesystem.h>

std::streampos filesystem::file_size(const fs::path file_path) {
    std::ifstream file(file_path, std::ios_base::binary);

    if (file.fail())
        throw std::runtime_error("filesystem: file_open error\n");

    std::streampos

    file_size = file.tellg();
    file.seekg(0, std::ios::end);
    file_size = file.tellg() - file_size;

    file.close();

    return file_size;
}

const char *filesystem::file_read(const fs::path file_path) {
    std::streampos size_file = file_size(file_path);
    std::ifstream  file(file_path, std::ios_base::binary);

    if (file.fail())
        throw std::runtime_error("filesystem: file_open error\n");

    char *read_file_buffer = new s8[(u32)size_file];

    file.read(read_file_buffer, (u32)size_file);
    file.close();

    return read_file_buffer;
}

void filesystem::file_write(const fs::path file_path, const char *data) {
    std::ofstream file(file_path, std::ios_base::binary);

    if (file.is_open()) {
        file.write(data, strlen(data));
        file.close();
    }

    else throw std::runtime_error("filesystem: file_open error\n");
}

fs::path filesystem::get_app_data() {
    #ifdef WIN64
        return getenv("APPDATA");
    #else
        return "/etc";
    #endif // WIN64
}

fs::path filesystem::get_tmp() {
    #ifdef WIN64
        return getenv("TEMP");
    #else
        return "/tmp";
    #endif // WIN64
}

void filesystem::file_remove(const fs::path file_path) { fs::remove(file_path); }
void filesystem::file_copy(const fs::path file_path_src, const fs::path file_path_dst) { fs::copy(file_path_src, file_path_dst); }
void filesystem::file_move(const fs::path file_path_src, const fs::path file_path_dst) { fs::copy(file_path_src, file_path_dst); fs::remove(file_path_src); }
void filesystem::file_create(const fs::path file_path) { fs::create_directory(file_path); }
