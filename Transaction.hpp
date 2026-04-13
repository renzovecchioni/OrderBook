#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <iostream>

using namespace std;

class Transaction {
//A classe Transaction representa uma transação executada.
private:
    int buy_order_id;
    int sell_order_id;
    float execution_price;
public:
    Transaction() = default;
    Transaction(int buy_order_id, int sell_order_id, float execution_price);
    ~Transaction();
    int getBuyOrderId() const;
    int getSellOrderId() const;
    float getExecutionPrice() const;
};

#endif