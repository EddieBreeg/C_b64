from random import randrange as rand
from sys import argv

with open("data", "wb") as file:
    b = bytes([rand(256) for i in range(int(argv[1]))])
    file.write(b)