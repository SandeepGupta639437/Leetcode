CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    with ranked as (
        SELECT salary as getNthHighestSalary,
        DENSE_RANK() OVER (ORDER BY salary desc) as rnk
        from Employee
    ) 
    
        SELECT getNthHighestSalary
        from ranked
        where rnk = N
        LIMIT 1

  );
END