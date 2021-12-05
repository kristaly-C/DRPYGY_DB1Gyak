CREATE TABLE tanfolyam (
	tkod int PRIMARY KEY,
	ar INT,
	tipus VARCHAR,
	megnevezes VARCHAR);
CREATE TABLE resztvevo (
	tajszam VARCHAR PRIMARY KEY,
	nev VARCHAR NOT NULL,
	lakcim VARCHAR);
CREATE TABLE resztvevo_tanfolyam (
	tanfolyam INT,
	resztvevo VARCHAR,
	befizetes INT,
	FOREIGN KEY (tanfolyam) REFERENCES tanfolyam(tkod),
	FOREIGN KEY (resztvevo) REFERENCES resztvevo(tajszam));