-- Write your PostgreSQL query statement below
with t1 as (
    select *
    from products
    where change_date <= '2019-08-16'
    order by change_date desc
), t2 as (
    select distinct on (product_id) *
    from t1
    ORDER BY product_id, change_date DESC
), t3 as (
    select distinct on (product_id) p.product_id, coalesce(t2.new_price, 10) as price
    from products as p left join t2
    on p.product_id = t2.product_id
)

select * from t3;
