-- Write your PostgreSQL query statement below
with t1 as (
    select product_id, sum(units) as items_sold
    from unitsSold
    group by product_id
), t2 as (
    select prices.product_id, sum(unitsSold.units * prices.price) as total_price
    from prices
    join unitsSold
    on prices.product_id = unitsSold.product_id
    group by prices.product_id, unitsSold.purchase_date, prices.start_date, prices.end_date
    having unitsSold.purchase_date >= prices.start_date and unitsSold.purchase_date <= prices.end_date
), t3 as (
    select product_id, sum(total_price) as total
    from t2
    group by product_id
), t4 as (
    select t1.product_id, coalesce(round(t3.total / t1.items_sold, 2), 0) as average_price
    from t1
    left join t3
    on t1.product_id = t3.product_id
)

select distinct prices.product_id, coalesce(t4.average_price, 0) as average_price
from prices
left join t4
on prices.product_id = t4.product_id;
