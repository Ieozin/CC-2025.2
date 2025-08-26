#include <stdio.h>

// Função para mover a Torre
void moverTorre(int passos)
{

    if (passos > 0)
    {
        printf("Direita\n");

        moverTorre(passos - 1);
    }
}

// Função para mover o Bispo
void moverBispo(int passos)
{
    if (passos > 0)
    {
        printf("Cima, Direita\n");
        moverBispo(passos - 1);
    }
}

// Função para mover a Rainha
void moverRainha(int passos)
{
    if (passos > 0)
    {
        printf("Esquerda\n");
        moverRainha(passos - 1);
    }
}

int main()
{

    // --- Movimento da Torre ---
    printf("Movimento da Torre:\n");
    moverTorre(5);

    printf("\n");
    // --- Movimento do Bispo ---
    printf("Movimento do Bispo:\n");
    moverBispo(5);

    printf("\n");

    // --- Movimento da Rainha ---
    printf("Movimento da Rainha:\n");
    moverRainha(8);

    printf("\n");

    // --- Movimento do Cavalo ---

    printf("Movimento do Cavalo:\n");

    for (int i = 0; i < 2; i++)
    {
        printf("Cima\n");
    }

    for (int i = 0; i < 1; i++)
    {
        printf("Direita\n");
    }

    return 0;
}