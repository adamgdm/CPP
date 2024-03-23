#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generator()
{
    int i = std::rand() % 3;
    if (i == 0)
    {
        std::cout << "A was created" << std::endl;
        return (new A);
    }
    else if (i == 1)
    {
        std::cout << "B was created" << std::endl;
        return (new B);
    }
    else
    {
        std::cout << "C was created" << std::endl;
        return (new C);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } 
    catch (std::bad_cast &e) 
    {
        try 
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } 
        catch (std::bad_cast &e) 
        {
            try 
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } 
            catch (std::bad_cast &e) 
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main()
{
    std::srand(std::time(0));
    Base *base = generator();
    identify(base);
    identify(*base);
    delete base;

    // in case of unknown type
    // class D : public Base {};
    // D d;
    // identify(d);
    // identify(d);
    return 0;
}
