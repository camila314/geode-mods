for mod_name in */; do
	if [ -f "$mod_name/mod.json" ]; then
		mod_name=${mod_name:0:-1}
		args=""
		if [ -f "built/$mod_name/$mod_name.dll" ]; then
			args="$args --binary built/$mod_name/$mod_name.dll"
		fi
		if [ -f "built/$mod_name/lib$mod_name.dylib" ]; then
			args="$args --binary built/$mod_name/lib$mod_name.dylib"
		fi
		./geode.exe package new $mod_name $args --output $mod_name.geode
	fi
done