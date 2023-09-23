function data2string(data)
    if type(data) == 'table' then
        return table2string(data)
    elseif type(data) == 'string' then
        return "\""..data.."\""
    else
        return tostring(data)
    end
end

function string2table(s)
    if s == nil or type(s) ~= "string" then
        return nil
    end
    
    return load("return "..s)()
end

function table2string(data)
    if data == nil or type(data) ~= "table" then
        return nil
    end

    local result = "{";

    local i = 1
    local j = 1
    local item = ""
    
    for k, v in pairs(data) do
        local sepr = ","

        if i == 1 then
            sepr = ""
        end

        if k == i then
            result = result..sepr..data2string(v)
        else
            if type(k) == 'number' or type(k) == 'string' then
                result = result..sepr..'['..data2string(k).."]="..data2string(v)
            else
                if type(k) == 'userdata' then
                    result = result..sepr.."*s"..table2string(getmetatable(k)).."*e".."="..data2string(v)
                else
                    result = result..sepr..k.."="..data2string(v)
                end
            end
        end

        i = i + 1
    end

    result = result.."}"

    return result
end

function table2jsonstring(data)
    if data == nil or type(data) ~= "table" then
        return nil
    end

    local result = "{";

    local i = 1
    local j = 1
    local item = ""

    for k, v in pairs(data) do
        local sepr = ","

        if i == 1 then
            sepr = ""
        end

        if k == i then
            result = result .. sepr .. data2string(v)
        else
            if type(k) == 'number' or type(k) == 'string' then
                result = result .. sepr ..  data2string(k) .. ":" .. data2string(v)
            else
                if type(k) == 'userdata' then
                    result = result .. sepr .. "*s" .. table2string(getmetatable(k)) .. "*e" .. ":" .. data2string(v)
                else
                    result = result .. sepr .. k .. ":" .. data2string(v)
                end
            end
        end

        i = i + 1
    end

    result = result .. "}"

    return result
end

-- local t1 = {
--     A = 1,
--     B = {
--         1,
--         b = "strBb",
--         {
--             x = 'strB2x',
--             y = 0.1
--         }
--     }
-- }

-- local str1 = table2string(t1)
-- print(type(str1), str1)

-- local t2 = string2table(str1)
-- print(t2)
-- print(t2['B'][2].x)

-- local d = {["name"] = "Jack", ["age"] = 10}
-- print(table2string(d))
-- print(table2jsonstring(d))