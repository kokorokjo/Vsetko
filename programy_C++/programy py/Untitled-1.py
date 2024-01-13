import csv
pokracovanie ="a"
uroven = 1
skore = 1000
with open ('ABCD.csv') as csv_file:
    csv_reader = csv.DictReader(csv_file)
    for row in csv_reader:
           while pokracovanie == 'a':
                otazka=row[OTAZKA]
                odpoveda=row[ODPOVEDA]
                odpovedb=row[ODPOVEDB]
                odpovedc=row[ODPOVEDC]
                odpovedd=row[ODPOVEDD]
                spravnaodpoved=[SPRAVNAODPOVED]
                print("Uroven:", uroven)
                uroven = uroven+1
                print(otazka)
                print(odpovede)
                odpoved = input()
                if odpoved != spravnaodpoved:
                    break
                skore = skore *2
                if uroven ==15:
                    break
                print("Chcete pokracovat?")
                pokracovanie = input()
                if pokracovanie == n:
                   break
if odpoved != spravnaodpoved: #vyhra checkpoint penazi ak je nespravna odpoved
    if uroven >5:
        skore = 0
    elif uroven >10:
        skore = 16000
    elif uroven >15:
        skore = 1024000
print("Vase skore je :", skore)