local sample = {}

function sample.generate(outputdir, properties)
    project(properties.sample_name)
        location "%{prj.name}"
        kind "ConsoleApp"

        language "C++"
        cppdialect "C++20"

        targetdir("$(SolutionDir)Builds\\%{prj.name}\\" .. outputdir)
        objdir("$(SolutionDir)\\Intermediate\\%{prj.name}\\" .. outputdir)

        files 
        {
            "%{prj.location}\\**.h", 
            "%{prj.location}\\**.cpp", 
            "%{prj.location}\\**.png", 
            "%{prj.location}\\**.tiff",
            "%{prj.location}\\**.ttf"
        }

        includedirs 
        {
            "%{prj.location}\\include", 
            ("$(SolutionDir)" .. properties.dependencies_dir .. "\\include\\"),
            ("$(SolutionDir)" .. properties.name .. "\\include\\")
        }

        for l, v in pairs(properties.disabled_warnings) do
            disablewarnings {v}
        end

        libdirs("$(SolutionDir)" .. properties.dependencies_dir .. "\\lib\\")

        links(properties.name .. ".lib")

        for l, module in pairs(properties.libs) do
            links(module .. ".lib")
        end

        postbuildcommands("xcopy /Y \"$(SolutionDir)" ..properties.dependencies_dir .. "\\lib\\dll\\\" \"$(OutDir)\"")

        dependson(properties.name)

end

return sample
