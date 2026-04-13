#include <iostream>
#include "Order.hpp"
#include "Transaction.hpp"
#include "OrderBook.hpp"
using namespace std;

int main(){
    //exemplo requerido na atividade
    OrderBook sistema{};

    Order ord_1(2,'S', 100, 23);
    cout << sistema.submit(ord_1)<< "\n" << endl;

    Order ord_2(1,'B', 120, 12);
    cout << sistema.submit(ord_2)<< "\n" << endl;

    Order ord_3(3, 'B', 100, 35 );
    cout << sistema.submit(ord_3)<< "\n" << endl;

    Order ord_4(4, 'B', 90, 56);
    cout << sistema.submit(ord_4)<< "\n" << endl;

    Order ord_5(5, 'B', 100, 78);
    cout << sistema.submit(ord_5)<<"\n"<< endl;

    Order ord_6(6, 'S', 80, 87);
    cout << sistema.submit(ord_6)<< "\n" << endl;

    Order ord_7(7, 'S', 100, 23);
    cout << sistema.submit(ord_7)<< "\n" << endl;

    int n;
    sistema.getBuyOrders(&n);
    cout << "Quantidade de Ordens de compra " << n << "\n";

    cout << sistema.cancel(4) << "\n";

    sistema.printBuyOrders();
    sistema.printSellOrders();
    sistema.printTransactions();

    return 0;
}