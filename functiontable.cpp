#include "functiontable.h"

const FT function_table[] = {
    {sin, "sin"},
    {cos, "cos"},
    {exp, "e"},
    {log, "ln"},
    {tan, "tg"},
    {sqrt, "sqrt"},
};

funcptr_t search_function(const string& name) {
    int size = sizeof(function_table) / sizeof(FT);

    for (int i = 0; i < size; ++i) {
        if (name == function_table[i].name) {
            return function_table[i].function;
        }
    }

    return NULL;
}
