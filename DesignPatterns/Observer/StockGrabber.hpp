#ifndef STOCK_GRABBER_HPP
#define STOCK_GRABBER_HPP

#include <unordered_map>
#include <unordered_set>

#include <Publisher.hpp>
#include <Subscriber.hpp>

class StockGrabber : public Publisher
{
private:
    std::unordered_set<std::shared_ptr<Subscriber>> subscribers_;
    std::unordered_map<Company, double> prices_;

public:
    StockGrabber()          = default;
    virtual ~StockGrabber() = default;

    virtual auto regstr(const std::shared_ptr<Subscriber> &s) -> void override;
    virtual auto deregstr(const std::shared_ptr<Subscriber> &s) -> void override;
    virtual auto notifyAll() const -> void override;

    virtual auto setPrice(const Company company, const double price) -> void;
};

#endif    // STOCK_GRABBER_HPP