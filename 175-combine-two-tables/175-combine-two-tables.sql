# Write your MySQL query statement below
select FirstName, LastName, City, State from Person as p left join Address as a on p.PersonID = a.PersonID