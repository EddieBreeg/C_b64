from sys import argv
from base64 import b64encode

with open("data", 'rb') as fIn:
    b = fIn.read()
    print(b64encode(b).decode())