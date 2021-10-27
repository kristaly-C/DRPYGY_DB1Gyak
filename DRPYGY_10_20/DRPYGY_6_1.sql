CREATE TABLE GYARTO (
  adoszam int PRIMARY KEY,
  nev varchar(30) NOT NULL,
  telephely varchar(100) NOT NULL
) ENGINE=InnoDB

CREATE TABLE TERMEK (
  tkod int PRIMARY KEY,
  nev varchar(50) NOT NULL,
  ear int CHECK (ear > 0),
  gyarto int,
   FOREIGN KEY (gyarto) REFERENCES gyarto(adoszam)
) ENGINE=InnoDB