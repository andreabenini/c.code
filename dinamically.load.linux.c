// Dinamically load an external .so file and execute a function from it as well

typedef int (*some_func)(char *param);

void *myso = dlopen("/path/to/my.so", RTLD_NOW);
some_func *func = dlsym(myso, "function_name_to_fetch");
func("foo");
dlclose(myso);
