nasm -felf64 $1.asm && gcc -O3 $1.o && time ./a.out
