-- 1. 문자열 자르기 : SUBSTR
SELECT SUBSTR(PRODUCT_CODE, 1, 2) CATEGORY, COUNT(*) PRODUCTS
FROM PRODUCT
GROUP BY SUBSTR(PRODUCT_CODE, 1, 2)
ORDER BY 1;