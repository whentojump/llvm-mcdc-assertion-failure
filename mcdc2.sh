#!/bin/bash

# set -x


cat << EOF
Double check LLVM version:

EOF
clang --version
echo
read -n 1 -s -r -p "Press any key to continue..."
echo
echo

opt="-O0"
bin=main
sources=main.c

rm -f a.out $bin *.profdata *.profraw *.gcda *.gcno *.gcov

clang $opt -fprofile-instr-generate -fcoverage-mapping -fcoverage-mcdc $sources -o $bin

LLVM_PROFILE_FILE="$bin.profraw" ./$bin
llvm-profdata merge $bin.profraw -o $bin.profdata
llvm-cov show --show-mcdc $bin -instr-profile $bin.profdata # -output-dir=./garbage
