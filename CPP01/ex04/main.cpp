#include "StreamReplace.hpp"

int main(int argc, char **argv) {
    if (argc == 4) {
        StreamReplace sedclass(argv[1], argv[2], argv[3]);
        return 0;
    }
    std::cout << "wrong number of arguments" << std::endl;
    return 1;
}