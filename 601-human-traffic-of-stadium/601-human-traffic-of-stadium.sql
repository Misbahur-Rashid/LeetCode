# Write your MySQL query statement below
SELECT DISTINCT s1.*
FROM stadium s1, stadium s2, stadium s3
WHERE s1.people >= 100 AND s2.people >= 100 AND s3.people >= 100
AND ((s1.id = s2.id -1 AND s1.id = s3.id - 2) -- start of window (if three consecutive is detected and only this condition is set, only the first row will be returned)
     OR (s1.id = s2.id + 1 AND s1.id = s3.id -1) -- middle of the window (with this condition the middle value will be returned)
     OR (s1.id = s2.id + 2 AND s1.id = s3.id +1 )) -- end of the window (with this the last value)
ORDER BY s1.id;