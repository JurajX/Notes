#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include <string>
#include <unordered_map>

enum class Company { Apple, Google, IBM };

class Subscriber
{
private:
public:
    virtual ~Subscriber() = default;
    Subscriber()          = default;

    virtual auto update(const std::unordered_map<Company, double> &prices) -> void = 0;
};

#endif    // SUBSCRIBER_HPP
