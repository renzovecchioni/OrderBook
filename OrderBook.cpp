#include <iostream>
using namespace std;

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
	int sellcount = 0;
	int transactionsCount = 0;
public:

    OrderBook(){
	    buyOrders = new Order[tamanho]{};
	    sellOrders = new Order[tamanho]{};
	    transactions = new Transactions[tamanho]{};
    }
    ~OrderBook(){
	    delete[] buyOrders;
	    delete[] sellOrders;
	    delete[] transactions;
    }

    void ajustarTamanho(T*& array, int &antigoTamanho, int novoTamanho){
	    T* novoArray = new T[novoTamanho];
	    for (int i = 0; i<antigoTamanho; i++){
		    novoArray[i] = array[i];
	    }
	    delete[] array;
	    array = newArray;
	    antigoTamanho = novoTamanho;
    }    

    bool submit(Order order){
	    if (order.getType() == 'B'){//para compra
		    buyOrders[buyCount] = order;
		    buyCount++;
		    if (buyCount + 1 >= tamanhoBuy){
			    ajustarTamanho(buyOrders, tamanhoBuy, int(tamanhoBuy*1.2));
		    }
		    int menorPreco = sellOrders[0].getPrice(); //verificar erros
		    int guardarIndice;
		    for (int i = 0; i<tamanhoSell; i++){
			    if (sellOrders[i].getPrice() < menorPreco){
				    menorPreco = sellOrders[i].getPrice();
				    guardarIndice = i;
			    }
		    if (buyOrders[buyCount-1].getPrice() >= menorPreco){
			    transactions[transactionsCount] = Transactions(buyOrders[buyCount-1].getId(), sellOrders[guardarIndice].getId(), buyOrders[buyCount - 1].getPrice());
			    transactionsCount++;
		    }
		    printBuyOrders();
		    printSellOrders();
		    printTransactions();
		    return true;
	    }
	    else if(order.getType() == 'S'){//para venda
	    	    sellOrders[sellCount] = order;
		    sellCount++;
		    if (sellCount + 1>= tamanhoSell){
			    ajustarTamanho(sellOrders, tamanhoSell, int(tamanhoSell*1.2));
		    }
                    int menorPreco = buyOrders[0].getPrice(); //verificar erros
		    int guardarIndice;
		    for (int i = 0; i<tamanhoBuy; i++){
                            if (buyOrders[i].getPrice() < menorPreco){
                                    menorPreco = buyOrders[i].getPrice();
                                    guardarIndice = i;
                            }
                    if (sellOrders[sellCount-1].getPrice() >= menorPreco){
                            transactions[transactionsCount] = Transactions(sellOrders[sellCount-1].getId(), buyOrders[guardarIndice].getId(), sellOrders[buyCount - 1].getPrice());
                            transactionsCount++;
                    }
                    printBuyOrders();
                    printSellOrders();
                    printTransactions();
		    return true;
	    }
	    else{
		    return false;
	    }
	    
    }
    bool cancel(int id){
	    for (int i = 0; i< (buyCount > sellCount ? buyCount : sellCount);i++){
		    if (buyOrders[i].getId() == id){
			    // remocao do id na lista;
			    return true;
		    }
		    else if(sellOrders[i].getId() == id){
			    // remocao do id na lista;
			    return true;
		    }
	    }
	    return false;
    }

    Order* getBuyOrders(int* n){
	    *n = tamanhoBuy;
	    return buyOrders;
    }
    Order* getSellOrders(int* n){
	    *n = tamanhoSell;
	    return sellOrders;
    }
    Transaction* getTransactions(int* n){
	    *n = tamanhoTransactions;
	    return transactions;
    }
    void printBuyOrders(){
	cout<<"Buy Orders: "<<endl;
	if (tamanhoBuy == 0){
		cout<<"(empty)"<<endl;
	}
	else{
		for (int i = 0; i<tamanhoBuy; i++){
		cout<<"["<<buyOrders[i].getId()<<" | "<<buyOrders[i].getPrice()<<" | "<<buyOrders[i].getTimestamp()<<"]"<<endl;
		}
	}
    void printSellOrders(){
        cout<<"Sell Orders: "<<endl;
        if (tamanhoSell == 0){
                cout<<"(empty)"<<endl;
        }
        else{
                for (int i = 0; i<tamanhoSell; i++){
			cout<<"["<<sellOrders[i].getId()<<" | "<<sellOrders[i].getPrice()<<" | "<<sellOrders[i].getTimestamp()<<"]"<<endl;
                }
        }
    }
    void printTransactions(){
        cout<<"Transactions:"<<endl;
        if (tamanhoTransactions == 0){
                cout<<"(empty)"<<endl;
        }
        else{
                for (int i = 0; i<tamanhoTransactions; i++){
			cout<<"["<<transactions[i].getBuyOrderId()<<", "<<transactions[i].getSellOrdersId()<<", "<<transactions[i].getExecutionPrice()<<"]"<<endl;
                }
        }
    }
};
