CREATE TABLE Adresa_AVA (
  id_adresa number(10) CONSTRAINT id_adresa_PK_AVA PRIMARY KEY,
  nume_strada varchar2(50 CHAR),
  oras varchar2(50 CHAR),
  judet varchar2(50 CHAR),
  tara varchar2(50 CHAR)
);


CREATE TABLE Hotel_AVA (
  id_hotel number(10) CONSTRAINT id_hotel_PK_AVA PRIMARY KEY,
  id_adresa number(10),
  nume varchar2(50 CHAR) CONSTRAINT nume_hotel_not_null NOT NULL,
  nr_stele number(10),
  CONSTRAINT id_adresa_FK_AVA FOREIGN KEY(id_adresa) REFERENCES Adresa_AVA(id_adresa)
);


CREATE TABLE Camera_AVA (
  id_camera number(10) CONSTRAINT id_camera_PK_AVA PRIMARY KEY,
  id_hotel number(10),
  numar_camera number(10) CONSTRAINT numar_camera_not_null NOT NULL,
  CONSTRAINT id_hotel_FK_AVA FOREIGN KEY (id_hotel) REFERENCES Hotel_AVA(id_hotel)
);


CREATE TABLE Client_AVA (
  id_client number(10) CONSTRAINT id_client_PK_AVA PRIMARY KEY,
  nume varchar2(50 CHAR) CONSTRAINT nume_client_not_null NOT NULL,
  prenume varchar2(50 CHAR) CONSTRAINT prenume_client_not_null NOT NULL,
  data_nasterii date,
  telefon varchar2(15 CHAR)
);


CREATE TABLE Cazare_AVA (
  id_camera number(10),
  id_client number(10),
  data_sosire date CONSTRAINT  data_sosire_not_null NOT NULL,
  data_plecare date CONSTRAINT data_plecare_not_null NOT NULL,
  CONSTRAINT id_camera_client_PK_AVA PRIMARY KEY (id_camera,id_client),
  CONSTRAINT id_camera_FK_AVA FOREIGN KEY (id_camera) REFERENCES Camera_AVA(id_camera),
  CONSTRAINT id_client_FK_AVA FOREIGN KEY (id_client) REFERENCES Client_AVA(id_client)
);


CREATE TABLE Personal_AVA (
  id_angajat number(10) CONSTRAINT id_angajat_PK_AVA PRIMARY KEY,
  id_hotel number(10),
  nume varchar2(50 CHAR) CONSTRAINT nume_angajat_not_null NOT NULL,
  prenume varchar2(50 CHAR) CONSTRAINT prenume_angajat_not_null NOT NULL,
  data_angajare date CONSTRAINT data_angajare_not_null NOT NULL,
  salariu number(10) CONSTRAINT salariu_not_null NOT NULL,
  telefon number(10),
  CONSTRAINT id_hotel_personal_FK_AVA FOREIGN KEY (id_hotel) REFERENCES Hotel_AVA(id_hotel)
);


INSERT INTO Adresa_AVA(id_adresa, nume_strada, oras, judet, tara)
VALUES (1,'Strada Martisorului', 'Brasov', 'Brasov', 'Romania');

INSERT INTO Adresa_AVA(id_adresa, nume_strada, oras, judet, tara)
VALUES (2,'964 Route des Gaillands', 'Chamonix', '', 'Franta');

INSERT INTO Adresa_AVA(id_adresa, nume_strada, oras, judet, tara)
VALUES (3,'Strada Gheorghe Donici', 'Bacau', 'Bacau', 'Romania');

INSERT INTO Adresa_AVA(id_adresa, nume_strada, oras, judet, tara)
VALUES (4,'Bulevardul Mamaia Nr 566', 'Constanta', 'Constanta', 'Romania');

INSERT INTO Adresa_AVA(id_adresa, nume_strada, oras, judet, tara)
VALUES (5,'Bulevardul Mamaia 477', 'Constanta', 'Constanta', 'Romania');

INSERT INTO Adresa_AVA(id_adresa, nume_strada, oras, judet, tara)
VALUES (6,'Bulevardul Carol I', 'Sinaia', 'Prahova', 'Romania');



INSERT INTO Hotel_AVA(id_hotel, id_adresa, nume, nr_stele)
VALUES (1, 1, 'Golden Peak', 4);

INSERT INTO Hotel_AVA(id_hotel, id_adresa, nume, nr_stele)
VALUES (2, 4, 'Hotel Doina', 3);

INSERT INTO Hotel_AVA(id_hotel, id_adresa, nume, nr_stele)
VALUES (3, 4, 'Hotel Nyota', 5);

