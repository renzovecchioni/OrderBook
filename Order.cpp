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

    Order(int id, char type, float price, int timestamp){
	    this->id = id;
	    this->type = type;
	    this->price = price;
	    this->timestamp = timestamp;
    }
    ~Order(){}
    int getId() const{
	    return id;
    }
    char getType()const{
	    return type;
    }
    float getPrice() const{
	    return price;
    }
    int getTimestamp() const{
	    return timestamp;
    }
};
