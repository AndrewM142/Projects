DROP TRIGGER IF EXISTS GameAdd;
DROP TABLE IF EXISTS GameLog;
DROP TABLE IF EXISTS Sales;
DROP TABLE IF EXISTS Game;
DROP TABLE IF EXISTS Publisher;
DROP TABLE IF EXISTS Platform;
DROP TABLE IF EXISTS Genre;


CREATE TABLE Publisher
(
  Publisher_ID INT NOT NULL,
  Publisher_Name CHAR(30) NOT NULL,
  HQ_Location CHAR(30) NOT NULL,
  PRIMARY KEY (Publisher_ID)
);

CREATE TABLE Platform
(
  Platform_ID INT NOT NULL,
  Platform_Name CHAR(20) NOT NULL,
  Release_Date CHAR(20) NOT NULL,
  PRIMARY KEY (Platform_ID)
);

CREATE TABLE Genre
(
  Genre_ID INT NOT NULL,
  Genre_Name CHAR(30) NOT NULL,
  Visual_Style CHAR(30) NOT NULL,
  PRIMARY KEY (Genre_ID)
);

CREATE TABLE Game
( 
  Rank INT NOT NULL,
  Name CHAR(30) NOT NULL,
  Year CHAR(4) NOT NULL,
  Publisher_ID INT NOT NULL,
  Genre_ID INT NOT NULL,
  Platform_ID INT NOT NULL,
  PRIMARY KEY (Rank),
  FOREIGN KEY (Publisher_ID) REFERENCES Publisher(Publisher_ID),
  FOREIGN KEY (Genre_ID) REFERENCES Genre(Genre_ID),
  FOREIGN KEY (Platform_ID) REFERENCES Platform(Platform_ID)
);

CREATE TABLE Sales
(
  Rank INT NOT NULL,
  NA_Sales DECIMAL(4,2) NOT NULL,
  EU_Sales DECIMAL(4,2) NOT NULL,
  JP_Sales DECIMAL(4,2) NOT NULL,
  Other_Sales DECIMAL(4,2) NOT NULL,
  FOREIGN KEY (Rank) REFERENCES Game(Rank)
);

CREATE TABLE GameLog(
	Message VARCHAR(100)
);

DROP TRIGGER IF EXISTS GameAdd;

CREATE TRIGGER GameAdd
AFTER INSERT ON Game
FOR EACH ROW
INSERT INTO GameLog (Message)
SELECT CONCAT('You inserted a new game from ', Publisher.Publisher_Name)
FROM Publisher
WHERE Publisher.Publisher_ID = NEW.Publisher_ID;
;

INSERT INTO Publisher VALUES(1,'Nintendo','Kyoto, Japan');
INSERT INTO Publisher VALUES(2,'Microsoft Game Studios','Redmond, WA');
INSERT INTO Publisher VALUES(3,'Take-Two Interactive','New York, NY');
INSERT INTO Publisher VALUES(4,'Sony Computer Entertainment','San Mateo, CA');
INSERT INTO Publisher VALUES(5,'Ubisoft','Montreuil, France');
INSERT INTO Publisher VALUES(6,'Bethesda Softworks','Rockville, Maryland');
INSERT INTO Publisher VALUES(7,'Electronic Arts','Redwood City, CA');
INSERT INTO Publisher VALUES(8,'Microsoft Game Studios','Redmond, WA');
INSERT INTO Publisher VALUES(9,'Sega','Tokyo, Japan');
INSERT INTO Publisher VALUES(10,'SquareSoft','Tokyo, Japan');

INSERT INTO Genre VALUES(1,'Sports','3D Cartoon');
INSERT INTO Genre VALUES(2,'Platform','2D Cartoon');
INSERT INTO Genre VALUES(3,'Racing','3D Cartoon');
INSERT INTO Genre VALUES(4,'Role-Playing','Pixel-Art');
INSERT INTO Genre VALUES(5,'Puzzle','Pixel-Art');
INSERT INTO Genre VALUES(6,'Platform','3D Cartoon');
INSERT INTO Genre VALUES(7,'Misc','3D Cartoon');
INSERT INTO Genre VALUES(8,'Shooter','2D Cartoon');
INSERT INTO Genre VALUES(9,'Simulation','3D Realistic');
INSERT INTO Genre VALUES(10,'Misc','3D Semi-Realistic');
INSERT INTO Genre VALUES(11,'Action','3D Realistic');
INSERT INTO Genre VALUES(12,'Action','3D Cartoon');

