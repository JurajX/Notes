/* create an empty table */
CREATE TABLE tbl_name (
    col1 CHAR,
    col2 VARCHAR (n),       /* hold variable lenght string of max length n */

    col3 DECIMAL (p,s),     /* hold decimal number; p/s is #ofdigits before/after dec separator */
    col4 INT,               /* SMALLINT, BIGINT */
    col5 DOUBLE PRECISION   /* FLOAT, REAL */

    col6 DATE               /* TIME, TIMESTAMP */
    col7 INTERVAL
    col8 BOOLEAN
);

/* delete tbl_name with all it's stored values */
DROP TABLE tbl_name;

/* insert record into tbl_name with values in order */
INSERT INTO tbl_name VALUES (val1, ..., val8);
/* insert record into tbl_name with values in arbitrarily defined order */
INSERT INTO tbl_name (col5, col1, ...) VALUES (val5, val1, ...);

/* r: all records with all columns from tbl_name */
SELECT * FROM tbl_name;
/* r: all records with only col1 and col5 from tbl_name */
SELECT col1, col5 FROM tbl_name;
/* r: all records from tbl_name with col1 being equal to my_val1 or my_val2 */
SELECT * FROM tbl_name WHERE col1 = my_val1 OR col1 = my_val2;
/* r: all records from tbl_name with cond ordered by values in col4*/
SELECT * FROM tbl_name WHERE col4 < my_val3 ORDER BY col4;          /* ascending order */
SELECT * FROM tbl_name WHERE col4 < my_val3 ORDER BY col4 DESC;     /* descending order */
SELECT * FROM tbl_name WHERE col4 < my_val3 ORDER BY col4, col5;    /* first by col4, then by col5 */

/* set col2 to my_val for all records in tbl_name */
UPDATE tbl_name SET col2 = my_val;
/* set col2 to my_val for all records with col1 = my_val1 */
UPDATE tbl_name SET col2 = my_val WHERE col1 = my_val1;

/* delete all records from tbl_name */
DELETE FROM tbl_name;
/* delete all records with col1 = my_val1 */
DELETE FROM tbl_name WHERE col1 = my_val1;

/* shows info about the table */
DESCRIBE tbl_name;
