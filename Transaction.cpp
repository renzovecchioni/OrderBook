#include <iostream>
#include "Transaction.hpp"
using namespace std;

Transaction::Transaction(int buy_order_id, int sell_order_id, float execution_price){
	    this->buy_order_id = buy_order_id;
	    this->sell_order_id = sell_order_id;
	    this->execution_price = execution_price;
}
Transaction::~Transaction(){}
int Transaction::getBuyOrderId() const {
    return buy_order_id;
}
int Transaction::getSellOrderId() const {
    return sell_order_id;
}
float Transaction::getExecutionPrice() const {
    return execution_price;
}