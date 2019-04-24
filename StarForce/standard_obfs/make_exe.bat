@echo off

for %%f in (*.c) do for /F "tokens=1 delims=1." %%p in ("%%f") do (
START gcc %%f -o %%p
echo %%f is built to exe
)
pause>nul