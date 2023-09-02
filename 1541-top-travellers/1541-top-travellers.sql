# Write your MySQL query statement below
select u.name, if(isnull(sum(r.distance)), 0, sum(r.distance)) as travelled_distance
from users u
left join rides r
on r.user_id=u.id
group by u.id
order by travelled_distance desc, name asc