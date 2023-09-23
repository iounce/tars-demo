--package.path = package.path..";./?.lua;api.lua;func.lua;helper.lua;"
--print(package.path)
--print('.......................')

cur_path='/data/tars/tarsnode-data/GoodsApp.GoodsServer/bin'
package.path = package.path..";"..cur_path.."/?.lua;"

require("api")
require("func")
require("helper")

local api = Api:new(100)

function load_protocol()
    return api:load_protocol()
end

function get_groups()
    return api:get_groups()
end

function get_requests(grp_name)
    return api:get_requests(grp_name)
end

local function pack_request_100000(client_req, dataset)
    local trade_req = string2table(client_req)

    local req = {}

    req["func_no"] = 100000
    req["section_id"] = trade_req['IoSectionId']
    req["goods_name"] = trade_req['IoGoodsName']

    return table2jsonstring(req)
end

local function pack_request_100001(client_req, dataset)
    print('pack: ', client_req)
    local trade_req = string2table(client_req)

    local goods_id = trade_req['IoGoodsId']
    if #goods_id == 0 then
        goods_id = dataset["goods_id"]
    end

    local req = {}

    req["func_no"] = 100001
    req["section_id"] = trade_req['IoSectionId']
    req["goods_id"] = trade_req['IoGoodsId']

    return table2jsonstring(req)
end

function pack_request(req_name, client_req, dataset)
    local result = ""

    if req_name == "Request1" then
        result = pack_request_100000(client_req, dataset)
    elseif req_name == "Request2" then
        result = pack_request_100001(client_req, dataset)
    end

    return result
end
