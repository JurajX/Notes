#include <Flys.hpp>

auto ItFlys::fly() const -> std::string
{
    return "Flying high!";
}

auto CannotFly::fly() const -> std::string
{
    return "I cannot fly!";
}
