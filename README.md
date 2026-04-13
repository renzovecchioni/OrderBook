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



# Saída esperada

Ao rodar o programa, o sistema processa as ordens e apresenta o resultado de cada operação realizada. A seguir, é mostrado um exemplo de saída produzido pelo `main.cpp`.

```text

lorem

```
