# Write your MySQL query statement below
-- select firstName , lastName , city , state  from Person p LEFT JOIN Address a on (p.personId = a.personId)



SELECT P.firstName, P.lastName, A.city, A.state
FROM Person P
LEFT JOIN Address A USING (personId)