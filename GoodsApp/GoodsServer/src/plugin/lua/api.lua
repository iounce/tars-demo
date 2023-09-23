package.path = package.path .. ";/data/tars/tarsnode-data/GoodsApp.GoodsServer/bin/?.lua"

local yaml = require("YAMLParserLite")

Api = {}

function Api:new(cmd)
    local obj = {}
    
    obj.cmd = cmd
    obj.file_path = "/data/tars/tarsnode-data/GoodsApp.GoodsServer/bin/" .. string.format("protocol_%d.yaml", obj.cmd)
    obj.protocol = ""
    print(obj.cmd)
    print(obj.file_path)

    setmetatable(obj, self)
    self.__index = self

    return obj
end

function Api:load_protocol()
    local file = io.open(self.file_path, "r")
    self.protocol = yaml.parse(file:read("*a"))
    print(self.protocol['Request1'])
    file:close()
    return true
end

function Api:get_groups()
    local result = "["
    local grp_count = #self.protocol.Groups
    for i = 1, grp_count do
        local group = string.format("\"%s\"", self.protocol.Groups[i])
        result = result..group
        if (i ~= grp_count)
        then
            result = result..","
        end
    end
    result = result.."]"
    return result
end

function Api:get_requests(grp_name)
    local group = {}
    
    if (grp_name == "Group1")
    then
        group = self.protocol.Group1
    elseif (grp_name == "Group2")
    then
        group = self.protocol.Group2
    else
        group = {}
    end

    local result = "["
    local grp_count = #group

    for i = 1, grp_count do
        group = string.format("\"%s\"", group[i])
        result = result .. group
        if (i ~= grp_count) then
            result = result .. ","
        end
    end

    result = result .. "]"

    return result
end
