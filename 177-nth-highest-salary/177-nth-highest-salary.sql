CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      select distinct e.Salary
      from Employee e
      order by e.Salary desc
      limit N, 1
  );
END