# set -euo pipefail

echo $bins$1

clang++ -std=c++23 $(pwd)/$1.cpp -o $bins$1.exe

echo "yo"

$bins$1.exe
# ok