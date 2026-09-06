SELECT 
    ROUND(
        COUNT(DISTINCT CASE 
            WHEN a.event_date = f.first_date + INTERVAL 1 DAY 
            THEN a.player_id 
        END) 
        / COUNT(DISTINCT f.player_id),
        2
    ) AS fraction
FROM Activity a
JOIN (
    SELECT 
        player_id,
        MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
) f
ON a.player_id = f.player_id; 