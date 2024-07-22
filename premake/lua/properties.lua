require("string-utils")
ids = require("ids")

local props = {
    name = "",
    dependencies_dir = "",
    sample_name = "",
    language_version = "",
    disabled_warnings = {},
    libs = {}
}

function props:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function props.read(filepath)
    local new_props = props:new{
        name = "",
        dependencies_dir = "",
        sample_name = "",
        language_version = "",
        disabled_warnings = {},
        libs = {}
    }

    local file = assert(io.open(filepath, "r"))

    new_props:get_name(file)
    new_props:get_dependencies_dir(file)
    new_props:get_sample_name(file)
    new_props:get_language_version(file)
    new_props:get_disabled_warnings(file)
    new_props:get_libs(file)

    file:close()

    return new_props
end

function props:get_name(file)
    line = assert(file:read())

    if contains(line, ids.name) then
        self.name = value_from(line, ids.name)
    end
end

function props:get_dependencies_dir(file)
    line = assert(file:read())

    if contains(line, ids.dependencies_dir) then
        self.dependencies_dir = value_from(line, ids.dependencies_dir)
    end
end

function props:get_sample_name(file)
    line = assert(file:read())

    if contains(line, ids.sample_name) then
        self.sample_name = value_from(line, ids.sample_name)
    end
end

function props:get_language_version(file)
    line = assert(file:read())

    if contains(line, ids.language_version) then
        self.language_version = value_from(line, ids.language_version)
    end
end

function props:get_disabled_warnings(file)
    line = assert(file:read())

    if contains(line, ids.disabled_warnings) then
        line = value_from_len(line, ids.disabled_warnings, 3, 2)

        line = split(line, ',')

        for l, v in pairs(line) do
            self.disabled_warnings[l - 1] = no_quotes(v)
        end
    end
end

function props:get_libs(file)
    line = assert(file:read())

    if contains(line, ids.libs) then
        line = value_from_len(line, ids.libs, 3, 2)

        line = split(line, ',')

        for l, v in pairs(line) do
            self.libs[l - 1] = no_quotes(v)
        end
    end
end

return props