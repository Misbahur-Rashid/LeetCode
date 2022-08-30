# Write your MySQL query statement below
SELECT id,
MAX(CASE WHEN month='Jan' then revenue else null end) Jan_Revenue,
MAX(CASE WHEN month='Feb' then revenue else null end) Feb_Revenue,
MAX(CASE WHEN month='Mar' then revenue else null end) Mar_Revenue,
MAX(CASE WHEN month='Apr' then revenue else null end) Apr_Revenue,
MAX(CASE WHEN month='May' then revenue else null end) May_Revenue,
MAX(CASE WHEN month='Jun' then revenue else null end) Jun_Revenue,
MAX(CASE WHEN month='Jul' then revenue else null end) Jul_Revenue,
MAX(CASE WHEN month='Aug' then revenue else null end) Aug_Revenue,
MAX(CASE WHEN month='Sep' then revenue else null end) Sep_Revenue,
MAX(CASE WHEN month='Oct' then revenue else null end) Oct_Revenue,
MAX(CASE WHEN month='Nov' then revenue else null end) Nov_Revenue,
MAX(CASE WHEN month='Dec' then revenue else null end) Dec_Revenue
From
Department
Group By id