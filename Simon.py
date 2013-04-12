from random import *
import os 

# Random number from 1 to 4
def rand():
    return int(4*random() + 1)

# Game round with starting sequence
def gameRound(seq):
    seq.append(rand())

    print "Simon says: ", seq

    for i in seq:
        i = str(i)
        trial = raw_input(">")
        if trial != i:
            return "You lost! Score: " + str(len(seq) - 1)

    return gameRound(seq)

# Loop
while (1):
    print gameRound([])
