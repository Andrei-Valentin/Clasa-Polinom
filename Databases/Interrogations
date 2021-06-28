--Afisarea informatiilor hotelului cu adresa completa
SELECT h.nume "Nume Hotel",h.nr_stele "Numar stele",ad.nume_strada "Nume Strada", ad.oras "Oras", NVL(ad.judet,'-') "Judet", ad.tara "Tara"
FROM hotel_ava h JOIN adresa_ava ad ON (h.id_adresa = ad.id_adresa)
ORDER BY ad.oras DESC;

--Afisarea hotelelor din Constanta in ordine descrescatoarea a numarului de stele
SELECT h.nume "Nume Hotel",h.nr_stele "Numar stele"
FROM hotel_ava h JOIN adresa_ava ad ON (h.id_adresa=ad.id_adresa)
WHERE ad.oras='Constanta'
ORDER BY "Numar stele" DESC;

--Afisarea angajatilor al calor nume incepe cu litera "D"
SELECT personal_ava.nume "Nume angajat",personal_ava.prenume "Prenume"
FROM personal_ava
WHERE personal_ava.nume LIKE ('D%');

--Afisarea clientilor care se cazeaza in luna in care s-au nascut
SELECT cl.nume,cl.prenume
FROM client_ava cl JOIN cazare_ava cz ON (cl.id_client = cz.id_client)
WHERE TO_CHAR(cl.data_nasterii,'MM')=TO_CHAR(cz.data_sosire,'MM');

--Afisarea salariului maxim pentru fiecare hotel
SELECT personal_ava.id_hotel, MAX(personal_ava.salariu) AS "Salariu Maxim"
FROM personal_ava
GROUP BY personal_ava.id_hotel;

--Afisarea totalului platit ca salariu catre toti angajatii lantului hotelier
SELECT SUM( personal_ava.salariu ) "Total salarii platite"
FROM personal_ava;

--Afisarea hotelurilor din Brasov care au mai mult de 3 stele
SELECT h.nume "Nume Hotel",h.nr_stele "Numar stele"
FROM hotel_ava h JOIN adresa_ava ad ON (h.id_adresa=ad.id_adresa)
WHERE ad.oras='Brasov' AND h.nr_stele > 3
ORDER BY "Numar stele" DESC;

