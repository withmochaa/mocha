import random

answer=random.randint(1,20)
count=0;
for i in range(4,0,-1):
    num=int(input("기회가 %d번 남았습니다. 1-20 사이의 숫자를 맞혀 보세요 :"%(i)))
    count+=1
    if num<answer:
        print("UP")
    elif num>answer:
        print("Down")
    elif num==answer:
        print("축하합니다. %d번만에 숫자를 맞히셨습니다."%(count))
    
    
if count==4:
    print("아쉽습니다. 정답은 %d였습니다."%(answer))
    
    
    
    
import random

# 상수 정의
ANSWER = random.randint(1, 20)
NUM_TRIES = 4

# 변수 정의
guess = -1
tries = 0

while guess != ANSWER and tries < NUM_TRIES:
    guess = int(input("기회가 {}번 남았습니다. 1-20 사이의 숫자를 맞혀 보세요: ".format(NUM_TRIES - tries)))
    tries += 1    
    
    if ANSWER > guess:
        print("Up")
    elif ANSWER < guess:
        print("Down")

if guess == ANSWER:
    print("축하합니다. {}번 만에 숫자를 맞히셨습니다.".format(tries))
else:
    print("아쉽습니다. 정답은 {}입니다.".format(ANSWER))
