#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <memory>

#include <Subscriber.hpp>

class Publisher
{
public:
    virtual ~Publisher() = default;
    Publisher()          = default;

    virtual auto regstr(const std::shared_ptr<Subscriber> &s) -> void   = 0;
    virtual auto deregstr(const std::shared_ptr<Subscriber> &s) -> void = 0;
    virtual auto notifyAll() const -> void                              = 0;
};

#endif    // PUBLISHER_HPP