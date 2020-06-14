# how to use
# ./asm_tester.sh {test/???.c} {arg1} {arg2}

make re
gcc -fPIE test/$1.c -fPIE libasm.a -fPIE
make fclean
echo "\nresult"
echo "----------------------"
./a.out $2 $3
echo "----------------------"
rm -f ./a.out
