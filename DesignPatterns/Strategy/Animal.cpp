#include <fmt/core.h>

#include <Animal.hpp>

Animal::Animal(std::string_view name, std::unique_ptr<Flys> flyingType)
    : name_ { name }
    , flyingType_ { std::move(flyingType) }
{
    fmt::print("Animal constructor of {}.\n", name_);
}

Animal::~Animal()
{
    fmt::print("Animal destructor of {}.\n", name_);
}

auto Animal::getName() const -> std::string
{
    return name_;
}

auto Animal::setFlyingAbility(std::unique_ptr<Flys> flyingType) -> void
{
    flyingType_ = std::move(flyingType);
}

auto Animal::tryToFly() const -> std::string
{
    return flyingType_->fly();
}