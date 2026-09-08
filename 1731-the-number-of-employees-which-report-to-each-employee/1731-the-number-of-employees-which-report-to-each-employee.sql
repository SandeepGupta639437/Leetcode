SELECT 
    e.reports_to AS employee_id,
    m.name AS name,
    COUNT(*) AS reports_count,
    ROUND(AVG(e.age), 0) AS average_age
FROM Employees e
JOIN Employees m
    ON e.reports_to = m.employee_id
GROUP BY e.reports_to
ORDER BY e.reports_to ASC;