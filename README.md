# Push_swap

## Descrição

O projeto **Push_swap** é um desafio de ordenação que visa ordenar uma pilha de números utilizando um conjunto limitado de operações em duas pilhas. O objetivo é desenvolver um programa que receba uma lista de números e os ordene na menor quantidade possível de operações. Esse projeto é um ótimo exercício para desenvolver habilidades em algoritmos, manipulação de estruturas de dados (pilhas) e otimização de código.

## Funcionalidades

O programa aceita uma lista de números inteiros como entrada e utiliza duas pilhas (`stack_a` e `stack_b`) para executar operações que movem, trocam, giram ou revertem os elementos entre essas pilhas. O objetivo é ordenar a `stack_a` com o menor número de operações possível.

### As operações disponíveis são:

- `sa`: Troca os dois primeiros elementos de `stack_a`.
- `sb`: Troca os dois primeiros elementos de `stack_b`.
- `ss`: Executa `sa` e `sb` simultaneamente.
- `pa`: Move o primeiro elemento de `stack_b` para `stack_a`.
- `pb`: Move o primeiro elemento de `stack_a` para `stack_b`.
- `ra`: Roda todos os elementos de `stack_a` para cima.
- `rb`: Roda todos os elementos de `stack_b` para cima.
- `rr`: Executa `ra` e `rb` simultaneamente.
- `rra`: Roda todos os elementos de `stack_a` para baixo.
- `rrb`: Roda todos os elementos de `stack_b` para baixo.
- `rrr`: Executa `rra` e `rrb` simultaneamente.

## Estrutura do Projeto

- **error_handling**: Contém funções para validação de entradas, checagem de erros e tratamento de argumentos.
- **utilities**: Funções utilitárias para manipulação de memória e gerenciamento de pilhas.
- **stack_operations**: Implementa as operações básicas de pilha como `push`, `swap`, `rotate` e `reverse rotate`.
- **sorting_algorithms**: Contém os algoritmos de ordenação, como o **Radix Sort** e métodos para lidar com pequenas listas de números.
- **libft**: Biblioteca auxiliar contendo funções genéricas de manipulação de strings, memória, etc.

### Arquivos Importantes

- **push_swap.h**: Cabeçalho principal do projeto contendo a definição das estruturas e as declarações de todas as funções.
- **Makefile**: Script de compilação para compilar o projeto de forma eficiente.

## Algoritmos de Ordenação

O projeto utiliza diferentes algoritmos de ordenação, conforme o número de elementos:

- Para listas pequenas (2 a 5 elementos), utiliza métodos como:
  - `sort_two_elements()`
  - `sort_three_elements()`
  - `sort_four_elements()`
  - `sort_five_elements()`

- Para listas maiores, o **Radix Sort** é utilizado. O Radix Sort implementado é um algoritmo eficiente para ordenar grandes volumes de dados inteiros.

### Radix Sort

O **Radix Sort** é usado para listas maiores, aplicando a técnica de distribuição dos números com base em seus bits. O algoritmo segue os seguintes passos:

1. Distribui os números em `stack_b` com base no valor de seus bits.
2. Move os números de volta para `stack_a` até que estejam todos ordenados.

## Como Usar

### Compilação

Para compilar o projeto, utilize o `Makefile`. Execute o seguinte comando no terminal:

```bash
make

```
Isso irá gerar o executável push_swap.

#### O programa irá retornar as operações necessárias para ordenar a lista.

Exemplo de Saída <br>

Entrada:
```bash
./push_swap 3 2 5 1 4

```
Saída esperada:

```bash
sa
rra

```
#### Verificação do Desempenho
O desempenho do algoritmo pode ser medido pelo número de operações geradas para ordenar uma pilha. Idealmente, o número de operações deve ser o mais próximo possível do mínimo necessário para cada caso.

#### Testes
Recomenda-se a execução de diversos testes com diferentes conjuntos de números para verificar a eficiência do algoritmo:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
```bash
ARG=($(shuf -i 1-600 -n 500)); ./push_swap $ARG | wc -l
```
Isso retornará o número de operações utilizadas para ordenar os números.

### Gráficos de Desempenho
Ao comparar diferentes algoritmos e tamanhos de entrada, é interessante incluir gráficos que mostrem a quantidade de operações necessárias para ordenar conjuntos de diferentes tamanhos. Isso ajuda a visualizar a eficiência do algoritmo em diferentes cenários.

### Requisitos
- GCC
- Make

### Contribuição
Sinta-se à vontade para abrir issues ou enviar pull requests com melhorias no código, otimizações e novos testes.

