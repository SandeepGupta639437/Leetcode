SELECT
    DISTINCT player_id ,
    MIN(event_date) OVER(PARTITION by player_id) AS first_login 
FROM Activity