SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id 
JOIN people ON people.id = stars.person_id 
WHERE people.name IS 'Helena Bonham Carter'
INTERSECT
SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id 
JOIN people ON people.id = stars.person_id 
WHERE people.name IS 'Johnny Depp';