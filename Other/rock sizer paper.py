n=int(input())
Win=0
Draw=0
Lose=0
A=input()
for i in range(n):
    B=input()
    if A=='S' or A=='s':
        if B=='S' or B=='s':
            Draw=Draw+1
        elif B=='R' or B=='r':
            Lose=Lose+1     
        else:
            Win+=1
    elif A=='p' or A=='P':
        if B=='S' or B=='s':
            Lose=Lose+1
        elif B=='p' or B=='B':
            Draw=Draw+1
        else:
            Win=Win+1
    else:# A=R
        if B=='S' or B=='s':
            Win=Win+1
        elif B=='p' or B=='P':
            Lose=Lose+1
        else:
            Draw=Draw+1
            
print("Win:",Win)
print("Draw:",Draw)
print("Lose:",Lose)             