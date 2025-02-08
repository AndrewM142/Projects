/*Select *
From Publisher
;

Select *
From Genre
;

Select *
From Platform
;

Select *
From Game
;

Select *
From Sales
;
*/

-- 1
SELECT Game.Name, Publisher.Publisher_Name
From Game INNER JOIN Publisher ON Publisher.Publisher_ID = Game.Publisher_ID
;

-- 2
Select Game.Name, Sales.NA_Sales, Sales.EU_Sales, Sales.JP_Sales, Sales.Other_Sales
From Game INNER JOIN Sales ON Game.Rank = Sales.Rank
;

-- 3
SELECT Game.Rank, Game.Name, Publisher.Publisher_Name, SUM(Sales.NA_Sales + Sales.EU_Sales + Sales.JP_Sales + Sales.Other_Sales) AS "Total Game Sales (M)"
FROM Sales INNER JOIN Game ON Game.Rank = Sales.Rank INNER JOIN Publisher ON Publisher.Publisher_ID = Game.Publisher_ID
GROUP BY Game.Name, Game.Publisher_ID, Game.Rank
ORDER BY Game.Rank
;

-- 4
SELECT Game.Name, Game.Year AS "Release Year", Publisher.Publisher_Name, Platform.Platform_Name
FROM Game INNER JOIN Publisher ON Game.Publisher_ID = Publisher.Publisher_ID INNER JOIN Platform ON Game.Platform_ID = Platform.Platform_ID
;

-- 5
SELECT Game.Name, Platform.Platform_Name, Game.Year
FROM Game INNER JOIN Platform ON Game.Platform_ID = Platform.Platform_ID
WHERE Game.Year Like '19%'
;

-- 6
SELECT DISTINCT Platform.Platform_Name, Publisher.Publisher_Name AS 'Company'
FROM Platform LEFT JOIN Game ON Game.Platform_ID = Platform.Platform_ID LEFT JOIN Publisher ON Game.Publisher_ID = Publisher.Publisher_ID
;

-- 7
SELECT Platform_Name, Release_Date
FROM Platform
ORDER BY Platform_Name
;

-- 8
SELECT Platform.Platform_Name, SUM(Sales.NA_Sales + Sales.EU_Sales + Sales.JP_Sales + Sales.Other_Sales) AS "Total Platform Sales (M)"
FROM Platform LEFT JOIN Game ON Game.Platform_ID = Platform.Platform_ID LEFT JOIN Sales ON Sales.Rank = Game.Rank
GROUP BY Platform.Platform_Name;


-- 9
SELECT Game.Year, COUNT(Game.Rank) AS "Games per Year"
FROM Game
GROUP BY Game.Year
ORDER BY Game.Year DESC
;

-- 10
SELECT Platform.Platform_Name, COUNT(Game.Rank) AS "Games per Platform"
FROM Platform LEFT JOIN Game ON Platform.Platform_ID = Game.Platform_ID
GROUP BY Platform.Platform_Name
;

-- 11
SELECT Game.Name, Genre.Genre_Name
FROM Genre INNER JOIN Game ON Genre.Genre_ID = Game.Genre_ID
ORDER BY Genre.Genre_Name, Game.Name
;