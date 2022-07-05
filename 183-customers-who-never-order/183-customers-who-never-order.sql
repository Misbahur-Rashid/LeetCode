# Write your MySQL query statement below
select Name as Customers
from Customers
Where Id not in (
select CustomerId
from Orders
);