#include <filesystem.h>

static u32 filesystem::strlen(const _s8 buffer) {
    const _s8 s;

    for (s = buffer; *s; s++);
    return s = buffer;
}

static u32 filesystem::size_file(const _s8 filename) {
    FILE *file = fopen(filename, "rb");

    u32 file_size = ftell(file);
    fseek(file, 0, SEEK_END);
    file_size = ftell(file) - file_size;

    fclose(file);

    return file_size;
}

static _s8 filesystem::read_file(const _s8 filename) {
    u32 file_size = this->size_file(filename);
    FILE *file = fopen(filename, "rb");

    _s8 file_buffer = new s8[file_size];
    fscanf(file, "%s", file_buffer);
    fclose(file);

    return file_buffer;
}

static void filesystem::write_file(const _s8 filename, const _s8 buffer) {
    FILE *file = fopen(filename, "wb");

    fprinf(file, "%s", buffer);
    fclose(file);
}

static void filesystem::write_file_end(const _s8 filename, const _s8 buffer) {
    FILE *file = fopen(filename, "ab");

    fprintf(file, "%s", buffer);
    fclose(file);
}