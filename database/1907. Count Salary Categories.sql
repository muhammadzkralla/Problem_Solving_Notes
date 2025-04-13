-- Write your PostgreSQL query statement below
with t1 as (
    select * from accounts where income < 20000
), t2 as (
    select * from accounts where income >= 20000 and income <= 50000
), t3 as (
    select * from accounts where income > 50000
)

select 'High Salary' as category, count(*) as accounts_count from t3
union all
select 'Average Salary', count(*) from t2
union all
select 'Low Salary', count(*)from t1;
