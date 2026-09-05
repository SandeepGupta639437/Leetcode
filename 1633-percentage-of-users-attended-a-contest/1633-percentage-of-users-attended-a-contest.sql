# Write your MySQL query statement below
SELECT r.contest_id , ROUND(
    COUNT(DISTINCT user_id)*100/(SELECT COUNT(user_id) FROM Users)
    ,2) as percentage
FROM Register r 
GROUP BY r.contest_id
ORDER BY percentage DESC , contest_id ASC ## if percentage is same then orders by contest_id