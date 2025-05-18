select request_at as Day, ROUND(sum(status LIKE 'cancelled%')/count(*), 2) as 'Cancellation Rate' 
from Trips where (client_id,driver_id) in 
(select U1.users_id, U2.users_id from Users U1 JOIN Users U2 where U1.banned = 'No' and U2.banned = 'No')
and request_at BETWEEN '2013-10-01' and '2013-10-03'
group by request_at;