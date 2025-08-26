# Tema 5: Jogo de Batalha Naval

Este arquivo reúne minhas anotações e reflexões sobre o **Tema 5: Jogo de Batalha Naval**, que foca no uso de vetores e matrizes (arrays) em C. Aqui eu misturo resumos das aulas com minhas percepções pessoais — quero que fique com a voz do meu diário de bordo, então mantive as partes em primeira pessoa e destaquei onde tive dificuldade.

## 1. O que são Vetores e Matrizes (Arrays)?

### Vetores (Arrays de 1 Dimensão)

Um **vetor** é como uma fileira de uma caixa de ovos: uma sequência de "divisórias" numeradas que guardam valores do mesmo tipo. A regra principal é que tudo dentro do vetor tem que ser do mesmo tipo (por exemplo, só `int` ou só `float`). O índice sempre começa em zero — ou seja, a primeira posição é `notas[0]`.

Exemplo simples em C:

```c
#include <stdio.h>

int main() {
    int notas[5]; // vetor com 5 posições (índices 0..4)
    notas[0] = 8;
    notas[1] = 7;
    // ...
    printf("Primeira nota: %d\n", notas[0]);
    return 0;
}
```

### Matrizes (Arrays de 2 Dimensões)

Uma **matriz** é como a caixa de ovos inteira — uma estrutura 2D (ou mais dimensões) formada por linhas e colunas. Para acessar um elemento usamos dois índices: `tabuleiro[linha][coluna]`. Matrizes são perfeitas para representar tabuleiros (como no Batalha Naval).

Exemplo simples em C:

```c
#include <stdio.h>

int main() {
    int tabuleiro[3][3]; // matriz 3x3
    tabuleiro[0][0] = 0; // linha 0, coluna 0
    tabuleiro[1][2] = 1; // linha 1, coluna 2
    printf("Posição (1,2): %d\n", tabuleiro[1][2]);
    return 0;
}
```

## 2. A Combinação Perfeita: Loops + Matrizes

A grande sacada é usar `for` (ou `while`) para **percorrer** vetores e matrizes sem precisar acessar cada posição manualmente. Para vetores um único `for` resolve; para matrizes, o padrão mais comum é usar dois `for` aninhados: um para as linhas e outro para as colunas. Dessa forma dá para "desenhar" ou inicializar um tabuleiro na tela.

Exemplo: inicializar e imprimir uma matriz que representa o tabuleiro do jogo (0 = água, 1 = navio):

```c
#include <stdio.h>

int main() {
    int linhas = 5;
    int colunas = 5;
    int tabuleiro[5][5];

    // Inicializa o tabuleiro com zeros (água)
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coloca um navio simples na posição (2,1) e (2,2)
    tabuleiro[2][1] = 1;
    tabuleiro[2][2] = 1;

    // Imprime o tabuleiro
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

Algumas observações práticas:

* Sempre lembrar que os índices vão de `0` até `n-1`.
* Para matrizes `tabuleiro[L][C]`, o primeiro índice é a linha e o segundo é a coluna.
* Usar loops aninhados facilita validar posições, procurar navios, checar colisões e desenhar o tabuleiro na tela.

### Dica rápida

Quando começar a ficar confuso com os índices, desenhe no papel as linhas e colunas numeradas a partir de zero — isso ajuda muito a visualizar onde cada `(i, j)` está no tabuleiro.

### Meu Entendimento Pessoal

O último tema da disciplina é sobre vetores e matrizes, que a gente vai usar pra fazer um jogo de Batalha Naval. A ideia é parar de criar uma variável pra cada coisa e começar a usar "caixas" com várias divisórias para guardar um monte de dados do mesmo tipo. Eu aprendi a diferença entre Vetor, que é como uma fileira de uma caixa de ovos (1D), e Matriz, que é a caixa de ovos inteira (2D ou mais). A regra principal é que tudo dentro tem que ser do mesmo tipo, tipo só número inteiro ou só `float`. E o mais importante: a contagem das "divisórias" (o índice) sempre começa do zero! Para acessar uma posição num vetor eu uso `notas[0]`, e numa matriz eu preciso de dois números, o da linha e o da coluna, tipo `tabuleiro[0][0]`.

A grande sacada é usar loops pra percorrer essas estruturas. Em vez de acessar cada posição uma por uma, eu posso usar um loop `for` pra passar por um vetor. Para uma matriz, o normal é usar dois `for`, um dentro do outro (aninhado), um pra linha e outro pra coluna. Confesso que quando a matéria chegou em `for` e `while`, eu comecei a entender nada. Essa parte de loops é mais difícil e abstrata pra mim. Preciso estudar e praticar mais pra fixar. Mas pelo menos, com a ajuda dos exercícios e da revisão, consegui terminar a parte do xadrez. Agora é focar em entender bem as matrizes para o Batalha Naval. A ideia de que um loop dentro do outro pode "desenhar" um tabuleiro na tela faz sentido.

---

Anotações em andamento...
