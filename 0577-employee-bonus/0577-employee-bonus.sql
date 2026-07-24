# Write your MySQL query statement below
with it as (
    Select e.name as name , b.bonus as bonus 
    from Employee e LEFT JOIN Bonus b ON e.empId = b.empId
)

Select name, bonus from it where (bonus < 1000 or bonus is null)