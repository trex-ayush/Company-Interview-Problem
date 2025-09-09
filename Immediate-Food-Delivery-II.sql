SELECT ROUND (AVG (IF(orderDate = deliveryDate, 1, 0)), 4) * 100 AS immediate_percentage
FROM 
(
    SELECT MIN(order_date) AS orderDate,
    MIN(customer_pref_delivery_date) AS deliveryDate
    FROM Delivery 
    WHERE order_date <= customer_pref_delivery_date
    GROUP BY customer_id
) AS newTable

-- select round(sum(if(order_date = customer_pref_delivery_date, 1 , 0))*100/count(distinct customer_id),2) as immediate_percentage 
-- from delivery
-- where (customer_id, order_date ) in
--     (
--         select customer_id, min(order_date) as first_order_date
--         from delivery
--         group by customer_id
--     )