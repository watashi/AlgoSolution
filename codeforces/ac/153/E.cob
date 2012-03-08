       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 BUF       PIC X(10).
       01 N         PIC S9(9).
       01 I         PIC S9(9).
       01 J         PIC S9(9).
       01 DX        PIC S9(9)v9(9).
       01 DY        PIC S9(9)v9(9).
       01 DD        PIC S9(9)v9(9).
       01 .
           03 X     PIC S9(9)   OCCURS 100 TIMES.
           03 Y     PIC S9(9)   OCCURS 100 TIMES.

       PROCEDURE DIVISION.
           ACCEPT BUF
           MOVE BUF TO N
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > N
               ACCEPT BUF
               MOVE BUF TO X(I)
               ACCEPT BUF
               MOVE BUF TO Y(I)
           END-PERFORM

           MOVE 0 TO DD
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > N
               PERFORM VARYING J FROM 1 BY 1 UNTIL J EQUAL I
                   MOVE X(I) TO DX
                   SUBTRACT X(J) FROM DX
                   MULTIPLY DX BY DX GIVING DX
                   MOVE Y(I) TO DY
                   SUBTRACT Y(J) FROM DY
                   MULTIPLY DY BY DY GIVING DY
                   ADD DX TO DY
                   MOVE FUNCTION SQRT(DY) TO DX
                   IF DX > DD
                       MOVE DX TO DD
                   END-IF
               END-PERFORM
           END-PERFORM
           DISPLAY DD
           STOP RUN.

