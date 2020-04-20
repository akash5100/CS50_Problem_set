#include <stdio.h>
#include <math.h>
int main()
{
    float dollar;
    const int quarter = 25;
    const int dime = 10;
    const int nickel = 5;
    const int penny = 1;
    int counter=0;
    int cent;
    do
    {
        printf("Enter: ");
        scanf("%f",&dollar);
    } while (dollar < 0);
    cent=round(dollar*100);
    
    while(cent >= quarter)
    {
        cent-=quarter;
        counter++;
    }
    while(cent >= dime)
    {
        cent-=dime;
        counter++;
    }
    while(cent >= nickel)
    {
        cent-=nickel;
        counter++;
    }
    while(cent >= penny)
    {
        cent-=penny;
        counter++;
    }
    printf("%i\n",counter);

return 0;
}