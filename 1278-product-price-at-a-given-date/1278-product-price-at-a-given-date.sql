# Write your MySQL query statement below
SELECT  product_id,
    FIRST_VALUE(new_price) OVER (PARTITION BY product_id ORDER BY change_date DESC) AS price
from products
where change_date<'2019-08-17'
union
select
product_id, 10 as price
from products
group by product_id
having min(change_date)>'2019-08-16'