# Write your MySQL query statement below
select w1.Id
from Weather as w1, Weather as w2
where datediff(w1.RecordDate, w2.RecordDate) = 1 and w1.Temperature > w2.Temperature;