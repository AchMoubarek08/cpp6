#include "Static.hpp"

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}
Base * generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            (void) dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                (void) dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main()
{
    Base *b = generate();
    identify(b);
    identify(*b);
    (void) b;
}