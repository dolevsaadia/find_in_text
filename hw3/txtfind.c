#include <stdio.h>
#include <stdlib.h>
#include "txtfind.h"

int getline1(char s[line])
{
    fgets(s, line, stdin);
    int i = 0;
    int numword = 0;
    int count = 0;
    while (s[i] != '\n')
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        {
            numword++;
            i++;
            count++;
        }
        else
        {
            i++;
            count++;
        }
    }

    return count;
}
int getword(char w[])
{
    int countletters = 0;

    fscanf(stdin, "%s", w);
    while (*(w + countletters) != NULL)
    {
        countletters++;
    }

    return countletters;
}
int substring(char *str1, char *str2)
{
    int counter = 0;
    while (*(str2 + counter) != NULL)
    {
        counter++;
    }
    int i = 0;
    int j = 0;
    int flag = 0;
    while (*(str1 + i) != '\n')
    {

        if (*(str1 + i) == *(str2 + j))
        {
            i++;
            j++;
        }
        else
        {
            if (*(str2 + j) == '\0' || (*(str2 + j) == ' ') || *(str2 + j) == '\n')
            {
                if (*(str2 + j) == ' ')
                {
                    j++;
                }
                else
                {
                    flag = 1;
                    return flag;
                }
            }
            else
            {
                j = 0;
                i++;
            }
        }
    }

    if (counter == j)
    {
        flag = 1;
    }

    return flag;
}

int similar(char *s, char *t, int n)
{
    int counter = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    while (*(s + j) != '\0')
    {
        if (*(t + i) == *(s + j))
        {
            i++;
            j++;
        }
        else
        {
            counter++;

            j++;
        }
    }
    if (n == counter)
    {
        flag = 1;
    }

    return flag;
}
void print_line(char *str)
{
    char *s[line];
   
    while (fgets(s, line, stdin) != NULL)
    {
        if (substring(s, str) == 1)
        {
            printf("\n%s", s);
        }
    }
}
void print_simillar_words(char *str)
{
    char *w[word];
    int i = 0;
    while (fscanf(stdin, "%s", w) != EOF)
    {

        int size = getword(w);
        if (size > 1 && similar(w, str, 1) == 1)
        {
            printf("\n%s", &w);
        }
        else
        {
            if (similar(w, str, 0) == 1)
            {
                printf("\n%s", &w);
            }
        }
    }
}
