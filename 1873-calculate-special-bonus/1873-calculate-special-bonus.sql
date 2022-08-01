# Write your MySQL query statement below
#SELECT employee_id, IF(employee_id % 2 != 0 and SUBSTRING(name, 1, 1) != 'M', salary, 0) AS bonus from Employees
select employee_id,
case when employee_id%2=1 and left(name, 1) != 'M' then salary else 0 end as bonus
from Employees
order by employee_id