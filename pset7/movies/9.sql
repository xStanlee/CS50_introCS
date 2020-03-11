--9--

SELECT DISTINCT(name) FROM people
INNER JOIN stars ON people.id = stars.person_id
INNER JOIN movies ON movies.id = stars.movie_id
WHERE movies.year = 2004 ORDER BY people.birth;
