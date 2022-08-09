# Write your MySQL query statement below
select u.name, c.balance
from Users u
right join
(
    select account, sum(amount) as balance
    from Transactions
    group by 1
) c
on u.account = c.account
where balance > 10000;