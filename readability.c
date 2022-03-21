#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // ingresar el texto//
    string texto = get_string("ingrese el texto: ");


    //contar la cantidad de letras q hay en el texto//
    int letras = 0;
    for (int i = 0; i < strlen(texto); i++)
    {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z'))
        {
            letras++;
        }
    }


    //Contar el numero de palabras de la oracion//

    int palabras = 1;
    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == ' ')
        {
            palabras++;
        }
    }


    //Contar el numero de oraciones//

    int oraciones = 0;
    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == '!' || texto[i] == '?' || texto[i] == '.')
        {
            oraciones++;
        }
    }


    //Usar el indice del Coleman-Liau para determinar el grado de lectura//

    float calcular = (0.0588 * letras / palabras * 100) - (0.296 * oraciones / palabras * 100) - 15.8;
    int indice = round(calcular);

    if (indice < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (indice >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", indice);
    }
}