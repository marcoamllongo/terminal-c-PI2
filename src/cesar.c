#include "cesar.h"
#include "validacoes.h"

#include <stdio.h>
#include <string.h>

void cesar_aplicar(char texto[], int desloc, int decifrar) {
    int i;
    if (decifrar == 1)
        desloc = (26 - desloc) % 26;

    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
            texto[i] = 'A' + (texto[i] - 'A' + desloc) % 26;
        else if (texto[i] >= 'a' && texto[i] <= 'z')
            texto[i] = 'a' + (texto[i] - 'a' + desloc) % 26;
    }
}

int cesar_arquivo(const char *nome, int desloc, int decifrar) {
    FILE *entrada, *saida;
    char nome_saida[120], linha[500];

    if (!nome_arquivo_valido(nome) || strlen(nome) > 99) {
        printf("Erro: nome de arquivo invalido.\n");
        return 1;
    }
    entrada = fopen(nome, "r");
    if (entrada == NULL) {
        printf("Erro: arquivo nao encontrado.\n");
        return 1;
    }

    strcpy(nome_saida, nome);
    strcat(nome_saida, decifrar == 1 ? ".decifrado" : ".cifrado");
    saida = fopen(nome_saida, "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saida.\n");
        fclose(entrada);
        return 1;
    }

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        cesar_aplicar(linha, desloc, decifrar);
        fprintf(saida, "%s", linha);
    }
    fclose(entrada);
    fclose(saida);
    printf("Arquivo gerado: %s\n", nome_saida);
    return 0;
}

int comando_cesar(const char *args) {
    char acao[20], modo[3], resto[500];
    char *espaco, *entrada = resto;
    int desloc, decifrar, tam;

    if (args == NULL || sscanf(args, "%19s %2s %499[^\n]", acao, modo, resto) != 3) {
        printf("Erro: use cesar cifrar|decifrar -t|-f <entrada> <deslocamento>\n");
        return 1;
    }
    decifrar = (strcmp(acao, "decifrar") == 0);
    if ((strcmp(acao, "cifrar") != 0 && !decifrar) ||
        (strcmp(modo, "-t") != 0 && strcmp(modo, "-f") != 0)) {
        printf("Erro: use cifrar/decifrar e -t (texto) ou -f (arquivo).\n");
        return 1;
    }

    espaco = strrchr(resto, ' ');
    if (espaco == NULL || !deslocamento_valido(espaco + 1, &desloc)) {
        printf("Erro: informe um deslocamento de 0 a 25.\n");
        return 1;
    }
    *espaco = '\0';

    tam = strlen(resto);
    if (tam >= 2 && resto[0] == '"' && resto[tam - 1] == '"') {
        resto[tam - 1] = '\0';
        entrada = resto + 1;
    }

    if (strcmp(modo, "-f") == 0)
        return cesar_arquivo(entrada, desloc, decifrar);

    cesar_aplicar(entrada, desloc, decifrar);
    printf("%s\n", entrada);
    return 0;
}