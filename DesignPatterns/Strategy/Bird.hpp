#ifndef BIRD_HPP
#define BIRD_HPP

#include <string>
#include <string_view>

#include <Animal.hpp>

class Bird : public Animal
{
public:
    virtual ~Bird();
    Bird();
    Bird(std::string_view name);
    auto makeSound() const -> std::string override;
};

#endif    // BIRD_HPP