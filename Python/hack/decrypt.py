import os
from cryptography.fernet import Fernet

files = []

for file in os.listdir():
    if file.endswith('.txt'):
        files.append(file)

print(files)

with open('key.key', 'rb') as key_file:
    key = key_file.read()


for file in files:
    with open(file, 'rb') as f:
        data = f.read()

    dencrypted = Fernet(key).decrypt(data)

    with open(file, 'wb') as f:
        f.write(dencrypted)