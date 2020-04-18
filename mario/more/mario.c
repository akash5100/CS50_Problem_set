#include <stdio.h>
 int main()
 {
    int height=0;

    do
    {
        printf("height: ");
        scanf("%i",&height);
    }while (height<1 || height > 8);
    

    for(int i=0 ; i < height ; i++)
    {
        for(int j=0 ; j < height; j++)
        {
            if(j < height-i-1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }  
        printf("  ");
        for(int j=0; j<=i ;j++) 
        {
            printf("#");
        }  
         printf("\n");
    }
 }