
#include <stdio.h>
#include <string.h>

int main(void)
{
    char comando[256];

    while (1)
    {
        printf("terminal> ");

        if (scanf(" %255[^\n]", comando) != 1)
            break;

        if (strcmp(comando, "sair") == 0)
        {
            printf("Encerrando terminal...\n");
            break;
        }

        printf("Comando ainda nao implementado.\n");
    }

    return 0;
}