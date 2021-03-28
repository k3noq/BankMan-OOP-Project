# Grupa19
Zubić Adi, Genjac Kenan, Jamaković Emrah

<i>Managment sistem za banku</i> - <b>BankMan</b>

Konzolna aplikacija koja simulira osnovne i proširene djelatnosti poslovanja banke.

Postoje 3 moda pristupa:
  1. Superuser (sudo)
  2. Admin (uposlenik)
  3. Korisnik;

-----------
<b>1. Korisnik</b>
- 
  Korisnik mod ima meni sa opcijama za korištenje usluga banke, kao što su
  uplaćivanje na račun, isplata sa računa, provjera stanja, pregled izvršenih
  naloga, itd.
  Pri prijavi korisnika se provjerava da li taj korisnik postoji u bazi banke, tačnije
  da li je kreiran i spašen kao korisnik.

<b>2. Admin</b>
-
  Admin mod otvara meni sa opcijama za uposlenika gdje uposlenik može
  birati između nekih privilegovanih opcija koje se tiču korisnika, kao što su
  kreiranje korisnika (korisnik ne može koristiti usluge banke ako nije
  registrovan), brisanje korisnika i dr.

<b>3. SuperUser</b>
-
  SuperUser mod koji nudi meni za upravljanje uposlenicima banke. Tačnije, to
  je mod koji koristi šef/direktor za upravljanje operacijama u banci. On može
  zapošljavati radnike, otpuštati radnike, pregledavati izvještaje i dr. opcije koje
  se nude nadređenima. 

-----------

<b>Dodatni fajlovi:</b> 

<b>1. users.txt</b>: sadrži informacije o korisnicima. Prilikom prijavljivanja korisnika u sistem se isti verifikuje pomoću broja računa i enkriptovane šifre koja se nalazi na kraju informacija o svakom korisniku. U ovaj fajl se također zapisuju informacije o novounesenom korisniku, a ukoliko se korisnik obriše, brišu se i njegove informacije iz users.txt fajla. Format zapisa u fajlu users.txt je sljedeći:

    JMBG Ime Prezime Godine Spol StudentIliNe BrKartice CVVBroj DatumIsteka MjesecnaNaplata BrRacuna StanjeRacuna LimitRacuna DaLiJeOtvoren EnkriptovanaŠifra
                
<b>2. employees.txt</b>: sadrži informacije o usposlenicima. Prilikom prijavljivanja radnika u sistem se isti verifikuje pomoću ID-a radnika i enkriptovane šifre koja se nalazi na kraju informacija o svakom radniku. U ovaj fajl se također zapisuju informacije o novounesenom radniku, a ukoliko se radnik obriše, brišu se i njegove informacije iz employees.txt fajla. Format zapisa u fajlu emplyoees.txt je sljedeći: 

    JMBG Ime Prezime Godine Spol IDRadnika Obrazovanje Pozicija SedmicnoRadnihSati KoeficijentPozicije Plata DatumZaposlenja DatumIstekaUgovora Adresa BrMobitela EnkriptovanaŠifra
      
<b>3. bossPassword.txt</b>: sadrži enkriptovanu šifru koja se provjerava prilikom verifikacije kod prijave direktora u sistem.

<b>4. logs.txt</b>: sadrži informacije o korisniku i vremenu prijave korisnika na sistem.

-----------
<b>Login podaci:</b>

	1. Korisnik:
  
              Korisnik 1 - Br. računa: 123456
              	     - Password: adi1234

              Korisnik 2 - Br. računa: 642345
              	     - Password: kenan1

              Korisnik 3 - Br. računa: 456723
              	     - Password: emrah33


    2. Radnik:
 
              Radnik 1 - ID: 11
              	   - Password: 123pass

              Radnik 2 - ID: 12
                       - Password: emp123

              Radnik 3 - ID: 13
                       - Password: kenks45


    3. Direktor:  	
              
              Password: 123boss
              
-----------
