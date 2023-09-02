# Write your MySQL query statement below
select p.product_name, SUM(unit) as unit
from products p
inner join orders o
on p.product_id=o.product_id
where extract(YEAR_MONTH FROM o.order_date) = '202002'
group by p.product_id
having SUM(unit)>=100