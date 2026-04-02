#include <iostream>
using namespace std;

class Transaction {
//A classe Transaction representa uma transação executada.
private:
    int buy_order_id;
    int sell_order_id;
    float execution_price;

public:

    Transaction(int buy_order_id, int sell_order_id, float execution_price){
	    this->buy_order_id = buy_order_id;
	    this->sell_order_id = sell_order_id;
	    this->execution_price = execution_price;
    }
    ~Transaction(){}
    int getBuyOrderId() const {
	    return buy_order_id;
    }
    int getSellOrderId() const {
	    return sell_order_id;
    }
    float getExecutionPrice() const {
	    return execution_price;
    }
};

