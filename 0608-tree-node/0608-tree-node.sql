# Write your MySQL query statement below
select id,
  case
    when isnull(p_id) then 'Root'
    when id in (select p_id from tree) then 'Inner'
    else 'Leaf'
  end as type
from Tree
group by id, p_id