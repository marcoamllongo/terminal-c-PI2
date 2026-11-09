

#include <stdio.h>
#include <string.h>

#include "comandos.h"
#include "arquivos.h"
#include "cesar.h"

int main(void)
{
    char entrada[256];

    while (1)
    {
        printf("terminal> ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            break;

        entrada[strcspn(entrada, "\n")] = '\0';

        char *nome = entrada;

        while (*nome == ' ' || *nome == '\t')
            nome++;

        if (*nome == '\0')
            continue;

        char *args = nome;

        while (*args != '\0' && *args != ' ' && *args != '\t')
            args++;

        if (*args != '\0')
        {
            *args = '\0';
            args++;

            while (*args == ' ' || *args == '\t')
                args++;
        }

        if (strcmp(nome, "sair") == 0)
        {
            printf("Encerrando terminal...\n");
            break;
        }
        else if (strcmp(nome, "ajuda") == 0)
        {
            comando_ajuda(args);
        }
        else if (strcmp(nome, "ec") == 0)
        {
            comando_ec(args);
        }
        else if (strcmp(nome, "criar") == 0)
        {
            comando_criar(args);
        }
        else if (strcmp(nome, "cat") == 0)
        {
            comando_cat(args);
        }
        else if (strcmp(nome, "cesar") == 0)
        {
            comando_cesar(args);
        }
        else
        {
            printf("Erro: comando desconhecido.\n");
        }
    }

    return 0;
}