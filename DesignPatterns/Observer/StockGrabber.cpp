#include <stdexcept>

#include <StockGrabber.hpp>

auto StockGrabber::regstr(const std::shared_ptr<Subscriber> &s) -> void
{
    if (subscribers_.contains(s))
        throw std::runtime_error("Given subscriber is already registered.");
    subscribers_.insert(s);
}

auto StockGrabber::deregstr(const std::shared_ptr<Subscriber> &s) -> void
{
    if (subscribers_.contains(s))
        throw std::runtime_error("Given subscriber is not yet registered.");
    subscribers_.erase(s);
}

auto StockGrabber::notifyAll() const -> void
{
    for (const auto &subscriber : subscribers_)
        subscriber->update(prices_);
}

auto StockGrabber::setPrice(const Company company, const double price) -> void
{
    prices_[company] = price;
    notifyAll();
}
