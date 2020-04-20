while(True):
    height = int(input("Enter: "))
    if(height > 0 and height < 9):
        break

blank = int(height)

for i in range(height):
    #print(" ",end="")

    for j in range(blank-1):
        print(" ",end="")
    blank-=1

    for j in range(i+1):
        print("#",end="")
    print()     
