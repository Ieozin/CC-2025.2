#include <stdio.h>

// --- Constantes para o Jogo ---
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 1
#define ACERTO 2
#define ERRO 3

int main()
{
    // --- Criação do Tabuleiro ---
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
        {

            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // --- Posicionando Navios ---
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    tabuleiro[3][4] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[5][4] = NAVIO;
    tabuleiro[6][4] = NAVIO;

    // --- Posicionando Navios na Diagonal ---
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    tabuleiro[8][8] = NAVIO;

    // --- Exibindo o Tabuleiro ---
    printf("--- Jogo de Batalha Naval ---\n");
    printf("Tabuleiro Inicial (0 = Água, 1 = Navio):\n\n");

    // Imprimindo os números das colunas
    printf("  ");
    for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
    {
        printf("%d ", coluna);
    }
    printf("\n");

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {
        printf("%d ", linha);
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n"); 
    }

    // --- Simulação de Habilidades Especiais ---
    int origem_linha = 5;
    int origem_coluna = 5;

    printf("\nSimulando um ataque especial em CRUZ na posição (%d, %d)...\n", origem_linha, origem_coluna);

    for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
    {
        if (tabuleiro[origem_linha][coluna] == NAVIO)
        {
            tabuleiro[origem_linha][coluna] = ACERTO;
        }
        else if (tabuleiro[origem_linha][coluna] == AGUA)
        {
            tabuleiro[origem_linha][coluna] = ERRO;
        }
    }

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {

        if (linha != origem_linha)
        {
            if (tabuleiro[linha][origem_coluna] == NAVIO)
            {
                tabuleiro[linha][origem_coluna] = ACERTO;
            }
            else if (tabuleiro[linha][origem_coluna] == AGUA)
            {
                tabuleiro[linha][origem_coluna] = ERRO;
            }
        }
    }

    // --- Exibindo o Tabuleiro Após o Ataque ---
    printf("\nTabuleiro Após Ataque (0=Água, 1=Navio, 2=Acerto, 3=Erro):\n\n");
    printf("  ");
    for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
    {
        printf("%d ", coluna);
    }
    printf("\n");

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {
        printf("%d ", linha);
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}