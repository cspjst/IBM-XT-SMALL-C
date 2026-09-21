@echo off
echo running tests...
type newline.txt > t.csv
echo 16K file
test t.dat 0, 16 >> t.csv
test t.dat 1, 16 >> t.csv
test t.dat 2, 16 >> t.csv
test t.dat 4, 16 >> t.csv
test t.dat 8, 16 >> t.csv
test t.dat 16, 16 >> t.csv
test t.dat 24, 16 >> t.csv

type newline.txt >> t.csv
echo 32K file
test t.dat 0, 32 >> t.csv
test t.dat 1, 32 >> t.csv
test t.dat 2, 32 >> t.csv
test t.dat 4, 32 >> t.csv
test t.dat 8, 32 >> t.csv
test t.dat 16, 32 >> t.csv
test t.dat 24, 32 >> t.csv

type newline.txt >> t.csv
echo 64K file
test t.dat 0, 64 >> t.csv
test t.dat 1, 64 >> t.csv
test t.dat 2, 64 >> t.csv
test t.dat 4, 64 >> t.csv
test t.dat 8, 64 >> t.csv
test t.dat 16, 64 >> t.csv
test t.dat 24, 64 >> t.csv

type newline.txt >> t.csv
echo 128K file
test t.dat 0, 128 >> t.csv
test t.dat 1, 128 >> t.csv
test t.dat 2, 128 >> t.csv
test t.dat 4, 128 >> t.csv
test t.dat 8, 128 >> t.csv
test t.dat 16, 128 >> t.csv
test t.dat 24, 128 >> t.csv

type newline.txt >> t.csv
echo 256K file
test t.dat 0, 256 >> t.csv
test t.dat 1, 256 >> t.csv
test t.dat 2, 256 >> t.csv
test t.dat 4, 256 >> t.csv
test t.dat 8, 256 >> t.csv
test t.dat 16, 256 >> t.csv
test t.dat 24, 256 >> t.csv
