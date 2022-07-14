#include <fmt/core.h>

#include <Bird.hpp>

Bird::~Bird()
{
    fmt::print("  Bird constructor of {}.\n", getName());
}

Bird::Bird()
    : Bird { "unnamed bird" }
{ }

Bird::Bird(std::string_view name)
    : Animal { name, std::make_unique<ItFlys>() }
{
    fmt::print("  Bird constructor of {}.\n", getName());
}

auto Bird::makeSound() const -> std::string
{
    return "Chirp, chirp!";
}