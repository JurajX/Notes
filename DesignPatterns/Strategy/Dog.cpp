#include <fmt/core.h>

#include <Dog.hpp>

Dog::~Dog()
{
    fmt::print("  Dog constructor of {}.\n", getName());
}

Dog::Dog()
    : Dog { "unnamed dog" }
{ }

Dog::Dog(std::string_view name)
    : Animal { name, std::make_unique<CannotFly>() }
{
    fmt::print("  Dog constructor of {}.\n", getName());
}

auto Dog::makeSound() const -> std::string
{
    return "Bark, bark!";
}