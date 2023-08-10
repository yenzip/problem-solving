SELECT PRODUCT_CODE, SUM(PRICE * SALES_AMOUNT) SALES
FROM PRODUCT P JOIN OFFLINE_SALE O ON P.PRODUCT_ID = O.PRODUCT_ID
GROUP BY PRODUCT_CODE
ORDER BY 2 DESC, 1;