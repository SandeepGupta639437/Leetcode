# Write your MySQL query statement below
-- SELECT e1.name Employee 
-- FROM Employee e1
-- WHERE (e1.salary > (
--     SELECT e2.salary FROM Employee e2 WHERE e2.id = e1.managerID
-- ) )

SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
ON e.managerId = m.id
WHERE e.salary > m.salary;