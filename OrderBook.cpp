#include <iostream>
#include "Transaction.hpp"
#include "Order.hpp"
#include "OrderBook.hpp"

using namespace std;

OrderBook::OrderBook(){
	buyOrders = new Order[tamanhoBuy]{};
	sellOrders = new Order[tamanhoSell]{};
	transactions = new Transaction[tamanhoTransactions]{};
}
OrderBook::~OrderBook(){
	delete[] buyOrders;
	delete[] sellOrders;
	delete[] transactions;
}

template <typename T>
void OrderBook::ajustarTamanho(T*& array, int &antigoTamanho, int novoTamanho){
	T* novoArray = new T[novoTamanho];
	for (int i = 0; i<antigoTamanho; i++){
		novoArray[i] = array[i];
	}
	delete[] array;
	array = novoArray;
	antigoTamanho = novoTamanho;
}    

bool OrderBook::submit(Order order){
	if (order.getType() == 'B'){//para compra
		if (buyCount >= tamanhoBuy){
			ajustarTamanho(buyOrders, tamanhoBuy, int(tamanhoBuy*1.2) + 1);
		}
		buyOrders[buyCount] = order;
		buyCount++;
		if (sellCount == 0){
			printBuyOrders();
			printSellOrders();
			printTransactions();
			return true;
		}
		int menorPreco = sellOrders[0].getPrice(); //verificar erros
		int guardarIndice = 0;
		for (int i = 0; i<sellCount; i++){
			if (sellOrders[i].getPrice() < menorPreco){
				menorPreco = sellOrders[i].getPrice();
				guardarIndice = i;
			}
		}
		if (buyOrders[buyCount-1].getPrice() >= menorPreco){
			if (transactionsCount >= tamanhoTransactions){
				ajustarTamanho(transactions, tamanhoTransactions, int(tamanhoTransactions*1.2)+1);
			}
			transactions[transactionsCount] = Transaction(buyOrders[buyCount-1].getId(), sellOrders[guardarIndice].getId(), buyOrders[buyCount - 1].getPrice());
			transactionsCount++;
			int buyId = buyOrders[buyCount-1].getId();
			int sellId = sellOrders[guardarIndice].getId();

			cancel(buyId);
			cancel(sellId);
		}
		
	
		printBuyOrders();
		printSellOrders();
		printTransactions();
		return true;
}
	else if(order.getType() == 'S'){//para venda
		if (sellCount >= tamanhoSell){
			ajustarTamanho(sellOrders, tamanhoSell, int(tamanhoSell*1.2) + 1);
		}
		sellOrders[sellCount] = order;
		sellCount++;
		if (buyCount == 0){
			printBuyOrders();
			printSellOrders();
			printTransactions();
			return true;
		}
		int maiorPreco = buyOrders[0].getPrice(); //verificar erros
		int guardarIndice = 0;
		for (int i = 0; i<buyCount; i++){
				if (buyOrders[i].getPrice() > maiorPreco){
				maiorPreco = buyOrders[i].getPrice();
				guardarIndice = i;
				}
			}
		if (sellOrders[sellCount-1].getPrice() <= maiorPreco){
			if (transactionsCount >= tamanhoTransactions){
				ajustarTamanho(transactions, tamanhoTransactions, int(tamanhoTransactions * 1.2) + 1);
			}
			transactions[transactionsCount] = Transaction(buyOrders[guardarIndice].getId(), sellOrders[sellCount-1].getId(), sellOrders[sellCount - 1].getPrice());
			transactionsCount++;
			int buyId = buyOrders[guardarIndice].getId();
			int sellId = sellOrders[sellCount-1].getId();
			
			cancel(buyId);
			cancel(sellId);
		}
			
		printBuyOrders();
		printSellOrders();
		printTransactions();
		return true;
	} 
	return false;
}
bool OrderBook::cancel(int id){
	for (int i = 0; i< buyCount ;i++){
		if (buyOrders[i].getId() == id){
			for (int j = i; j< buyCount-1;j++){
				buyOrders[j] = buyOrders[j+1];
			}
			buyCount--;
			return true;
		}
	}
	for (int i = 0; i < sellCount; i++){
		if(sellOrders[i].getId() == id){
			for (int j = i; j< sellCount-1;j++){
				sellOrders[j] = sellOrders[j+1];
			}
			sellCount--;
			return true;
		}
	}
	return false;
}


Order* OrderBook::getBuyOrders(int* n){
	*n = buyCount;
	return buyOrders;
}
Order* OrderBook::getSellOrders(int* n){
	*n = sellCount;
	return sellOrders;
}
Transaction* OrderBook::getTransactions(int* n){
	*n = transactionsCount;
	return transactions;
}
void OrderBook::printBuyOrders(){
	cout<<"Buy Orders: "<<endl;
	if (buyCount == 0){
		cout<<"(empty)"<<endl;
	}
	else{
		for (int i = 0; i<buyCount; i++){
		cout<<"["<<buyOrders[i].getId()<<" | "<<buyOrders[i].getPrice()<<" | "<<buyOrders[i].getTimestamp()<<"]"<<endl;
		}
	}
}
void OrderBook::printSellOrders(){
	cout<<"Sell Orders: "<<endl;
	if (sellCount == 0){
		cout<<"(empty)"<<endl;
	}
	else{
		for (int i = 0; i<sellCount; i++){
			cout<<"["<<sellOrders[i].getId()<<" | "<<sellOrders[i].getPrice()<<" | "<<sellOrders[i].getTimestamp()<<"]"<<endl;
			}
		}
	}
void OrderBook::printTransactions(){
	cout<<"Transactions:"<<endl;
	if (transactionsCount == 0){
		cout<<"(empty)"<<endl;
	}
	else{
		for (int i = 0; i<transactionsCount; i++){
			cout<<"["<<transactions[i].getBuyOrderId()<<", "<<transactions[i].getSellOrderId()<<", "<<transactions[i].getExecutionPrice()<<"]"<<endl;
			}
		}
	}