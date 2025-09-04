select Product.product_name, Sales.year, Sales.price
from Sales
inner join Product
where Product.product_id = Sales.product_id;