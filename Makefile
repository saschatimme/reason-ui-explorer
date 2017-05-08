path-bs-react-native = ../bs-react-native

copy-and-make-world:
	@ echo "file changed - copy files"; \
	rm -rR ./node_modules/bs-react-native/src; \
	cp -R $(path-bs-react-native)/src ./node_modules/bs-react-native/src; \
	echo "make-world"; \
	./node_modules/.bin/bsb -clean-world -make-world &>/dev/null; \
	echo "done"; \

watch:
	@ echo "Start watching: $(path-bs-react-native)/src" ;\
	fswatch -0 -o -r $(path-bs-react-native)/src | xargs -0 -n 1 make copy-and-make-world