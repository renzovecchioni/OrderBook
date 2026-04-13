#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

using namespace std;
#include <iostream>
#include "Transaction.hpp"
#include "Order.hpp"

class OrderBook {
//A classe OrderBook é responsável por gerenciar todas as ordens e transações do sistema.;
private:
	Order* buyOrders;
	Order* sellOrders;
	Transaction* transactions;
	// apenas declara um tamanho inicial que a partir de uma lista dinamica, futuramente o tamanho do nosso array sera alterado.
	int tamanhoBuy = 10;
	int tamanhoSell = 10;
	int tamanhoTransactions = 10;
	int buyCount = 0;
	int sellCount = 0;
	int transactionsCount = 0;
public:

    OrderBook();
    ~OrderBook();
	template <typename T>
    void ajustarTamanho(T*& array, int &antigoTamanho, int novoTamanho);

    bool submit(Order order);
    bool cancel(int id);

    
    Order* getBuyOrders(int* n);
    Order* getSellOrders(int* n);
    Transaction* getTransactions(int* n);
    void printBuyOrders();
    void printSellOrders();
    void printTransactions();
};

#endif