INSERT INTO Hotel_AVA(id_hotel, id_adresa, nume, nr_stele)
VALUES (4, 5, 'Hotel Spendid', 4);

INSERT INTO Hotel_AVA(id_hotel, id_adresa, nume, nr_stele)
VALUES (5, 6, 'Hotel Rina', 4);

INSERT INTO Hotel_AVA(id_hotel, id_adresa, nume, nr_stele)
VALUES (6, 2, 'Le Vert Hôtel', 5);



INSERT INTO Personal_AVA(id_angajat, id_hotel, nume, prenume, data_angajare, salariu, telefon)
VALUES (1, 1, 'Vasile', 'Florian', to_date('20-06-2020','dd-mm-yyyy'), 2500, to_char('0726093456'));

INSERT INTO Personal_AVA(id_angajat, id_hotel, nume, prenume, data_angajare, salariu, telefon)
VALUES (2, 3, 'Popescu', 'Ciprian', to_date('18-01-2020','dd-mm-yyyy'), 3200, to_char('0726463432'));

INSERT INTO Personal_AVA(id_angajat, id_hotel, nume, prenume, data_angajare, salariu, telefon)
VALUES (3, 3, 'Marin', 'Alexandru', to_date('03-11-2018','dd-mm-yyyy'), 4500, to_char('0726362747'));

INSERT INTO Personal_AVA(id_angajat, id_hotel, nume, prenume, data_angajare, salariu, telefon)
VALUES (4, 5, 'Ionescu', 'Matei', to_date('13-09-2019','dd-mm-yyyy'), 3750, to_char('0726839521'));

INSERT INTO Personal_AVA(id_angajat, id_hotel, nume, prenume, data_angajare, salariu, telefon)
VALUES (5, 6, 'Depardieu', 'Jean', to_date('15-02-2019','dd-mm-yyyy'), 7500, to_char('0726126367'));

INSERT INTO Personal_AVA(id_angajat, id_hotel, nume, prenume, data_angajare, salariu, telefon)
VALUES (6, 5, 'Dumitrescu', 'Florian', to_date('25-09-2019','dd-mm-yyyy'), 3500, to_char('0726259634'));



INSERT INTO Client_AVA(id_client, nume, prenume, data_nasterii,telefon)
VALUES (1, 'Popa', 'Florin', to_date('13-12-1970','dd-mm-yyyy'), to_char('0726592753'));

INSERT INTO Client_AVA(id_client, nume, prenume, data_nasterii,telefon)
VALUES (2, 'Marinescu', 'Andrei', to_date('15-10-1999','dd-mm-yyyy'), to_char('0726937547'));

INSERT INTO Client_AVA(id_client, nume, prenume, data_nasterii,telefon)
VALUES (3, 'Radu', 'Cosmin', to_date('10-04-1990','dd-mm-yyyy'), to_char('0726291754'));

INSERT INTO Client_AVA(id_client, nume, prenume, data_nasterii,telefon)
VALUES (4, 'Ionescu', 'Cristian', to_date('02-03-1960','dd-mm-yyyy'), to_char('0726386739'));



INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (1,1,1);

INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (2,2,1);

INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (3,4,1);

INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (4,5,1);

INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (5,3,100);

INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (6,3,101);

INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (7,6,201);

INSERT INTO Camera_AVA(id_camera,id_hotel,numar_camera)
VALUES (8,6,202);




INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (1,1, to_date('20-11-2018','dd-mm-yyyy'),to_date('25-11-2018','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (2,1, to_date('20-06-2020','dd-mm-yyyy'),to_date('23-06-2020','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (7,1, to_date('10-06-2019','dd-mm-yyyy'),to_date('15-06-2019','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (5,1, to_date('05-03-2017','dd-mm-yyyy'),to_date('09-03-2017','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (3,2, to_date('20-05-2020','dd-mm-yyyy'),to_date('22-05-2020','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (4,2, to_date('18-07-2019','dd-mm-yyyy'),to_date('20-07-2019','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (6,3, to_date('13-08-2018','dd-mm-yyyy'),to_date('16-08-2018','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (1,3, to_date('23-06-2019','dd-mm-yyyy'),to_date('26-06-2019','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (2,4, to_date('25-08-2019','dd-mm-yyyy'),to_date('05-09-2019','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (5,4, to_date('17-07-2020','dd-mm-yyyy'),to_date('18-07-2020','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (6,4, to_date('02-02-2020','dd-mm-yyyy'),to_date('09-02-2020','dd-mm-yyyy'));

INSERT INTO Cazare_AVA(id_camera,id_client,data_sosire,data_plecare)
VALUES (1,4, to_date('19-04-2020','dd-mm-yyyy'),to_date('23-04-2020','dd-mm-yyyy'));
