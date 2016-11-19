PRAGMA FOREIGN_KEY = TRUE;
drop table Administrator;
CREATE TABLE Administrator(ID INTEGER PRIMARY KEY AUTOINCREMENT,
login varchar(255) not null unique,
password integer not null,
id_teatra integer not null,
FOREIGN KEY (id_teatra) REFERENCES teatr(id));

drop table Teatr;
create table Teatr(ID INTEGER PRIMARY KEY AUTOINCREMENT,
id_postanovki INTEGER not null,
vsego_mest integer not null,
cost_beletaj integer not null,
cost_parter integer not null,
cost_benuar integer not null,
FOREIGN KEY (id_postanovki) REFERENCES Postanovka(id)
);
drop table Postanovka;
create table Postanovka(ID INTEGER PRIMARY KEY AUTOINCREMENT,
Name varchar(255) not null unique,
time_seansa time unique not null unique,
date_seansa date unique not null
);