#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "plugin.h"

typedef int (* mainfunc_t)(int, char **);
void * handle;

mainfunc_t get_plugin_main()
{
    handle = dlopen("./libplugin.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();    /* Clear any existing error */

    mainfunc_t plugin_main = (mainfunc_t) dlsym(handle, "_Z11plugin_mainiPPc");
    char * error;
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    return plugin_main;
}

void sleeper()
{
    sleep(3); // seconds
}

void cleanup()
{
    dlclose(handle);
    // try triggering the Qt problem already
    sleeper();
}

int main(int argc, char *argv[])
{
    mainfunc_t plugin_main = get_plugin_main();
    int ret = (*plugin_main)(argc, argv);
    cleanup();
    return ret;
}
