#include <stdio.h>

// 本例演示了 main 函数的主要用法及其参数的意义

// main函数的三个参数
// 1. argc，argument count的简称，即命令行的参数个数
//    shell中调用程序命令本身的名字算一个，所以一般地， argc >= 1
//    (如使用 `./a.out` 调用，则argv[0]为 `./a.out`)
// 2. char **argv，arguement vector，参数名，第一个为程序名
//    需要注意的是，参数默认以空格为分隔，所有参数有空格符号时，需要用引号（单引号/双引号），
//    或者用 "\ " 来转义
// 3. char **envp，enviroment of program，程度环境变量,
//    但似乎这不是 POSIX 标准？
//    具体的讨论参见 [**envp portability](http://stackoverflow.com/questions/10321435/is-char-envp-as-a-third-argument-to-main-portable)
//    还可以使用 getenv() 和 extern char **environ
//    getenv 是 C标准
//    extern char **environ是 POSIX标准


extern char **environ;

int main(int argc, char **argv, char **envp) {
	
	printf("argc = %d\n", argc);
	printf("\nshow **argv\n");
	for(int i=0; i< argc; i++) {
		printf("%d : %s\n", i, argv[i]);
	}
	
	printf("\nshow **envp\n");
	for(int j=0; ;j++) {
		if(envp[j]) {
			printf("%d : %s\n", j, envp[j]);
		} else {
			break;
		}
	}

	printf("\nshow **environ\n");
	for(int ei=0; ;ei++) {
		if(environ[ei]) {
			printf("%d : %s\n", ei, environ[ei]);
		} else {
			break;
		}
	}
}