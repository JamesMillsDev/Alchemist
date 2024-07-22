properties = require("properties")

local current_dir=io.popen"cd":read"*l"

local project_props = properties.read(current_dir .. "\\project.properties")
local outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

ws = require("workspace")
sample = require("sample")
prj = require("project")

ws.generate(project_props)
prj.generate(outputdir, project_props)
sample.generate(outputdir, project_props)