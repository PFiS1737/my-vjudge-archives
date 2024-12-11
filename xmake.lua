add_rules("mode.debug", "mode.release")

set_project("oj")
set_version("0.0.0")
set_languages("c99")

target("oj", function()
	set_kind("binary")
	add_files("src/__main__.c")

	add_cflags("-O2", "-Wall", "-Wextra", "-Wno-deprecated-declarations")
	add_defines("ONLINE_JUDGE")

	if is_mode("debug") then
		add_defines("DEBUG")
	end

	add_links("m")
end)
