# 依赖关系
	# 依赖方法
mycode:mycode.o  
	gcc mycode.o -o mycode
mycode.o:mycode.s
	gcc -c mycode.s -o mycode.o
mycode.s:mycode.i
	gcc -S mycode.i -o mycode.s
mycode.i:mycode.c
	gcc -E mycode.c -o mycode.i


.PHONY:
clean:
	rm -f *.i *.s *.o 
