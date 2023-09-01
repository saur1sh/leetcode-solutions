# Write your MySQL query statement below
select id, count(*) as num
from 
(
  (select requester_id id from requestaccepted)
  union all
  (select accepter_id from requestaccepted)
) tb
group by id
order by num desc LIMIT 1;