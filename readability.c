#include <cs50.h>
#include <stdio.h>
#include <string.h> //necessary to include lenght of the string
#include <math.h> //necessary to include round() function

int count_letters(string text); //Function Declarations
int count_words(string text);
int count_frases(string text);

int main(void)
{
    string text = get_string("Text: "); //Prompting the user for text
    int letters = count_letters(text); //Calling the functions
    int palabras = count_words(text);
    int sentences = count_frases(text);
    //printf("%i", letters); //Print statements used for checking
    //printf(" letter(s)\n");
    //printf("%i", palabras);
    //printf(" word(s)\n");
    //printf("%i", sentences);
    //printf(" sentence(s)\n");

    double L = (round)(100 * letters) / palabras; //Calculation of grade.
    double S = (round)(100 * sentences) / palabras;
    int Grade = (round)((0.0588 * L) - (0.296 * S) - 15.8);

    if (Grade >= 16) //Conditionals for printing grade.
    {
        printf("Grade 16+\n");
    }
    else if (Grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", Grade);
    }



}

int count_letters(string text) //Function for counting letters
{
    int numberOfLetters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (((text[i] >= 'a' || text[i] >= 'A') && (text[i] <= 'z' || text[i] <= 'Z')) || (text[i] == '-'))
        {
            numberOfLetters++;
        }
    }
    return numberOfLetters;
}

int count_simbols(string text) //Function used to calculate the number of words
{
    int numberOfSimbols = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '"' || text[i] == '\'' || text[i] == ',' || text[i] == ';' || text[i] == ':' || text[i] == '.' || text[i] == '?'
            || text[i] == '!')
        {
            numberOfSimbols++;
        }
    }
    return numberOfSimbols;
}

int count_words(string text) //Function used for counting words
{
    int spaces = strlen(text) - count_letters(text);
    int palabras = spaces + 1 - count_simbols(text);
    return palabras;
}

int count_frases(string text) //Function used for counting sentences
{
    int numberOfFrases = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numberOfFrases++;
        }
    }
    return numberOfFrases;
}



