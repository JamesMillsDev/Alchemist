local ws = {}

function ws.generate(project_props)
	workspace (project_props.name)
    architecture "x64"

    configurations
	{
		"Debug",
		"Release"
	}

	startproject (project_props.sample_name)
end

return ws