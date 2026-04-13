#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
using namespace std;

class Order {
//A classe Order representa uma ordem de compra ou venda.
private:
    int id;
    char type; // 'B' ou 'S'
    float price;
    int timestamp;
public:
    Order() = default;
    Order(int id, char type, float price, int timestamp);
    ~Order();
    int getId() const;
    char getType() const;
    float getPrice() const;
    int getTimestamp() const;
};

#endif