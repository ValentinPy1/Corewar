ls
valgrind ./corewar -dump 10000 -n 1 -a f1 42.cor -a b33 abel.cor
valgrind ./corewar -dump 10000 -n 1 -a f1 pdd.cor -a b33 abel.cor
valgrind ./corewar -dump 10000 -n 1 -a f1 champ/assembled/pdd.cor -a b33 champ/assembled/abel.cor
clear
valgrind ./corewar -dump 10000 -n 1 -a f1 champ/assembled/pdd.cor -a b33 champ/assembled/abel.cor
make debug && valgrind ./corewar -dump 10000 -n 1 -a f1 champ/assembled/pdd.cor -a b33 champ/assembled/abel.cor
ls
exit
