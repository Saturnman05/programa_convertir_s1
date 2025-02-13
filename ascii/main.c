/*
Realice un programa que convierta un carácter ASCII a su equivalente numérico o viceversa.
Ejemplo: ASCII 65 equivale al carácter "A" o el carácter "b" equivale al ASCII 98.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void menu();
int ascii_num(char);
char num_ascii(int);

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        menu();
    }
    else if (argc == 2)
    {
        int is_number = 1;
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                is_number = 0;
                break;
            }
        }

        if (is_number)
        {
            int num = atoi(argv[1]);
            printf("El carácter equivalente a %d es: '%c'\n", num, num_ascii(num));
        }
        else if (argv[1][1] == '\0')
        {
            char character = argv[1][0];
            printf("El valor ASCII de '%c' es: %d\n", character, ascii_num(character));
        }
        else
        {
            printf("Error: Ingresa un solo carácter o un número válido.\n");
        }
    }
    return 0;
}

void menu()
{
    int select = 0;

    do
    {
        printf("Digite su opcion:\n");
        printf("1. ASCII a numero\n");
        printf("2. Numero a ASCII\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            char character;
            printf("Ingrese un carácter: ");
            scanf(" %c", &character);
            printf("El valor ASCII de '%c' es: %d\n\n", character, ascii_num(character));
            break;
        case 2:
            int num;
            printf("Ingrese un numero: ");
            scanf(" %d", &num);
            printf("El carácter equivalente a %d es: '%c'\n\n", num, num_ascii(num));
            break;
        case 3:
            printf("...Cerrando el programa\n\n");
            return;
        default:
            printf("Error. La opcion que escogiste no coincide con las opciones disponibles.\n\n");
            break;
        }
    } while (select > 0 && select < 4);
}

int ascii_num(char a)
{
    return (int)a;
}

char num_ascii(int a)
{
    return (char)a;
}