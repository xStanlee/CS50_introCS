/*
Shows 10.0 rating films from IMBd (was curious)

SELECT ratings.rating, ratings.votes
FROM movies
INNER JOIN ratings ON movies.id = ratings.movie_id WHERE ratings.rating = 10;
*/

SELECT COUNT(rating) AS Counter
FROM ratings
WHERE rating = 10;
