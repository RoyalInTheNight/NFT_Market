#include <buffer_container.h>
#include <iostream>

int main() {
    base_buffer<char, cxx_allocator<char> > buffer = "128";

    buffer += "Hello world!";

    std::cout << buffer.data() << std::endl;

    buffer.pop_back();

    std::cout << buffer.data() << std::endl;

    buffer = "soft work!!";

    std::cout << buffer.data() << std::endl;
}