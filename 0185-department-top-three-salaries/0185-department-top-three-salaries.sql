# Write your MySQL query statement below
with ranked as (
    SELECT e.name as Employee, e.salary as Salary , d.name as Department,
    DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY e.salary desc) as rnk
    from Employee e JOIN Department d ON e.departmentId = d.id
)

SELECT Department,Employee,Salary 
FROM ranked
WHERE rnk < 4