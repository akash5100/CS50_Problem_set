#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{   
    if (argc < 2)
    {
        printf("Usage: ./recover [FILE...]\n");
        exit(1);
    }
    
    // open file 
    FILE *file=fopen(argv[1],"r");
    if (file==NULL)
    {
        fprintf(stderr,"file not found!\n");
    }
    
    FILE *img = NULL;
    BYTE buffer[512];
    char filename[8];
    int counter = 0;
    bool flag = false;

        
        while( fread(buffer, 512, 1, file) == true )
        {
            if( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0 )
            {
                if (flag == true)
                {
                    fclose(img);
                }
                else
                {
                    flag = true;
                }
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                counter++;

            }
            if(flag == true)
            {
                fwrite(buffer,512,1,img);
            }
            
        }
            //if next header then close the previous and start reading new

    fclose(file);
    fclose(img);
    
    return 0;

}


        