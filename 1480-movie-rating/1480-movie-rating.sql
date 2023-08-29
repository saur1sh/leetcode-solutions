# Write your MySQL query statement below
WITH cte AS
(SELECT mr.*, u.name, m.title
from MovieRating mr
LEFT JOIN Movies m
on mr.movie_id=m.movie_id
LEFT JOIN Users u
on mr.user_id=u.user_id)

( select name as results
  from cte
  group by name
  order by count(*) DESC, name LIMIT 1
)
UNION ALL
(
  SELECT title
  from cte
  WHERE DATE_FORMAT(created_at, '%Y-%m')='2020-02'
  GROUP BY title
  ORDER BY AVG(RATING) DESC, title LIMIT 1
);