INSERT INTO Platform VALUES(1,'Wii','11/19/2006');
INSERT INTO Platform VALUES(2,'NES','7/15/1983');
INSERT INTO Platform VALUES(3,'GB','4/21/1989');
INSERT INTO Platform VALUES(4,'DS','11/21/2004');
INSERT INTO Platform VALUES(5,'X360','11/22/2005');
INSERT INTO Platform VALUES(6,'PS3','11/11/2006');
INSERT INTO Platform VALUES(7,'PS2','3/4/2000');
INSERT INTO Platform VALUES(8,'SNES','9/9/1991');
INSERT INTO Platform VALUES(9,'GBA','6/11/2001');
INSERT INTO Platform VALUES(10,'3DS','2/26/2011');

INSERT INTO Game VALUES(1,'Wii Sports','2006',1,1,1);
INSERT INTO Game VALUES(2,'Super Mario Bros.','1985',1,2,2);
INSERT INTO Game VALUES(3,'Mario Kart Wii','2008',1,3,1);
INSERT INTO Game VALUES(4,'Wii Sports Resort','2009',1,1,1);
INSERT INTO Game VALUES(5,'Pokemon Red/Pokemon Blue','1996',1,4,3);
INSERT INTO Game VALUES(6,'Tetris','1989',1,5,3);
INSERT INTO Game VALUES(7,'New Super Mario Bros.','2006',1,6,4);
INSERT INTO Game VALUES(8,'Wii Play','2006',1,7,1);
INSERT INTO Game VALUES(9,'New Super Mario Bros. Wii','2009',1,6,1);
INSERT INTO Game VALUES(10,'Duck Hunt','1984',1,8,2);
INSERT INTO Game VALUES(11,'Nintendogs','2005',1,9,4);
INSERT INTO Game VALUES(16,'Kinect Adventures!','2010',2,10,5);
INSERT INTO Game VALUES(17,'Grand Theft Auto V','2013',3,11,6);
INSERT INTO Game VALUES(18,'Grand Theft Auto: San Andreas','2004',3,12,7);
INSERT INTO Game VALUES(19,'Super Mario World','1990',1,6,8);
INSERT INTO Game VALUES(26,'Pokemon Ruby/Pokemon Sapphire','2002',1,4,9);
INSERT INTO Game VALUES(33,'Pokemon X/Pokemon Y','2013',1,4,10);

INSERT INTO Sales VALUES(1,41.49,29.02,3.77,8.46);
INSERT INTO Sales VALUES(2,29.08,3.58,6.81,0.77);
INSERT INTO Sales VALUES(3,15.85,12.88,3.79,3.31);
INSERT INTO Sales VALUES(4,15.75,11.01,3.28,2.96);
INSERT INTO Sales VALUES(5,11.27,8.89,10.22,1);
INSERT INTO Sales VALUES(6,23.2,2.26,4.22,0.58);
INSERT INTO Sales VALUES(7,11.38,9.23,6.5,2.9);
INSERT INTO Sales VALUES(8,14.03,9.2,2.93,2.85);
INSERT INTO Sales VALUES(9,14.59,7.06,4.7,2.26);
INSERT INTO Sales VALUES(10,26.93,0.63,0.28,0.47);
INSERT INTO Sales VALUES(11,9.07,11,1.93,2.75);
INSERT INTO Sales VALUES(16,14.97,4.94,0.24,1.67);
INSERT INTO Sales VALUES(17,7.01,9.27,0.97,4.14);
INSERT INTO Sales VALUES(18,9.43,0.4,0.41,10.57);
INSERT INTO Sales VALUES(19,12.78,3.75,3.54,0.55);
INSERT INTO Sales VALUES(26,6.06,3.9,5.38,0.5);
INSERT INTO Sales VALUES(33,5.17,4.05,4.34,0.79);

DROP PROCEDURE IF EXISTS PublisherGames;

DELIMITER //

CREATE PROCEDURE PublisherGames(IN p_Publisher_ID INT)

BEGIN
    SELECT Game.Name AS Game_Name, Game.Year, Publisher.Publisher_Name
    FROM Game
    JOIN Publisher ON Game.Publisher_ID = Publisher.Publisher_ID
    WHERE Publisher.Publisher_ID = p_Publisher_ID;
END //

DELIMITER ;

CALL PublisherGames(1);

SELECT * FROM GameLog;
SHOW TRIGGERS;
