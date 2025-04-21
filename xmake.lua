add_rules("mode.debug", "mode.release")

set_project("oj")
set_version("0.0.0")
set_languages("cxx11")

target("oj", function()
	set_kind("binary")
	add_files("src/main.cpp")

	add_cflags("-O2", "-Wall", "-Wextra")
	add_defines("ONLINE_JUDGE")

	if is_mode("debug") then
		add_defines("DEBUG")
	end

	add_links("m")
end)
