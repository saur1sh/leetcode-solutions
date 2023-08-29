# Write your MySQL query statement below
select employee_id
from Employees
WHERE manager_id NOT IN (SELECT employee_id from Employees)
AND SALARY<30000
order by employee_id;