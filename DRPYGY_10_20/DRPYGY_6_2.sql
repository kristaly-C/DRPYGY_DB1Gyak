CREATE TABLE GYARTO (
  adoszam int PRIMARY KEY,
  nev varchar(30) NOT NULL,
  irsz varchar(4) NOT NULL,
  varos varchar(40),
  utca varchar(100) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE TERMEK (
  tkod int PRIMARY KEY,
  nev varchar(50) NOT NULL,
  ear int CHECK (ear > 0),
  gyarto int,
   FOREIGN KEY (gyarto) REFERENCES gyarto(adoszam)
) ENGINE=InnoDB;

CREATE TABLE EGYSEGEK (
  aru int,
  db int CHECK (db > 0),
 FOREIGN KEY (aru) REFERENCES termek(tkod)
) ENGINE=InnoDB;

CREATE TABLE ALKATRESZ (
  akod int PRIMARY KEY,
  nev varchar(50)
) ENGINE=InnoDB;

CREATE TABLE KOMPONENSEK (
  termek int,
  alkatresz int,
  FOREIGN KEY (termek) REFERENCES termek(tkod),
  FOREIGN KEY (alkatresz) REFERENCES alkatresz(akod)
) ENGINE=InnoDB;