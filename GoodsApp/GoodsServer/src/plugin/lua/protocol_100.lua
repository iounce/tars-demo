require("./api")
require("./func")
require("./helper")

local api = Api:new(100)

local function load_protocol()
    return api:load_protocol()
end

local function get_groups()
    return api:get_groups()
end

local function get_requests(grp_name)
    return api:get_requests(grp_name)
end

local function pack_request_100000(client_req, dataset)
    local trade_req = string2table(client_req)
    
    local req = {}

    req["section_id"] = trade_req['IoSectionId']
    req["goods_name"] = trade_req['IoGoodsName']

    return table2jsonstring(req)
end

local function pack_request_100001(client_req, dataset)
    local trade_req = string2table(client_req)

    local goods_id = trade_req['IoGoodsId']
    if #goods_id == 0
    then
        goods_id = dataset["goods_id"]
    end

    req = {}
    req["section_id"] = trade_req['IoSectionId']
    req["goods_id"] = trade_req['IoGoodsId']

    return table2jsonstring(req)
end

local function pack_request(req_name, client_req, dataset)
    local result = ""

    if req_name == "Request1" then
        result = pack_request_100000(client_req, dataset)
    elseif req_name == "Request2" then
        result = pack_request_100001(client_req, dataset)
    end

    return result
end