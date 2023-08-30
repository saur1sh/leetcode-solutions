# Write your MySQL query statement below
SELECT me.employee_id, me.name, count(me.employee_id) as reports_count, ROUND(avg(e.age)) as average_age
from employees e join employees me
on e.reports_to = me.employee_id
group by employee_id
order by employee_id