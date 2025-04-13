[1934. Confirmation Rate](https://leetcode.com/problems/confirmation-rate/ "1934. Confirmation Rate") <br>
`t1` CTE represents each `user_id` with their total count of 'confirmed' records. `t2` CTE represents each `user_id` and their total count of occurences in the database. `t3` CTE represents each `user_id` and their `confirmation_rate` but it does not contain all the `user_id`s in the `signup` table, so we need to join it with the `signup` table with left join and use `coalesce` to replace null values with zero.<br>

[1251. Average Selling Price](https://leetcode.com/problems/average-selling-price/ "1251. Average Selling Price") <br>
`t1` CTE represents each `product` with their total count of `items_sold`, this helps us know how many items are sold of each item to use it later to calculate the average price of this item. `t2` CTE represents each `product` with their total amount of money spent on this item according to when was this item sold and its price on that date, the problem with this CTE is that it does not give us the total price for each item in just one row, so we need another CTE `t3`. `t3` CTE represents each `product` and the total amount of money spent on it over all time. `t4` CTE represents each `product` with their average price, `average_price`, but it does not contain all the `product_id`s in the `prices` table, so we need to join it with the `prices` table with left join and use `coalesce` to replace null values with zero. <br>

[1211. Queries Quality and Percentage](https://leetcode.com/problems/queries-quality-and-percentage/ "1211. Queries Quality and Percentage") <br>
`t1` CTE represents each query with the sum of all its `(rating / position)` values. `t2` CTE represents each query and their total count of occurences in the database. `t3` CTE represents each query and the sum of all its poor rated records. `t4` CTE represents each query with their quality values. `t5` CTE represents each query with their poor_query_percentage values. <br>

[1211. Queries Quality and Percentage](https://leetcode.com/problems/queries-quality-and-percentage/ "1211. Queries Quality and Percentage") <br>
This is another solution to the problem above as I forgot to use the `avg` function in it. In this solution we can just select each `query_name` and use the `avg` function with both the rating and the position directly instead of making CTEs (`t1`, `t2`) and then use the `sum` function with `case` to get the total sum of all `rating`s less than one and multiply them by one hundred to get the `poor_query_percentage` column. <br>

[1193. Monthly Transactions I](https://leetcode.com/problems/monthly-transactions-i/description/ "1193. Monthly Transactions I") <br>
To extract only the month and the year in psql, you need to use the `to_char()` function and specify its format, which is `YYYY-MM`. The country column has nothing to do about except for the fact that there exists null countries you have to handle with the `coalesce()` function. The rest are regular `sum()` functions with some `case when` conditions. The most important part here is that in order to correctly parse records in the same month is to group by the month after formatting which is after applying the `to_char()` part on the dates. <br>

[1789. Primary Department for Each Employee](https://leetcode.com/problems/primary-department-for-each-employee/description/ "1789. Primary Department for Each Employee") <br>
First we get all the employees and department ids with primary flag set to yes in `t1` CTE. In `t2` CTE, we get all the employees with only one occurence in the table, and then in `t3` CTE, we join them on the `employees` table to get their department id. <br>

[180. Consecutive Numbers](https://leetcode.com/problems/consecutive-numbers/description/ "180. Consecutive Numbers") <br>
Using `lag` and `lead` window functions, we can get the row before and after the current row, then we check if all the three values are equal and add them to the answer. <br>

[1164. Product Price at a Given Date](https://leetcode.com/problems/product-price-at-a-given-date/ "1164. Product Price at a Given Date") <br>
`t1` CTE represents rows with dates before `2019-08-16`. `t2` CTE represents rows with the latest date just before `2019-08-16` using `distinct on (product_id)`. `t3` CTE, which is the answer, joins the products table with `t2` CTE to `coalesce` non-existing products in it. <br>

[1204. Last Person to Fit in the Bus](https://leetcode.com/problems/last-person-to-fit-in-the-bus/description/ "1204. Last Person to Fit in the Bus") <br>
`t1` CTE is just the input ordered by turn. `t2` CTE calculates the cumalative sum over all the rows and put them in a new column called `cum_sum`, this is done using `sum(weight) over (order by turn)` part. Finally, the answer will be the join result of `queue` and `t2` tables where `cum_sum >= 1000` and to get the right answer, we will sort and take only one row (limit 1).
