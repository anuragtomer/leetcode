import random

for i in range(3):
    line = random.choice(open('questions.txt', 'r').readlines())
    print(line)

