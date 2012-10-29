       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 POS       PIC 9(10)    VALUE ZEROS.
       01 ORD       PIC 9(10)    VALUE ZEROS.
       01 NUM       PIC 9(10)    VALUE ZEROS.
       01 TMP       PIC 9(10)    VALUE ZEROS.
       01 BUF       PIC X(10)    VALUE SPACES.
       01 STR.
           03 CHR   PIC X        VALUE SPACES   OCCURS 10 TIMES.

       PROCEDURE DIVISION.
           ACCEPT STR
           ACCEPT BUF
           MOVE BUF TO NUM
           PERFORM VARYING POS FROM 1 BY 1 UNTIL POS > 10
               IF CHR(POS) NOT EQUAL ' '
                   MOVE FUNCTION ORD(CHR(POS)) TO ORD
                   SUBTRACT FUNCTION ORD('A') FROM ORD
                   ADD NUM TO ORD
                   DIVIDE ORD BY 26 GIVING TMP REMAINDER ORD
                   ADD FUNCTION ORD('A') TO ORD
                   MOVE FUNCTION CHAR(ORD) TO CHR(POS)
               END-IF
           END-PERFORM
           DISPLAY STR
           STOP RUN.

