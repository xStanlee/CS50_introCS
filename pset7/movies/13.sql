--13--

SELECT name FROM people
JOIN stars ON people.id = stars.person_id JOIN
movies ON stars.movie_id = movies.id
WHERE title = (SELECT title FROM
people JOIN stars ON people.id = stars.person_id JOIN
movies ON stars.movie_id = movies.id

WHERE name = 'Kevin Bacon' and birth = 1958);
