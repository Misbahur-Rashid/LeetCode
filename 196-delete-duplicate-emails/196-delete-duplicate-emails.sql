# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete p.*
from Person as p,(
select Email, min(Id) as minId
from Person
group by Email
having count(*)>1
) as q
where p.Email = q.Email and Id > q.minId;