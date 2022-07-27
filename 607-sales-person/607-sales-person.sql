# Write your MySQL query statement below
select s.name
from salesperson as s
where s.sales_id not in(
select sales_id
from orders as o left join company as c on o.com_id = c.com_id
where c.name = 'RED');