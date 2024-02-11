def encode(n: int, plain_text: str) -> str:     # vraci ciphertext typu String

    

    

def decode(n: int, cipher_text: str) -> str:    # vraci plaintext typu String
    pass

# Testy:
print(encode(3, "Ahoj"))    # ohAj
print(encode(2, "Ahoj"))    # hAjo
print(encode(10, "Ahoj"))   # johA
print(encode(3, "12345"))   # 32154
print(encode(5, "komunikace"))  # numokecaki
print(decode(2, "hAjo"))    # Ahoj
print(decode(5, "rgorpavomain"))    # programovani
print(decode(3, encode(3, "Karlik a Los Karlos komunikuji sifrovane"))) # Karlik a Los Karlos komunikuji sifrovane

# na automaticke testy doporucuji assert

