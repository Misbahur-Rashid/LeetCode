/* Write your T-SQL query statement below */
select Score, (select count(distinct Score) from Scores where Score >= s.Score)
as Rank 
from Scores as s
order by Score desc;