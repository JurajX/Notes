#include <StockObserver.hpp>

#include <fmt/core.h>

auto priceMap { [](const Company c) -> std::string {
    std::string name {};
    switch (c) {
        case Company::Apple :
            return "Apple";
        case Company::Google :
            return "Google";
        case Company::IBM :
            return "IBM";
        default :
            return "unknown";
    }
} };

StockObserver::StockObserver(const Company company)
    : company_ { company }
{ }

auto StockObserver::update(const std::unordered_map<Company, double> &prices) -> void
{
    if (prices.contains(company_))
        price_ = prices.at(company_);
}

auto StockObserver::printPrice() const -> void
{
    fmt::print("The price of {}, is {} euro.\n", priceMap(company_), price_);
}