-- Write your PostgreSQL query statement below
with t1 as (
    select query_name, sum(cast(rating as numeric) / cast(position as numeric)) as summation
    from queries
    group by query_name
), t2 as (
    select query_name, count(query_name) as count
    from queries
    group by query_name
), t3 as (
    select 
        query_name, 
        sum(case when rating < 3 then 1 ELSE 0 end) as poor
    from queries
    group by query_name
), t4 as (
    select t1.query_name, round(t1.summation / t2.count, 2) as quality
    from t1
    join t2
    on t1.query_name = t2.query_name
), t5 as (
    select 
        t3.query_name,
        round((cast(t3.poor as numeric) / cast(t2.count as numeric)) * 100, 2) as poor_query_percentage
    from t3
    join t2
    on t3.query_name = t2.query_name
)

select t4.query_name, t4.quality, t5.poor_query_percentage 
from t4
join t5
on t4.query_name = t5.query_name;
