# Write your MySQL query statement below
with cte as (
    SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk FROM Employee
)

SELECT (SELECT DISTINCT salary FROM cte WHERE rnk = 2) AS SecondHighestSalary;