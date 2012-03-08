
       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 BUF       PIC X(10).
       01 IDX       PIC S9(9).
       01 STR.
           03 DD    PIC 9(2).
           03       PIC X.
           03 MM    PIC 9(2).
           03       PIC X.
           03 YY    PIC 9(4).
       01 YMD.
           03 Y     PIC 9(4).
           03 M     PIC 9(2).
           03 D     PIC 9(2).
       01 NUM       REDEFINES YMD   PIC 9(8).

       PROCEDURE DIVISION.
           ACCEPT STR
           MOVE YY TO Y
           MOVE MM TO M
           MOVE DD TO D
           ACCEPT BUF
           MOVE BUF TO IDX
           ADD FUNCTION INTEGER-OF-DATE(NUM) TO IDX
           MOVE FUNCTION DATE-OF-INTEGER(IDX) TO YMD
           MOVE Y TO YY
           MOVE M TO MM
           MOVE D TO DD
           DISPLAY STR
           STOP RUN.

