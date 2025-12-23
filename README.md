# priesegzamine-uzduotis
## Asociatyvių konteinerių taikymas (C++)
## Įvadas

Ši užduotis skirta patyrinėti, kodėl **asociatyvūs konteineriai** (pvz. `std::map`, `std::set`) yra labiau tinkami ir efektyvesni teksto analizės tipo užduotims nei sekos konteineriai (`std::vector`, `std::list`).  
Asociatyvūs konteineriai leidžia automatiškai **rūšiuoti elementus įrašymo metu**, greitai rasti reikiamą raktą ir patogiai kaupti papildomą informaciją (pvz., skaičių ar eilučių numerius).
## Užduoties formuluotė
Buvo atliktos trys pagrindinės užduotys:

1. **Žodžių pasikartojimų skaičiavimas**  
   - Iš pasirinkto teksto (ne trumpesnio nei 1000 žodžių) pašalinti skyrybos ženklai ir skaičiai.
   - Visi žodžiai normalizuoti (paversti mažosiomis raidėmis, palaikant lietuviškas raides).
   - Suskaičiuota, kiek kartų kiekvienas skirtingas žodis pasikartoja.
   - Į rezultatų failą išvesti tik tie žodžiai, kurie pasikartojo **daugiau nei vieną kartą**, kartu nurodant jų kiekį.
2. **Cross-reference (kryžminės nuorodos) lentelė**  
   - Kiekvienam daugiau nei vieną kartą pasikartojančiam žodžiui sudarytas eilučių numerių sąrašas.
   - Lentelėje pateikiama informacija, **kuriose teksto eilutėse** konkretus žodis buvo paminėtas.
3. **URL adresų paieška tekste**  
   - Tekste surasti visi URL adresai, pateikti:
     - pilna forma (`http://...`)
     - sutrumpinta forma (`www.vu.lt`, `vu.lt`, `saitas.xyz`)
   - Rasti URL’ai tvarkingai išvesti ekrane arba į failą.
  
Programa sugeneruoja šiuos failus:

- kiekis.txt
Žodis ir jo pasikartojimų skaičius (tik > 1)

- eil.txt
Žodis ir eilučių numeriai, kuriose jis pasirodė

- url_info.txt
Rasti URL adresai 
## Naudotas tekstas
   

Analizei buvo pasirinktas Vikipedijos straipsnis **„Pilkasis vilkas (Canis lupus)“**.  
Tai didelės apimties informacinis tekstas apie pilkąjį vilką, apimantis:
- biologinę klasifikaciją,
- paplitimą,
- išvaizdą,
- elgseną,
- santykį su žmogumi,
- mitologiją,
- porūšius,
- situaciją Lietuvoje,
- istorinius ir kultūrinius aspektus.
  Tekstas puikiai tiko užduočiai, nes jame:
- gausu pasikartojančių terminų (pvz., *vilkas*, *vilkai*, *vilkų*),
- vartojami sudėtiniai žodžiai ir moksliniai pavadinimai,
- pateikti URL adresai šaltiniuose ir nuorodose.
## Įgyvendinimas

### Žodžių apdorojimas
- Žodžiai buvo valomi nuo skyrybos ženklų.
- Skaičiai pašalinti.
- Lietuviškos raidės (`ą, č, ė, į, š, ų, ū, ž`) korektiškai paverstos į mažąsias naudojant `lt_LT.UTF-8` lokalę.
### Duomenų struktūros
- `std::map<string, int>` – žodžių pasikartojimų skaičiavimui.
- `std::map<string, std::set<int>>` – kryžminių nuorodų (eilučių numerių) saugojimui.
- Asociatyvūs konteineriai užtikrino:
  - automatinį žodžių rikiavimą,
  - greitą paiešką,
  - aiškią ir tvarkingą išvestį.
 Pavyzdžiui, žodžiai Indijos ir Individų kartojosi šiose eilutėse po du kartus:
<img width="317" height="43" alt="image" src="https://github.com/user-attachments/assets/c7b10469-395b-48bc-a674-ca7bc428c460" />
<img width="261" height="43" alt="image" src="https://github.com/user-attachments/assets/09bad46f-ebdb-481f-9f1d-792da8339b03" />
<img width="679" height="46" alt="image" src="https://github.com/user-attachments/assets/b8e887fe-7cdf-4edc-a746-90e9d58fcd77" />
<img width="1472" height="166" alt="image" src="https://github.com/user-attachments/assets/575cbc18-6d27-46ce-ab21-a54ae91ab078" />


Reikia nepamiršti paminėti, kad žmogus gali atsidaryti input/output failus ir pasižiūrėti gautus rezultatus, ar atsiuntęs kartu su .cpp ir.h, run.bat bei CMakeLists.txt ir į vieną Debug folderį įdėjęs ir tekstas.txt, paprašius "Iveskite failo pavadinima:" gaus analogiškus rezultatus. Tą patį galima padaryti ir su kitais tekstais, kurie yra .txt formato. 

Be to, žodžių trumpiniai, tokie kaip "ide","d" taip pat laikomi kaip vartojami žodžiai, nes yra trumpiniai, svarbu to nepamiršti.

## Įdiegimo instrukcija
# CMake įdiegimas Windows naudojant `.msi` paketą

Prieš pradedant 

Atsisiųsti CMakeLists.txt, run.bat, .cpp ir .h failus iš GitHub.

Kompiuteryje sukurti aplanką pavadintą "cmaketest". Į jį įkelti CMakeLists.txt, run.bat failus.

"cmaketest" aplanke sukurti du aplankus: "src", "include". Į "src" aplanką įkelti .cpp failus, o į "include" - .h failus.

## 1. Atsisiuntimas
1. Eikite į oficialų CMake puslapį: [https://cmake.org/download/](https://cmake.org/download/)
2. Pasirinkite **Windows x64 Installer (.msi)** versiją.
   - Pavyzdys: `cmake-3.25.0-windows-x86_64.msi`

## 2. Diegimas
1. Paleiskite atsisiųstą `.msi` failą.
2. Spauskite **Next** visuose langeliuose.
3. Svarbu: pasirinkite **"Add CMake to the system PATH for all users"** arba **"for current user"**.  
   - Tai leis naudoti `cmake` komandą bet kuriame terminale.

## 3. Baigimas
1. Spauskite **Finish**, kai diegimas baigtas.
2. Atidarykite naują **PowerShell** langą.
3. Patikrinkite diegimą įvedę:
   ```powershell
   cmake --version

# CMake projekto paleidimas Windows PowerShell ir naudojimo instrukcija
---

## 1. Atidarykite PowerShell

- Atidarykite **Windows PowerShell**.
2. **Eikite į savo projekto katalogą, pavyzdžiui:**
- cd C:\Users\aiste\Desktop\cmaketest
- 
3. **Paleiskite CMake projektą:**

cmake .\CMakeLists.txt

4. **Sukurkite projektą:**

cmake --build .

5. **Pereikite į Debug katalogą:**

cd Debug

6. **Paleiskite programą:**

.\failo_rusiavimo_programa.exe

7. **Terminale matysite programos meniu:**
Iveskite failo pavadinima:

Įvedus failo pavadinimą, matome, kad galime pasirinkti, ar URL rašomas į terminalą, ar į failus, o eilutės ir žodžių pasikartojimo skaičius išvedamas į du atskirus failus – eil.txt ir kiekis.txt
<img width="1382" height="352" alt="image" src="https://github.com/user-attachments/assets/5200d981-9b4f-48f0-9b0c-a4d91ee2e9cf" />





