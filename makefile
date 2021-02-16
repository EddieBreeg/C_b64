SRC=src/b64.c

output: $(SRC) b64Encode.c b64Decode.c
	gcc $(SRC) b64Encode.c -o b64Encode -Wall
	gcc $(SRC) b64Decode.c -o b64Decode -Wall