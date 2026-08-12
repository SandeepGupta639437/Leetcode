# Write your MySQL query statement below
SELECT t.request_at AS Day , ROUND(SUM(CASE WHEN t.status LIKE 'cancelled%' THEN 1 ELSE 0 END)/ COUNT(*),2) AS "Cancellation Rate"
FROM Trips AS t
LEFT JOIN Users AS u1
ON t.client_id = u1.users_id
LEFT JOIN Users AS u2
ON t.driver_id = u2.users_id
WHERE u1.banned = 'No'
AND u2.banned = 'No'
AND t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;