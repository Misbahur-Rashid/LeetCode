# Write your MySQL query statement below
select Email
from person
group by Email
having count(Email)>1;