# Write your MySQL query statement below
SELECT class
from courses
group by class
having count(class)>=5