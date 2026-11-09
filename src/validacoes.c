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