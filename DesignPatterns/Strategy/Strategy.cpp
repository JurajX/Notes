#include <fmt/core.h>

#include <Bird.hpp>
#include <Dog.hpp>

int main(int /*argc*/, char const ** /*argv[]*/)
{
    {
        Dog sparky { "sparky" };
        fmt::print("The dog {}, says: {}, {}\n", sparky.getName(), sparky.makeSound(), sparky.tryToFly());
        sparky.setFlyingAbility(std::make_unique<ItFlys>());
        fmt::print("The dog {}, says: {}, {}\n", sparky.getName(), sparky.makeSound(), sparky.tryToFly());
    }
    fmt::print("\n");
    {
        Bird tweety { "tweety" };
        fmt::print("The bird {}, says: {}, {}\n", tweety.getName(), tweety.makeSound(), tweety.tryToFly());
    }
    return 0;
}
