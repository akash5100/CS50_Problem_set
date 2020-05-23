SELECT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN (SELECT movie_id FROM stars WHERE stars.person_id
                IN (SELECT id FROM people WHERE name='Kevin Bacon' AND birth=1958)) 
AND name != 'Kevin Bacon';
