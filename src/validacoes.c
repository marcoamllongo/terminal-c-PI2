#include <string.h>
#include "validacoes.h"

int nome_arquivo_valido(const char *nome)
{
    if (nome == NULL || nome[0] == '\0') {
        return 0;
    }

    if (strcmp(nome, ".") == 0 || strcmp(nome, "..") == 0) {
        return 0;
    }

    if (strchr(nome, '/') != NULL || strchr(nome, '\\') != NULL) {
        return 0;
    }

    return 1;
}

int deslocamento_valido(const char *texto, int *valor)
{
    int numero = 0;
    int i;

    if (texto == NULL || texto[0] == '\0') {
        return 0;
    }

    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] < '0' || texto[i] > '9') {
            return 0;
        }

        numero = numero * 10 + (texto[i] - '0');

        if (numero > 25) {
            return 0;
        }
    }

    if (valor != NULL) {
        *valor = numero;
    }

    return 1;
}