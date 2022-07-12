#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <memory>
#include <string>
#include <string_view>

#include <Flys.hpp>

class Animal
{
private:
    std::string name_;
    std::unique_ptr<Flys> flyingType_;

public:
    virtual ~Animal();
    Animal(std::string_view name, std::unique_ptr<Flys> flyingType);

    virtual auto getName() const -> std::string;
    virtual auto setFlyingAbility(std::unique_ptr<Flys> flyingType) -> void;
    virtual auto makeSound() const -> std::string = 0;
    virtual auto tryToFly() const -> std::string;
};

#endif    // ANIMAL_HPP