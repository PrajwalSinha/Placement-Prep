# Write your MySQL query statement below
select customer_id ,count(customer_id) as count_no_trans from Visits WHERE  NOT EXISTS (SELECT visit_id
                   FROM   Transactions t
                   WHERE  t.visit_id = Visits.visit_id) group by customer_id