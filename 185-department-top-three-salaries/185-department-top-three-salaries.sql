# Write your MySQL query statement below
select d1.Name as Department, e1.Name as Employee, e1.Salary as Salary
from Employee e1, Department d1
where e1.DepartmentId  = d1.Id and 3 > (select count(distinct(e2.salary)) from Employee e2 where e2.salary > e1.salary and e2.DepartmentId = e1.DepartmentId)