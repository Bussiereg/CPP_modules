#include "easyfind.hpp"

int main() {

    std::deque<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::deque<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(5);

    std::cout << "---Test with vectors---" << std::endl;
    easyfind(vec, 7);
    std::cout << std::endl;

    std::cout << "---Test with list---" << std::endl;
    easyfind(lst1, 1);
    std::cout << std::endl;

    return 0;
}
