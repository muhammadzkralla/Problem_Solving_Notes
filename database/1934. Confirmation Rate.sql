-- Write your PostgreSQL query statement below
with t1 as (
    select user_id, count(user_id) as rate
    from confirmations
    where action = 'confirmed'
    group by user_id
), t2 as (
    select user_id, count(user_id) as total
    from confirmations
    group by user_id
), t3 as (
    select 
        t2.user_id,
        round(cast(t1.rate as numeric) / cast(t2.total as numeric), 2) as confirmation_rate
    from t2
    join t1
    on t2.user_id = t1.user_id
)

select signups.user_id, coalesce(t3.confirmation_rate, 0) AS confirmation_rate
from signups
left join t3
on signups.user_id = t3.user_id;
