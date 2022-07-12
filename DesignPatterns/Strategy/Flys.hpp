#ifndef FLYS_HPP
#define FLYS_HPP

#include <string>

class Flys
{
public:
    virtual ~Flys() = default;
    Flys()          = default;

    virtual auto fly() const -> std::string = 0;
};

class ItFlys : public Flys
{
public:
    virtual ~ItFlys() = default;
    ItFlys()          = default;

    virtual auto fly() const -> std::string override;
};

class CannotFly : public Flys
{
public:
    virtual ~CannotFly() = default;
    CannotFly()          = default;

    virtual auto fly() const -> std::string override;
};

#endif    // FLYS_HPP