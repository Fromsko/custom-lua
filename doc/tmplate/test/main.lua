import "os"
import "cjson"

local doc = [[
--------------------------------------------
欢迎使用 魔改版 Lua
> 基于 Lua 5.4 构建

作者: Fromsko
站点: https://github.com/fromsko/custom-lua

功能:
    - import
    - cjson
    - sknet
--------------------------------------------
]]

local CjsonTest = function()
    print("[INFO] 准备进行 Cjson 测试")
    local json_obj = '{"name": "Alice", "age": 30}'
    print("[INFO] 数据解析 local resp = " .. json_obj)
    local resp = cjson.decode(json_obj)
    print("[INFO] 获取 resp.name => " .. resp.name)
end

print(doc)
print(CjsonTest())
