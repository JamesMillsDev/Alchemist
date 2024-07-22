local prj = {}

function prj.generate(outputdir, properties)
    project(properties.name)
        location "%{prj.name}"
        kind "SharedLib"

        language "C++"
        cppdialect "C++20"

        targetdir("$(SolutionDir)" ..properties.dependencies_dir .. "\\lib")
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

        for l, module in pairs(properties.libs) do
            links(module .. ".lib")
        end

        postbuildcommands
        {
            ("move /y \"$(SolutionDir)" .. properties.dependencies_dir .. "\\lib\\" .. properties.name .. ".dll\" \"$(SolutionDir)" ..properties.dependencies_dir .. "\\lib\\dll\\" .. properties.name .. ".dll\"")
        }

        defines("DLL_EXPORT")

        filter "configurations:Debug"
            postbuildcommands
            { 
                ("move /y \"$(SolutionDir)" .. properties.dependencies_dir .. "\\lib\\" .. properties.name .. ".pdb\" \"$(SolutionDir)" ..properties.dependencies_dir .. "\\lib\\dll\\" .. properties.name .. ".pdb\"") 
            }

end

return prj