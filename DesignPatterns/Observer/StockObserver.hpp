#ifndef STOCK_OBSERVER_HPP
#define STOCK_OBSERVER_HPP

#include <Subscriber.hpp>

class StockObserver : public Subscriber
{
private:
    Company company_;
    double price_;

public:
    virtual ~StockObserver() = default;
    StockObserver(Company company);

    virtual auto update(const std::unordered_map<Company, double> &prices) -> void override;
    virtual auto printPrice() const -> void;
};

#endif    // STOCK_OBSERVER_HPP