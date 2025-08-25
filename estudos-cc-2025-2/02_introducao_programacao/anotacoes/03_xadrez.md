# Tema 4: Movimentação de Peças de Xadrez

Estou documentando meu estudo sobre **estruturas de repetição** (loops) a partir da aula — quero que isso funcione como um guia rápido e com exemplos práticos ligados ao projeto do xadrez. Eu entendi que a ideia principal é evitar repetir código à mão e ensinar o computador a executar ações repetitivas para a gente.

## 1. As Ferramentas de Repetição (Loops)

### `for` — Torre

Eu entendi que o `for` é ideal quando eu sei de antemão quantas vezes quero repetir algo, por exemplo "mover de 1 a 4 casas". A sintaxe organiza inicialização, condição e incremento em uma linha só, o que deixa o código bem limpo.

Exemplo: mover a Torre (Torre se move em linha reta ao longo de uma fileira ou coluna). Aqui uso um `for` para mover numa direção X por `steps` casas:

```c
#include <stdio.h>

/* Exemplo simples: mover a Torre para a direita 'steps' casas */
int main() {
    int x = 0, y = 0;      // posição inicial da Torre (coluna x, linha y)
    int steps = 4;        // quantas casas queremos avançar
    printf("Posição inicial: (%d, %d)\n", x, y);

    // mover para a direita 'steps' vezes
    for (int i = 0; i < steps; i++) {
        x += 1; // mover uma casa para a direita
        printf("Passo %d -> (%d, %d)\n", i+1, x, y);
    }

    printf("Posição final: (%d, %d)\n", x, y);
    return 0;
}
```

### `while` — Bispo

Eu entendi que o `while` é melhor quando eu não sei quantas vezes vou repetir, mas sei a condição para continuar — tipo "enquanto não chegar na borda". O que eu peguei de mais importante é que eu preciso **lembrar de atualizar** as variáveis dentro do loop; se não, vira loop infinito.

Exemplo: mover o Bispo em diagonal até alcançar uma borda ou um destino (aqui eu mostro movimento diagonal até sair do tabuleiro):

```c
#include <stdio.h>
#include <stdbool.h>

/* Exemplo: mover o Bispo diagonalmente até a borda */
int main() {
    int x = 2, y = 0; // posição inicial do Bispo (coluna x, linha y)
    printf("Posição inicial do Bispo: (%d, %d)\n", x, y);

    // queremos mover diagonalmente para cima-direita até a borda (x,y entre 0 e 7)
    while (x < 7 && y < 7) {
        x += 1; // atualizar dentro do loop! (evita loop infinito)
        y += 1;
        printf("Bispo se moveu para (%d, %d)\n", x, y);
    }

    printf("Bispo parou em (%d, %d) - borda ou condição atingida\n", x, y);
    return 0;
}
```

### `do-while` — Rainha

Eu entendi que o `do-while` é parecido com o `while`, mas garante que o bloco execute **pelo menos uma vez** antes de checar a condição. Isso é útil quando quero executar uma ação e depois decidir se continuo — por exemplo, mover a Rainha passo a passo até um destino, garantindo pelo menos uma tentativa de movimento.

Exemplo: mover a Rainha em direção a um destino (uma casa alvo). O `do-while` permite mover e só depois verificar se já alcançamos o destino:

```c
#include <stdio.h>
#include <stdlib.h>

/* Exemplo: mover a Rainha um passo por iteração em direção a (tx, ty) */
int main() {
    int x = 0, y = 0;   // posição inicial da Rainha
    int tx = 4, ty = 3; // posição alvo
    printf("Rainha inicia em (%d, %d). Alvo: (%d, %d)\n", x, y, tx, ty);

    // mover um passo em direção ao alvo até chegar lá
    do {
        if (x < tx) x++;
        else if (x > tx) x--;

        if (y < ty) y++;
        else if (y > ty) y--;

        printf("Rainha se moveu para (%d, %d)\n", x, y);
        // o do-while garante que acompanhe pelo menos um movimento
    } while (x != tx || y != ty);

    printf("Rainha alcançou o alvo (%d, %d)\n", x, y);
    return 0;
}
```

## 2. Conceitos Mais Avançados

### Loops Aninhados

Eu aprendi que *loops aninhados* são quando um loop fica dentro de outro. No xadrez, eles são úteis para percorrer o tabuleiro inteiro (por exemplo, um `for` para linhas dentro de um `for` para colunas). Eu uso isso para verificar todas as casas, detectar colisões ou gerar movimentos possíveis para peças que dependem de combinação de eixos.

Pequena ideia em pseudo-C:

```c
for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
        // verifica casa (col, row)
    }
}
```

### Recursividade

Recursividade é quando uma função chama a si mesma. Eu percebi que ela é poderosa para problemas que se quebram em subproblemas similares — por exemplo, explorar caminhos possíveis em um tabuleiro (backtracking), ou gerar movimentos em profundidade (como para avaliadores de jogadas). O cuidado é sempre ter uma condição de parada clara, senão vira recursão infinita e estoura a pilha.

Exemplo conceitual (pseudo):

```c
void explorar(int profundidade) {
    if (profundidade == 0) return; // condição de parada
    // processa estados
    explorar(profundidade - 1);
}
```

---

Anotações em andamento...
