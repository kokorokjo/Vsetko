# Pravidlá

Každý hráč má jeden tank, ktorý ovláda.
Hrá sa po ťahoch a v každom ťahu sa každý hráč pohne,
vystrelí a možno si môže vylepšiť tank alebo nejaké svoje `staty`.
Tanky sa pohybujú po ploche, na ktorej sa okrem iných hráčov nachádzajú
ešte tzv. `entity` (také guličky). Tieto entity sa v priebehu hry generujú.
Ostatní hráči ani entity netvoria prekážku, cez ktorú by sa nedalo prechádzať.
Avšak, prechádzanie cez entity uberá život obom veciam, ktoré sa prekrývajú.

## Zopár technickejších detailov

Hra sa _nehrá_ na mriežke, ale hrá sa na reálnych súradniciach.

### Pohyb

Pohyb funguje tak, že pošlete súradnice, na ktoré by ste sa chceli pohnúť.
V prípade, že pošlete súradnice ďalej ako sa môžete hýbať, tak server váš ťah preškáluje.
(Je to v zásade zámer, takže nemusíte preškálovávať svoj ťah,
proste len poviete súradnice, kam sa chcete dostať, a tank sa pohne tým smerom.)

### Strieľanie

Strely existujú 3 druhov a podľa toho sa aj obsluhujú a správajú:

1. Smerové strely. Jednoducho letia nejakým smerom, až kým im nevyprší TTL.
2. Strela navádzaná na hráča. Strela letí za hráčom.
   Ak hráč v ľubovoľnom momente zomrie, tak pokračuje v smere ako letela naposledy.
3. Strela navádzaná na súradnice. Strela letí na súradnice a keď tam príde,
   tak až kým jej nevyprší TTL, tak tam ostane.

## Oživovanie a život

Každý hráč má nejaké množstvo života. Pokiaľ nemá maximálne množstvo života,
tak sa mu každé kolo pridá trochu života (regeneruje sa).
Každý hráč má 3 respawny. Hráč zomrie, ak má menej ako 0 ostávajúcich respawnov.
Život sa hráčovi uberá:

- ak sa zrazí s guľkou
- ak sa zrazí s iným hráčom
- ak sa zrazí s entitou
- ak vyjde mimo mapy

Hráč potom, ako zomrie, sa znovu oživi (ak má ešte nejaký ostávajúci respawn),
má maximálny život a má BasicTank. Má tiež polovicu levelov a všetky TankUpdaty.

## `Exp` a bodovanie

Počas hry získavaš `Exp`. Získavaš ich ak:

- znížiš život hráča, či už guľkou, alebo tak, že sa s ním zrazíš
- zabiješ hráča alebo entitu

Potom, čo získaš nejaký počet `Exp`, budeš mať možnosť si zväčšiť nejaký Stat (zväčší sa ti level).
Každých 10 levelov dostaneš možnosť si vylepšiť tank.

Výsledné skóre sa sčítava z dvoch vecí:
- počet `Exp`, ktoré v priebehu hry získate
- poradia v ktorom ste zomreli (posledný krát). Čím neskôr zomriete, tým viac bodov získate.

## Stats

Každý hráč má svoje `stats`, ktoré sa skladajú zo `stats` samotného hráča a `stats` tanku.

Stats sú takéto:

| názov              | význam                                                           |
| ------------------ | ---------------------------------------------------------------- |
| Range              | ako ďaleko dovidíš (na entity, hráčov alebo guľky)               |
| Speed              | ako rýchlo sa tvoj tank vie hýbať                                |
| BulletSpeed        | ako rýchlo letia tvoje guľky                                     |
| BulletTTL          | ako ďaleko tvoja guľka doletí                                    |
| BulletDamage       | aký damage spôsobia tvoje guľky                                  |
| HealthMax          | najviac koľko života môže mať tvoj tank                          |
| HealthRegeneration | ako rýchlo sa ti obnovuje život                                  |
| BodyDamage         | aký damage spôsobíš súperovi/entite, keď sa prekrývate (zrazíte) |
| ReloadSpeed        | po akom čase môžeš opäť vystreliť                                |

## Tanky

Existuje zopár (12) druhov tankov:

| id | názov               | popis                                        | môžeš vylepšiť na tank |
| -- | ------------------- | -------------------------------------------- | ---------------------- |
|  0 | BasicTank           | základný tank                                | 1,5,9                  |
|  1 | TwinTank            | tank s dvomi hlavňami                        | 2,3,4                  |
|  2 | EverywhereTank      | tank s hlavňami do 8 smerov                  | -                      |
|  3 | VariableDoubleTank  | tank s dvomi nezávislými hlavňami            | -                      |
|  4 | DoubleDoubleTank    | tank s dvomi hlavňami dopredu a dvomi dozadu | -                      |
|  5 | SniperTank          | tank s dlhým dostrelom                       | 6,7,8                  |
|  6 | WideBulletTank      | tank so širokými guľkami                     | -                      |
|  7 | GuidedBulletTank    | tank s navádzanými strelami                  | -                      |
|  8 | MachineGunTank      | tank s malým cooldownom                      | -                      |
|  9 | AsymetricTank       | tank s veľkou hlavňou dopredu a malou dozadu | 10,11,12               |
| 10 | PeacefulTank        | tank, ktorý nevie strieľať                   | -                      |
| 11 | InvisibleBulletTank | tank, ktorý strieľa neviditeľné strely       | -                      |
| 12 | AsymetricTripleTank | tank s dvomi malými hlavňami dozadu          | -                      |
