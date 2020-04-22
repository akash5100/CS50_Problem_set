
def main():
    w=0
    l=0
    s=0
    index=0
    text = input("Text: ")

    l=letters(text)
    s=sentence(text)
    w=word(text)

    grade(text,l,s,w)

    return 0

def letters(text):
    counter=0
    for i in text:
        if ((int(ord(i)) >= 65 and int(ord(i)) <= 90) or (int(ord(i)) >= 97 and int(ord(i)) <= 122)):
            counter+=1
    return counter


def sentence(text):
    counter =0
    for i in text:
        if int(ord(i)) == 33 or int(ord(i)) == 63 or int(ord(i)) == 46:
            counter+=1
    return counter   

def word(text):
    counter=1
    for i in text:
        if int(ord(i)) == 32:
            counter+=1
    return counter

def grade(text,L,S,W):
    index = 0.0588 * (100 * float(L) / float(W)) - 0.296 * (100 * float(S)/float(W) ) - 15.8   

    if index <16 and index>=0:
        print(f"grade {round(index)}")

    elif index >= 16:
        print("grade 16+ ")

    else:
        print("Before Grade 1")

    
main()