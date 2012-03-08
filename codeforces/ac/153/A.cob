       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 A        PIC 9(10)   VALUE ZEROES.
       01 B        PIC 9(10)   VALUE ZEROES.
       01 C        PIC z(10).

       PROCEDURE DIVISION.
           ACCEPT A
           ACCEPT B
           ADD A TO B
           MOVE B TO C
           DISPLAY C
           STOP RUN.
