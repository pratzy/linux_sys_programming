# /!usr/bin/python3

import codecs
from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.bind(('', 1068))
s.listen(5)
print("Listening...")


def rot13_service(client):
    while True:
        in_bytes = client.recv(1024)
        if in_bytes:
            out_bytes = codecs.encode(in_bytes.decode(), 'rot_13').encode()
            client.send(out_bytes)
        else:
            break


while True:
    client, addr = s.accept()
    print("Connected")
    rot13_service(client)
    client.close()
