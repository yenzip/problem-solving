/* 0 ~ 23까지 임시 테이블 */
WITH RECURSIVE HH24 AS (
    SELECT 0 AS HOUR
    UNION ALL
    SELECT HOUR + 1 FROM HH24
    WHERE HOUR < 23
)

SELECT HOUR, COUNT(DATETIME)
FROM HH24 LEFT JOIN ANIMAL_OUTS AO ON HH24.HOUR = HOUR(DATETIME)
GROUP BY HOUR
ORDER BY HOUR;
