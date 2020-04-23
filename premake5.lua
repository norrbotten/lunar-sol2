
 -- this can be either CLIENT or SERVER
local realm = "SERVER"

-- set this to true if youre compiling for windows systems
local is_windows = false

-- this only has an effect on WINDOWS builds
local arch = "x32" -- x32 for 32-bit, x64 for 64-bit

-- name of your module
local module_name = "sol2-module"

-- optional install directory for the 'install' action
local install_dir = "/home/gmod_exp01/serverfiles/garrysmod/lua/bin/" -- should end with /

function getModulePrefix()
    return (realm == "SERVER") and "gmsv" or "gmcl"
end

workspace ("lunar-" .. module_name)
    location "makefiles"

    architecture "x32"
    language "C++"
    cppdialect "C++17"

    targetdir "build/bin"
    objdir "build/obj"

    targetname (module_name)
    targetprefix (getModulePrefix() .. "_")
    targetsuffix "_linux"
    targetextension ".dll"

    configurations { "debug", "release" }

    filter { "configurations:debug" }
        symbols "On"
        buildoptions { "-Wall", "-Wextra", "-Wpedantic", "-Wnull-dereference", "-Wmisleading-indentation" }

    filter { "configurations:release" }
        optimize "On"
        buildoptions { "-O3", "-Wall", "-Wextra", "-Wpedantic", "-Wnull-dereference", "-Wmisleading-indentation" }

    filter { }

project (module_name)
    kind "SharedLib"
    files "**"
    includedirs { ".", "sol2/include" }

    if realm == "CLIENT" then
        defines { "LUNAR_CLIENT_MODULE" }
    end

    if is_windows and arch == "x64" then
        defines { "LUNAR_WINDOWS_x64" }
    end

function getCompiledBinaryPath()
    return "./build/bin/" .. getModulePrefix() .. "_" .. module_name .. "_linux.dll"
end

function getInstallpath()
    return install_dir .. getModulePrefix() .. "_" .. module_name .. "_linux.dll"
end

newaction {
    trigger     = "clean",
    description = "clean the software",
    execute     = function()
        os.rmdir("./build")
        os.rmdir("./makefiles")
    end
}

newaction {
    trigger     = "verify",
    description = "verify the compiled binary",
    execute     = function()
        local out = os.outputof("file " .. getCompiledBinaryPath())

        if out:find("ELF 32-bit LSB pie executable", 1, true) then
            if out:find("debug_info", 1, true) then
                print("Binary is valid and is a debug build")
            else
                print("Binary is valid and is a release build")
            end
        else
            print("Error: Invalid binary format")
        end
    end
}

newaction {
    trigger     = "install",
    description = "install the library",
    execute     = function()
        
        if not os.copyfile(getCompiledBinaryPath(), getInstallpath()) then
            print("Error: Could not copy file. File permissions issue?")
        else
            print("~ cp " .. getCompiledBinaryPath() .. " " .. getInstallpath())
            print("Installed module successfully. Remember that gmod caches modules so you will" ..
                  " need to restart your server for changes to take effect.")
        end
    end
}