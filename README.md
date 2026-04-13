# Descrição do Projeto

Sistema básico para controle de ordens de compra e venda de uma única ação, desenvolvido com ênfase no uso de alocação dinâmica de memória e na implementação de estruturas de dados próprias.

Cada ordem contém:

- id: identificador único da ordem.
- tipo: ‘B’ para compra (buy) e ‘S’ para venda (sell).
- preço: valor unitário da ordem.
- timestamp: marca temporal que indica o momento da submissão.

O sistema mantém as ordens ativas organizadas em livros de ofertas e realiza automaticamente transações sempre que há correspondência de preços entre ordens de compra e venda.

# Instruções de compilação

No terminal, execute:

```bash
g++ main.cpp Order.cpp OrderBook.cpp Transaction.cpp -o order_book
```

# Instruções de execução

Após compilar, execute:

```bash
.\order_book.exe
```

# Uma breve explicação de como os dados estão organizados internamente no sistema.

O sistema implementado organiza internamente as informações por meio de três estruturas principais: ordens de compra (buyOrders), ordens de venda (sellOrders) e transações realizadas (transactions). Todas essas estruturas são armazenadas em arrays dinâmicos alocados na heap, o que permite que o sistema cresça conforme novas ordens são inseridas, sem depender de um tamanho fixo definido em tempo de compilação.

# Saída esperada

Ao rodar o programa, o sistema processa as ordens e apresenta o resultado de cada operação realizada. A seguir, é mostrado um exemplo de saída produzido pelo `main.cpp`.

```text
Buy Orders: 
(empty)
Sell Orders:
[2 | 100 | 23]
Transactions:
(empty)
1

Buy Orders:
(empty)
Sell Orders:
(empty)
Transactions:
[1, 2, 120]
1

Buy Orders:
[3 | 100 | 35]
Sell Orders:
(empty)
Transactions:
[1, 2, 120]
1

Buy Orders:
[3 | 100 | 35]
[4 | 90 | 56]
Sell Orders:
(empty)
Transactions:
[1, 2, 120]
1

Buy Orders:
[3 | 100 | 35]
[4 | 90 | 56]
[5 | 100 | 78]
Sell Orders:
(empty)
Transactions:
[1, 2, 120]
1

Buy Orders:
[4 | 90 | 56]
[5 | 100 | 78]
Sell Orders:
(empty)
Transactions:
[1, 2, 120]
[3, 6, 80]
1

Buy Orders:
[4 | 90 | 56]
Sell Orders:
(empty)
Transactions:
[1, 2, 120]
[3, 6, 80]
[5, 7, 100]
1

Quantidade de Ordens de compra 1
1
Buy Orders:
(empty)
Sell Orders:
(empty)
Transactions:
[1, 2, 120]
[3, 6, 80]
[5, 7, 100]

```
