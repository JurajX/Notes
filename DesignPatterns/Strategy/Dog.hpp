#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <string_view>

#include <Animal.hpp>

class Dog : public Animal
{
public:
    virtual ~Dog();
    Dog();
    Dog(std::string_view name);
    auto makeSound() const -> std::string override;
};

#endif    // DOG_HPP