#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define maxlen 2662

int main(int argc, char *argv[])
{
    char* key;
    //get key 
    if(argc > 2 || argc == 1)
    {
        printf("Usage: ./substitution (KEY single command-line) \n");
        return 1;
    } 
    else 
    {
        //got key 
        key = argv[1]; 
    }   
    

        //validate key 

        //step 1- check length
        if(strlen(key) != 26)
        {
            printf("the key should have 26 character\n");
            return 1;
        }
        // step 2- check non-alphabetic characters
        else  
        {
            for (int i = 0; key[i]!= '\0' ; i++)
            {
                if(key[i] >=65 && key[i] <=90 || key[i]>=97 && key[i]<=122)
                continue;

                else
                {
                    printf("key must not contain non-alphabetic character\n");
                    return 1;
                }
            
            }
        
        }
        //step 3- check repeated character
         
        {
            char counter='\0';
            for (int i = 0; key[i]!= '\0'; i++)
            {
                counter = key[i];
                for (int j = i+1; key[j]!= '\0'; j++)
                {
                    if((int)key[j] == (int)counter)
                    {
                        printf("repetition of character not allowed in key\n");
                        return 1;
                    }

                }
                
            }
            
        } //key generated successfully
    
    //get plain text from user
    char plain_text[maxlen];
    printf("Plain-text: ");
    fgets(plain_text,maxlen,stdin);
    

    //cipher 
    char cipher[maxlen];
    int j=0;
        //encrypt
        for ( int i = 0; plain_text[i] != '\0' ; i++)
        {
            if(plain_text[i]>= 65 && plain_text[i]<= 90 ) //if character is in uppercase
            {
                j = ((int)plain_text[i] - 65) ;
                cipher[i]=toupper(key[j]);
            }

            if(plain_text[i]>=97 && plain_text[i]<=122 ) //if character is in lowercase
            {
                j = ((int)plain_text[i] - 97) ;
                cipher[i]=tolower(key[j]); 
            }

            if(plain_text[i]>=32 && plain_text[i]<= 64)// if character is punctuation
            {
                cipher[i] = plain_text[i];
            }

        }
    printf("ciphertext: ");           
    puts(cipher);

}
