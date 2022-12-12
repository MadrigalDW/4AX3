@ECHO off

set file=%1
IF NOT %1.==. GOTO has

set /p file=Enter file name:

:has
  g++ -I "C:\Program Files\eigen3" %file%.cpp -o %file%

:End