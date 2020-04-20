
while(True):

    height = int(input("Height: "))
    if( height > 0 and height < 9 ):
        break

for i in range(height):

    for j in range(height):
        if(j < height-i-1):
            print(" ",end="")
        else:
            print("#",end="")
        
    print("  ",end="")
    for j in range(i+1): 
        print("#",end="")
      
    print("")

