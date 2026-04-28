# Projeto Acadêmico: Merge Sort em Lista Encadeada Simples (C++)

## Objetivo do projeto

Este projeto tem como objetivo implementar o algoritmo **Merge Sort** em uma **Lista Encadeada Simples**, de forma didática e organizada para estudo em disciplina de **Projeto e análise de algoritmos**.

A proposta é demonstrar, na prática:

- como a lista é dividida em duas metades;
- como as metades ordenadas são intercaladas;
- como fica o resultado antes, durante e depois da ordenação.

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
    └── gerar_vetores.cpp
```

## Compilação
Primeiro, é preciso gerar os arquivos de teste com gerar_vetores.cpp:

g++ -std=c++17 -Wall -Wextra -pedantic gerar_vetores.cpp -o gerar_vetores
./gerar_vetores

Em seguida, compile o programa principal:

g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o mergesort_lista

## Execução
Após compilar, execute:
./gerar_vetores
e depois:
./mergesort_lista

O programa exibirá um menu com duas opções:
Teste automático: carrega automaticamente os arquivos gerados (melhor_caso, pior_caso, quase_ordenado) e ordena cada um, exibindo o tempo de execução.
Modo manual: permite inserir valores um a um (no início ou no final), imprimir, ordenar, buscar e remover elementos da lista.

## Exemplo do que o programa faz
No modo de teste automático, o programa:
lê uma lista encadeada a partir de um arquivo .txt gerado pelo gerar_vetores;
imprime a lista original e seu tamanho;
aplica o Merge Sort, exibindo cada etapa de divisão e intercalação;
imprime a lista ordenada em ordem crescente;
exibe o tempo de execução em microssegundos para cada caso.

No modo manual, o programa:
permite ao usuário inserir valores no início ou no final da lista;
imprime a lista atual a qualquer momento;
aplica o Merge Sort sob demanda, com medição de tempo;
permite buscar ou remover um valor específico. em ordem crescente.

## Saída esperada (exemplo):

```text
Lista original: 42 -> 7 -> 19 -> 3 -> 25 -> 11 -> 30
Lista ordenada: 3 -> 7 -> 11 -> 19 -> 25 -> 30 -> 42
```

## Complexidade do algoritmo

- **Tempo (melhor caso, caso médio e pior caso):** `O(n log n)`
- **Espaço auxiliar (recursão):** `O(log n)`

Por que O(n log n)?
A cada nível de recursão o problema é dividido ao meio, gerando log n níveis. Em cada nível, todos os n elementos são percorridos para intercalar as sublistas. O resultado é n × log n operações. Esse custo é igual nos três casos pois a divisão sempre ocorre independentemente da ordem inicial dos elementos.

Como a ordenação é feita diretamente sobre a lista encadeada (ajuste de ponteiros), o algoritmo é uma excelente alternativa para estruturas lineares dinâmicas.

## Integrantes e Divisão de tarefas
