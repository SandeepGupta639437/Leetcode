# Write your MySQL query statement below
WITH cte AS (
    SELECT id 
    FROM (
        SELECT email, min(id) AS id 
        FROM Person 
        GROUP BY email
    ) t
)

DELETE FROM Person WHERE id NOT IN (SELECT * FROM cte);