# Write your MySQL query statement below
select * from 
(
    select product_id, 'store1' store, store1 price from Products
    union 
    select product_id, 'store2' store, store2 price from Products
    union
    select product_id, 'store3' store, store3 price from Products
)t 
where price is not null;