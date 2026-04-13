#include <iostream>
#include "Order.hpp"

using namespace std;

Order::Order(int id, char type, float price, int timestamp){
	    this->id = id;
	    this->type = type;
	    this->price = price;
	    this->timestamp = timestamp;
    }
Order::~Order(){}
// retorna o getter do Order.id()
int Order::getId() const{
    return id;
}
// retorna o getter do Order.type()
char Order::getType()const{
    return type;
}
// retorna o getter do Order.getPrice()
float Order::getPrice() const{
    return price;
}
// retorna o getter do Order.timestamp()
int Order::getTimestamp() const{
    return timestamp;
}
