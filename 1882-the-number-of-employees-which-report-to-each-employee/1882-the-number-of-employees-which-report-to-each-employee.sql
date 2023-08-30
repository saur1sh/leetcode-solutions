# Write your MySQL query statement below
with cte as 
(
  select reports_to, count(employee_id) as reports_count, ROUND(AVG(age), 0) as average_age
  from Employees
  where reports_to IS NOT NULL
  GROUP BY reports_to
)

SELECT e.employee_id, e.name, c.reports_count, c.average_age
from cte c
left join employees e
on e.employee_id=c.reports_to
order by employee_id;