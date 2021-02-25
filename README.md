# C b64

A tiny C lib that allows you to use base64 encoding and decoding.

## Functions

```C
void encode(const byte* src, byte* dst, unsigned int length)
```
Encodes a block 3 (or less) bytes from `src`, and writes
the base64 encoded data in `dst`. If `length` > 3, the function
will only encode 3 bytes of data

```C
int decode(const byte* src, byte* dst)
```
Reads a 4-character long base64 encoded string `src`, and writes the
decoded bytes in `dst`.