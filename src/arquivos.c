#include "arquivos.h"

#include <stdio.h>
#include <string.h>

// Comando CRIAR
int comando_criar(const char *args)
{
    FILE *arquivo;
    char nome[100];
    char texto[1000];

    // Verifica se os argumentos foram informados
    if (args == NULL || args[0] == '\0')
    {
        printf("Nome ou texto nao informado!\n");
        return 1;
    }

    // Separa o nome do arquivo e o texto
    if (sscanf(args, "%99s %999[^\n]", nome, texto) != 2)
    {
        printf("Nome ou texto nao informado!\n");
        return 1;
    }

    // Verifica se o nome possui barras
    if (strchr(nome, '/') != NULL || strchr(nome, '\\') != NULL)
    {
        printf("Nome do arquivo invalido!\n");
        return 1;
    }

    // Abre o arquivo para escrita
    arquivo = fopen(nome, "w");

    if (arquivo == NULL)
    {
        printf("Erro ao criar arquivo!\n");
        return 1;
    }

    // Grava o texto no arquivo
    fprintf(arquivo, "%s", texto);

    fclose(arquivo);

    printf("Arquivo criado com sucesso!\n");

    return 0;
}


// Comando CAT
int comando_cat(const char *args)
{
    FILE *arquivo;
    char texto[1000];

    // Verifica se o nome foi informado
    if (args == NULL || args[0] == '\0')
    {
        printf("Nome do arquivo nao informado!\n");
        return 1;
    }

    // Abre o arquivo para leitura
    arquivo = fopen(args, "r");

    if (arquivo == NULL)
    {
        printf("Arquivo nao encontrado!\n");
        return 1;
    }

    // Lê e exibe o conteúdo
    while (fgets(texto, sizeof(texto), arquivo) != NULL)
    {
        printf("%s", texto);
    }

    fclose(arquivo);

    printf("\n");

    return 0;
}
