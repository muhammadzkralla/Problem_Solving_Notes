-- Write your PostgreSQL query statement below
with t1 as (
    select * from queue order by turn asc
), t2 as (
    select person_id, sum(weight) over (order by turn) as cum_sum
    from t1
)

select q.person_name
from queue as q
left join t2
on q.person_id = t2.person_id
where cum_sum <= 1000
order by cum_sum desc
limit 1
