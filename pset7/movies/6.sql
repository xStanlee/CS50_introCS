SELECT AVG(rating) AS Avarge_2012
FROM movies
INNER JOIN ratings ON movies.id = ratings.movie_id WHERE year=2012;
