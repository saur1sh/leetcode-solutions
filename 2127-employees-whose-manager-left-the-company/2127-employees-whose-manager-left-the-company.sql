# Write your MySQL query statement below
SELECT employee_id
from Employees
where manager_id NOT IN (SELECT employee_id from Employees)
AND salary<30000
ORDER BY employee_id;