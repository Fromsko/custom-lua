#include <iostream>
#include "iclient/iclient.h"

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "cJSON.h"
}

using namespace ic::client;

void test_http_get()
{
    Request request("http://httpbin.org/ip");
    Response response = request.Perform();

    if (response.ok())
    {
        // status
        printf("%s\n", to_string(response.status()));
        // Header
        printf("------ Headers -------------------------------\n");
        auto &headers = response.headers();
        for (auto &header : headers)
        {
            printf("%s: %s\n", header.first.c_str(), header.second.c_str());
        }
        // Data
        printf("------ Body ----------------------------------\n");
        printf("%s\n", response.data().c_str());
        printf("---------------------------------------------\n");
    }
    printf("\n\n");
}

int main()
{
    lua_State *L = luaL_newstate(); // 创建 Lua 状态
    luaL_openlibs(L);               // 打开 Lua 库

    if (luaL_loadfile(L, "test/main.lua")) // 执行文件
    {
        const char *error = lua_tostring(L, -1);
        printf("Lua call error: %s", error);
        return -1;
    }

    if (lua_pcall(L, 0, 0, 0)) // 处理栈堆错误
    {
        const char *error = lua_tostring(L, -1);
        printf("Lua call error: %s", error);
        return -1;
    }

    lua_close(L); // 关闭 Lua 状态
    return 0;
}
