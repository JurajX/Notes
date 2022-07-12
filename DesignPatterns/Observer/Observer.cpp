#include <algorithm>
#include <memory>

#include <fmt/core.h>

#include <StockGrabber.hpp>
#include <StockObserver.hpp>

int main(int /*argc*/, const char ** /*argv[]*/)
{
    auto grabber { std::make_shared<StockGrabber>() };
    std::vector<std::shared_ptr<StockObserver>> subscribers;
    subscribers.push_back(std::make_shared<StockObserver>(Company::Apple));
    subscribers.push_back(std::make_shared<StockObserver>(Company::Google));
    subscribers.push_back(std::make_shared<StockObserver>(Company::IBM));

    std::for_each(subscribers.cbegin(), subscribers.cend(), [&grabber](const auto &s) { grabber->regstr(s); });

    grabber->setPrice(Company::Apple, 7);

    std::for_each(subscribers.cbegin(), subscribers.cend(), [](const auto &s) { s->printPrice(); });
    fmt::print("\n");

    grabber->setPrice(Company::Google, 5);

    std::for_each(subscribers.cbegin(), subscribers.cend(), [](const auto &s) { s->printPrice(); });
    fmt::print("\n");

    grabber->setPrice(Company::IBM, 3);

    std::for_each(subscribers.cbegin(), subscribers.cend(), [](const auto &s) { s->printPrice(); });
    fmt::print("\n");

    return 0;
}
