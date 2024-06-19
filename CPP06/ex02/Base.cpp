#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
}

int random_number() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int random = std::rand() % 3;
    return random;
}

Base*	generate(void){

	int i =  random_number();
	Base * newclass = NULL;

	if (i == 0)
		newclass =  new A;
	else if (i == 1)
		newclass =  new B;
	else if (i == 2)
		newclass =  new C;
	return (newclass);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "No class identified" << std::endl;
}

void    identify(Base& p)
{
    try{
        A & newA = dynamic_cast<A&>(p);
        (void)newA;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e){
        try{
            B & newB = dynamic_cast<B&>(p);
            (void)newB;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e){
            try{
                C & newC = dynamic_cast<C&>(p);
                (void)newC;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e){
                std::cout << "No class identified" << std::endl;
            }
        }
    }
}

