# Write your MySQL query statement below
select t.Request_at as Day, round(sum(case when t.Status != 'completed' then 1 else 0 end)/count(*),2)
as 'Cancellation Rate'
from Trips t
where t.Client_Id in (select Users_Id from Users where Banned ='No')
and t.Driver_Id in (select Users_Id from Users where Banned = 'No')
and t.Request_at between '2013-10-01' and '2013-10-03'
group by t.Request_at;