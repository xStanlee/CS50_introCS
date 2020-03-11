--12--

SELECT title FROM movies
INNER JOIN stars ON movies.id = stars.movie_id
INNER JOIN people ON people.id = stars.person_id

WHERE people.name = 'Helena Bonham Carter' AND people.name = ' Johnny Depp';
