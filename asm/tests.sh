make

for file in `ls test`
do
    rm -f test/$file.cor
    if  [ "$file" == *.cor ]
    then
        continue
    fi
    echo "Testing $file"
    ./asm test/$file > log_$file.txt
    status=$?
    echo "|=> Exit status: $status"
    if [ $status -ne 0 ]
    then
        continue
    fi
    hexdump -C test/$file.cor >> log_$file.txt
    rm -f test/$file.cor
done