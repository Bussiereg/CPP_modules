#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main(void)
{
    Base *b = generate();
    identify(b);
    identify(*b);
    delete b;
    return (0);
}