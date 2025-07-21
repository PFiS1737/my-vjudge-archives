add_rules("mode.debug", "mode.release")

set_project("vjudge")
set_version("0.0.0")
set_languages("gnuxx14")

target("vjudge", function()
	set_kind("binary")
	add_files("src/main.cpp")

	add_cxxflags("-O2", "-Wall", "-Wextra")

	add_defines("ONLINE_JUDGE")

	if is_mode("debug") then
		add_defines("DEBUG")
	end

	add_links("m")
end)
