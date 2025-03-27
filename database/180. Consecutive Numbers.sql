-- Write your PostgreSQL query statement below
select distinct num as ConsecutiveNums
from (
    select num,
    lag(num) over (order by id) as prev,
    lead(num) over (order by id) as next
    from logs
)
where num = prev and num = next
