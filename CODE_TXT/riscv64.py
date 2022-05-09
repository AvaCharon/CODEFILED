'''
预编译文件experiment.i
riscv64-unknown-elf-gcc -E experiment.c -o experiment.i

查看预编译文件
gvim experiment.i &

汇编文件experiment.s
riscv64-unknown-elf-gcc -S experiment.i -o experiment.s

查看汇编文件
gvim experiment.s &

得到elf文件experiment.o
riscv64-unknown-elf-gcc -c experiment.s -o experiment.o

查看机器码
riscv64-unknown-elf-objdump -D experiment.o

生成可执行文件
riscv64-unknown-elf-gcc experiment.c -o experiment

执行可执行文件
spike pk experiment

反汇编
riscv64-unknown-elf-objdump -S experiment > experiment.txt

查看反汇编文件
gvim experiment.txt &
'''