# Movies

Write SQL queries to answer questions about a database of movies.

## Getting started

Here’s how to download this problem into your own CS50 IDE. Log into CS50 IDE and then, in a terminal window, execute each of the below.

Execute cd to ensure that you’re in ~/ (i.e., your home directory, aka ~).
If you haven’t already, execute mkdir pset7 to make (i.e., create) a directory called pset7 in your home directory.
Execute cd pset7 to change into (i.e., open) that directory.
Execute wget https://cdn.cs50.net/2019/fall/psets/7/movies/movies.zip to download a (compressed) ZIP file with this problem’s distribution.
Execute unzip movies.zip to uncompress that file.
Execute rm movies.zip followed by yes or y to delete that ZIP file.
Execute ls. You should see a directory called movies, which was inside of that ZIP file.
Execute cd movies to change into that directory.
Execute ls. You should see a movies.db file, and some empty .sql files as well.
Alternatively, you’re welcome to download and unzip cdn.cs50.net/2019/fall/psets/7/movies/movies.zip on your own computer and then open it in DB Browser for SQLite. But be sure to upload your .sql files to CS50 IDE ultimately so that you can submit them via submit50.

## Specification queries

In 1.sql, write a SQL query to list the titles of all movies released in 2008.
Your query should output a table with a single column for the title of each movie.
In 2.sql, write a SQL query to determine the birth year of Emma Stone.
Your query should output a table with a single column and a single row (plus optional header) containing Emma Stone’s birth year.
You may assume that there is only one person in the database with the name Emma Stone.
In 3.sql, write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
Your query should output a table with a single column for the title of each movie.
Movies released in 2018 should be included, as should movies with release dates in the future.
In 4.sql, write a SQL query to determine the number of movies with an IMDb rating of 10.0.
Your query should output a table with a single column and a single row (plus optional header) containing the number of movies with a 10.0 rating.
In 5.sql, write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.
In 6.sql, write a SQL query to determine the average rating of all movies released in 2012.
Your query should output a table with a single column and a single row (plus optional header) containing the average rating.
In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
Movies that do not have ratings should not be included in the result.
In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
Your query should output a table with a single column for the name of each person.
You may assume that there is only one movie in the database with the title Toy Story.
In 9.sql, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
Your query should output a table with a single column for the name of each person.
People with the same birth year may be listed in any order.
No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
If a person appeared in more than one movie in 2004, they should only appear in your results once.
In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
Your query should output a table with a single column for the name of each person.
In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Chadwick Boseman.
In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Johnny Depp.
You may assume that there is only one person in the database with the name Helena Bonham Carter.
In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
Your query should output a table with a single column for the name of each person.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.

## Usage 

At CS50 IDE in folder make a steps from getting started than copy code of each queries. After that fallow those steps:

1. Run our database in DBMS - Sqlite3 by typing in console: sqlite3 movies.db
2. Than read our queries on that DB by command: .read "ourfile".sql

