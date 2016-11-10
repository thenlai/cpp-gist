# 手动内存分配

void* malloc(int bytesCount);
void* calloc(int counts, int unitSize);
void* realloc(void* p, int bytesCount);

void free(void* p);

C++ 特有的方法：

new
delete