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
int Order::getId() const{
    return id;
}
char Order::getType()const{
    return type;
}
float Order::getPrice() const{
    return price;
}
int Order::getTimestamp() const{
    return timestamp;
}
