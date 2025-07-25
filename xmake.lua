---@diagnostic disable: param-type-mismatch

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", { outputdir = "build", lsp = "clangd" })

set_policy("build.always_update_configfiles", true)
set_policy("run.autobuild", true)

set_project("vjudge")
set_version("0.0.0")
set_languages("gnuxx14")

target("vjudge", function()
	set_kind("binary")
	add_files("src/main.cpp")

	add_cxxflags("-O2", "-Wall", "-Wextra")

	add_defines("LOCAL_JUDGE")

	if is_mode("debug") then
		add_defines("DEBUG")
	end

	add_links("m")
end)
