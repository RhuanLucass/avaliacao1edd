# Avaliação 1 – Laboratório de Estrutura de Dados
## Engenharia de Computação / CEFET-MG
### Rhuan Lucas Barbosa Fernandes

Nesta avaliação, a análise se concentrou no tamanho do lado dos quadrados como atributo principal. Na lista ordenada, o tamanho do lado foi usado para inserir o quadrado no local apropriado; durante as buscas, o lado foi utilizado para encontrar o quadrado correspondente.

### 1. Inserção
Para inserir 1000 quadrados em ordem crescente (2), decrescente (4) e aleatória (5) nas listas sequencial, ordenada e encadeada, respectivamente, as seguintes atribuições e comparações foram registradas:

| Caso | Sequencial | Ordenada | Encadeada |
|------|------------|----------|-----------|
| 2-a  | 3.000      | 1.003.000| 501.501   |
| 2-b  | 3.000      | 1.003.000| 501.501   |
| 2-c  | 3.000      | 757.351  | 501.501   |

As comparações e atribuições foram registradas para cada caso de inserção.

### 2. Busca
Foram realizadas buscas repetidas vezes para o mesmo quadrado nas listas sequencial, ordenada e encadeada. As comparações e atribuições para diferentes tamanhos de lados foram registradas.

#### Listas em ordem Crescente:

| Tamanho do Lado | Sequencial | Ordenada | Encadeada |
|------------------|------------|----------|-----------|
| 1                | 404        | 4.646    | 303       |
| 1001             | 505        | 9.797    | 202.505   |
| 500              | 152.106    | 14.948   | 303.606   |
| 1000             | 455.207    | 19.594   | 505.707   |

#### Listas em ordem Decrescente:

| Tamanho do Lado | Sequencial | Ordenada | Encadeada |
|------------------|------------|----------|-----------|
| 1                | 455.611    | 24.240   | 506.010   |
| 1001             | 455.712    | 29.391   | 708.212   |
| 500              | 607.313    | 34.542   | 809.313   |
| 1000             | 910.414    | 39.188   | 1.011.414 |

#### Listas em ordem Aleatória:

| Tamanho do Lado | Sequencial | Ordenada | Encadeada |
|------------------|------------|----------|-----------|
| 1                | 272.498    | 4.646    | 181.699   |
| 1001             | 272.599    | 9.797    | 202.505   |
| 500              | 370.266    | 14.948   | 449.046   |
| 1000             | 415.211    | 19.594   | 479.043   |

### Considerações
Os resultados obtidos na inserção mostram que a lista sequencial tem um desempenho superior em termos de comparações e atribuições para os três tipos de ordenação. Isso se deve à sua capacidade de inserir no fim da lista, verificando apenas se a lista está cheia antes de adicionar o quadrado. Já a lista ordenada insere todos os quadrados em ordem crescente, enquanto a lista encadeada percorre toda a lista até encontrar o último elemento para inserção, resultando em maior custo computacional.

As buscas refletem uma diferença significativa entre a lista ordenada e as outras duas. A busca binária na lista ordenada reduz o tamanho da busca pela metade a cada iteração, resultando em complexidade O(log(n)) no pior caso, enquanto as buscas nas listas sequencial e encadeada percorrem toda a lista, gerando um custo computacional muito maior.

Em relação à adequação das listas em diferentes situações, a lista sequencial é mais eficiente quando os elementos buscados estão no início da lista, devido à sua inserção vantajosa e custo de busca baixo nesse contexto. A lista ordenada se destaca quando o elemento buscado está no meio da lista, já que sua inserção é custosa, mas a busca divide a lista ao meio, resultando em um custo baixo para encontrar o quadrado.

A lista encadeada não apresenta um desempenho superior às outras duas para este caso específico, mas é melhor para inserção e remoção de elementos no meio da lista, uma vez que é uma estrutura dinâmica, minimizando o custo dessas operações.

Estes dados ajudam a identificar o tipo de lista mais adequado para diferentes situações, considerando suas características de inserção e busca.
