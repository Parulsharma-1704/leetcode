# Write your MySQL query statement below
select w2.id from Weather w
join Weather w2
-- on w.recordDate +1=w2.recordDate
on w2.recordDate = DATE_ADD(w.recordDate, INTERVAL 1 DAY)
where w2.temperature>w.temperature;