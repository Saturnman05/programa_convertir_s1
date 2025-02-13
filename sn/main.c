/*
Realice un programa que realice conversiones de sistemas numéricos, pueden elegir un solo de los sistemas numéricos.
Ejemplo: de Binario (base 2) a Decimal (base 10) Número binario 01000001 su equivalente en decimal es 65.
*/

#include <stdio.h>
#include <stdlib.h>

void menu();
char *base_2(char *);
char *base_8(char *);
int base_10(char *);
char *base_16(char *);

int main()
{
    menu();
    return 0;
}

void menu()
{
    char num[100];
    printf("Escribe un número en binario, octal, hexadecimal o decimal.\n");
    printf("Prefijo del número\n");
    printf("Binario -> 0b\n");
    printf("Octal -> 0\n");
    printf("Decimal -> N/A\n");
    printf("Hexadecimal -> 0x\n");
    printf("Número: ");

    scanf("%99s", num);

    if (num[0] == '0' && num[1] == 'b')
    {
        char *octal = base_8(num);
        printf("\nOctal: %s\n", octal);
        int decimal = base_10(num);
        printf("Decimal: %d\n", decimal);
        char *hexadecimal = base_16(num);
        printf("Hexadecimal: %s\n", hexadecimal);
    }
    else if (num[0] == '0' && num[1] == 'x')
    {
        char *binario = base_2(num);
        printf("\nBinario: %s\n", binario);
        char *octal = base_8(num);
        printf("Octal: %s\n", octal);
        int decimal = base_10(num);
        printf("Decimal: %d\n", decimal);
    }
    else if (num[0] == '0')
    {
        char *binario = base_2(num);
        printf("\nBinario: %s\n", binario);
        int decimal = base_10(num);
        printf("Decimal: %d\n", decimal);
        char *hexadecimal = base_16(num);
        printf("Hexadecimal: %s\n", hexadecimal);
    }
    else
    {
        char *binario = base_2(num);
        printf("\nBinario: %s\n", binario);
        char *octal = base_8(num);
        printf("Octal: %s\n", octal);
        char *hexadecimal = base_16(num);
        printf("Hexadecimal: %s\n", hexadecimal);
    }
}

int base_10(char *num)
{
    int decimal = 0;
    int i;

    if (num[0] == '0' && num[1] == 'x')
    {
        i = 2;
        while (num[i] != '\0')
        {
            decimal *= 16;
            if (num[i] >= 0 && num[i] <= 9)
            {
                decimal += num[i] - '0';
            }
            else if (num[i] >= 'A' && num[i] <= 'F')
            {
                decimal += num[i] - 'A' + 10;
            }
            else if (num[i] >= 'a' && num[i] <= 'f')
            {
                decimal += num[i] - 'a' + 10;
            }
            i++;
        }
    }
    else if (num[0] == '0' && num[1] == 'b')
    {
        i = 2;
        while (num[i] != '\0')
        {
            decimal *= 2;
            decimal += num[i] - '0';
            i++;
        }
    }
    else if (num[0] == '0')
    {
        i = 1;
        while (num[i] != '\0')
        {
            decimal *= 8;
            decimal += num[i] - '0';
            i++;
        }
    }
    else
    {
        i = 0;
        while (num[i] != '\0')
        {
            decimal = decimal * 10 + (num[i] - '0');
            i++;
        }
    }

    return decimal;
}

char *base_2(char *num)
{
    int decimal = base_10(num);
    char *result = (char *)malloc(65);

    if (decimal == 0)
    {
        result[0] = '0';
        result[1] = 'b';
        result[2] = '0';
        result[3] = '\0';
        return result;
    }

    // convertir decimal a binario
    int c = decimal;
    int r = c;
    int i = 2;
    result[0] = '0';
    result[1] = 'b';

    while (c > 0)
    {
        r = c % 2;
        c /= 2;
        result[i] = r + '0';
        i++;
    }
    result[i] = '\0';

    // invertir cadena
    int start = 2, end = i - 1;
    while (start < end)
    {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

char *base_8(char *num)
{
    char *result = (char *)malloc(65);
    int decimal = base_10(num);

    if (decimal == 0)
    {
        result[0] = '0';
        result[1] = '0';
        result[2] = '\0';
        return result;
    }

    // convertir decimal a octal
    int c = decimal;
    int r = c;
    int i = 1;

    while (c > 0)
    {
        r = c % 8;
        c /= 8;
        result[i++] = r + '0';
    }
    // i--;

    result[0] = '0';
    result[i] = '\0';

    // invertir cadena
    int start = 1, end = i - 1;
    while (start < end)
    {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

char *base_16(char *num)
{
    int decimal = base_10(num);
    char *result = (char *)malloc(65);

    if (decimal == 0)
    {
        result[0] = '0';
        result[1] = 'x';
        result[2] = '0';
        result[3] = '\0';
        return result;
    }

    // convertir decimal a hexadecimal
    int c = decimal;
    int r = c;
    int i = 2;
    result[0] = '0';
    result[1] = 'x';

    while (c > 0)
    {
        r = c % 16;
        c /= 16;
        if (r > 9)
        {
            result[i] = r + '7';
        }
        else
        {
            result[i] = r + '0';
        }
        i++;
    }
    result[i] = '\0';

    // invertir cadena
    int start = 2, end = i - 1;
    while (start < end)
    {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}