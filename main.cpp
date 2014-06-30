#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "plugin.h"

typedef int (* mainfunc_t)(int, char **);

int main(int argc, char *argv[])
{
    void * handle = dlopen("./libplugin.so", RTLD_LAZY);

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

    int ret = (*plugin_main)(argc, argv);

    dlclose(handle);
    // try triggering the Qt problem already
    sleep(3); // seconds
    return ret;
}
