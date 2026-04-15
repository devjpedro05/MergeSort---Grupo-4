# Projeto Acadêmico: Merge Sort em Lista Encadeada Simples (C++)

## Objetivo do projeto

Este projeto tem como objetivo implementar o algoritmo **Merge Sort** em uma **Lista Encadeada Simples**, de forma didática e organizada para estudo em disciplina de **Métodos de Ordenação**.

A proposta é demonstrar, na prática:

- como a lista é dividida em duas metades;
- como as metades ordenadas são intercaladas;
- como fica o resultado antes e depois da ordenação.

## Merge Sort em lista encadeada (resumo)

O Merge Sort segue a estratégia de **dividir para conquistar**:

1. Divide a lista em duas partes aproximadamente iguais;
2. Ordena cada parte recursivamente;
3. Intercala as duas sublistas já ordenadas.

Em listas encadeadas, essa abordagem é eficiente porque a intercalação pode ser feita apenas ajustando ponteiros, sem necessidade de realocação de blocos contínuos de memória.

## Estrutura do projeto

```text
/
├── README.md
└── src/
    └── main.cpp
```

## Compilação

No terminal, dentro da pasta do projeto, execute:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o mergesort_lista
```

## Execução

Após compilar, execute:

```bash
./mergesort_lista
```

## Exemplo do que o programa faz

O programa:

- cria uma lista encadeada simples;
- insere valores manualmente;
- imprime a lista original;
- aplica o Merge Sort;
- imprime a lista ordenada em ordem crescente.

Saída esperada (exemplo):

```text
Lista original: 42 -> 7 -> 19 -> 3 -> 25 -> 11 -> 30
Lista ordenada: 3 -> 7 -> 11 -> 19 -> 25 -> 30 -> 42
```

## Complexidade do algoritmo

- **Tempo (caso médio e pior caso):** `O(n log n)`
- **Espaço auxiliar (recursão):** `O(log n)`

Como a ordenação é feita diretamente sobre a lista encadeada (ajuste de ponteiros), o algoritmo é uma excelente alternativa para estruturas lineares dinâmicas.
