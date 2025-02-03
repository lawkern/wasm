compile:
	mkdir -p ./build
	$(CC) -g ./src/compiler.c -o ./build/wasmc

run:
	./build/wasmc
	mv index.wasm ./web/
