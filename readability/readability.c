#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXLEN 2001

int letters(char text[]);
int sentence(char text[]);
int inde(char text[],int L ,int S, int w);
int word(char text[]);

int main()
{
    int W=0,L=0,S=0;
    int index=0;
    char text[MAXLEN];
    printf("Text: ");
    gets(text);


    L=letters(text);
    S=sentence(text); 
    W=word(text);

    inde(text,L,S,W);
    return 0;

}

int letters(char text[])
{
    int counter=0 ;
    for(int i=0 ; text[i]!= '\0'; i++)
    {
       /* if(text[i]!= 32 && text[i]!= '!' && text[i]!= '.' && text[i]!= '?')
        {
            counter++;
        } */
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            counter++;
        }
    }
    
    return counter;
}

int sentence(char text[])
{
    int counter=0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]=='!' || text[i] =='?' || text[i]== '.' )
        counter++;
    }
    return counter;
    
}

int word(char text[])
{
    int counter=1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==32 )
        counter++;
    }
    return counter;
    
}

int inde(char text[],int L,int S,int W)
{
    double index = 0.0588 * (100 * (float)L / (float)W) - 0.296 * (100 * (float)S/(float)W ) - 15.8;
    //     index = 0.0588 * (-------------L-----------) - 0.296 * (-------------S----------) - 15.8
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
    return 0;
}

