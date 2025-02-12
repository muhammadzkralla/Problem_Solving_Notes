-- Write your PostgreSQL query statement below
with t1 as (
    select employee_id, department_id
    from employee
    where primary_flag = 'Y'
), t2 as (
    select employee_id
    from employee
    group by employee_id
    having COUNT(*) = 1
), t3 as (
    select t2.employee_id, employee.department_id
    from t2
    left join employee
    on t2.employee_id = employee.employee_id
)

select * from t1 union select * from t3;
