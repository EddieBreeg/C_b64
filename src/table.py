b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

t = [255 for i in range(128)]
for i in range(64):
    c = ord(b64[i])
    t[c] = i

print(t)