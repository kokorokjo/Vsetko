def encode(n: int, plain_text: str) -> str:     # vraci ciphertext typu String
    k=0
    z=0
    vysledok=""
    nieco=False
    while nieco==False:
        k+=n
        if k>=len(plain_text):
            k=len(plain_text)
            nieco =True
        daco=plain_text[z:k]
        z=k
        string = list(daco)
        string.reverse()
        vysledok+="".join(string)
    return vysledok
    
    

def decode(n: int, cipher_text: str) -> str:    # vraci plaintext typu String
    k=0
    z=0
    vysledok=""
    nieco=False
    while nieco==False:
        k+=n
        if k>=len(cipher_text):
            k=len(cipher_text)
            nieco =True
        daco=cipher_text[z:k]
        z=k
        string = list(daco)
        string.reverse()
        vysledok+="".join(string)
    return vysledok

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

