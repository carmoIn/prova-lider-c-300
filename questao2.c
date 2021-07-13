//
// Created by helci on 13/07/2021.
//

#include <stdio.h>
#include <conio.h>
#include "questao2.h"

int tamanhoString(char *str) // função strlen
{
    int contador = 0;
    while (str[contador] != '\0')
    {
        contador++;
    }
    return contador;
}


void codificar(int chave,char *entrada, char *saida)
{
    int i;
    int tamanho = tamanhoString(entrada);
    for (i = 0; i < tamanho; i++)
    {
        saida[i] = entrada[i] + chave;
    }
    saida[i] = '\0';
}

void decodificar(int chave, char *entrada, char *saida)
{
    int i;
    int tamanho = tamanhoString(entrada);
    for (i = 0; i < tamanho; i++)
    {
        saida[i] = entrada[i] - chave;
    }
    saida[i] = '\0';
}

void questao2()
{
    int chave;
    char mensagem[100];
    char codificado[100], decodificado[100];

    printf("\nDigite a chave e uma mensagem: ");
    scanf("%d %[^\n]", &chave, mensagem);

    codificar(chave, mensagem, codificado);
    printf("%s\n", codificado);
    decodificar(chave, codificado, decodificado);
    printf("%s\n", decodificado);

    getch();
}