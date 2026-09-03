# Write your MySQL query statement below
with cte as (
    SELECT id FROM (
        SELECT email,min(id) as id FROM Person GROUP BY email
    ) t
)

DELETE FROM Person WHERE id NOT IN (SELECT * FROM cte);