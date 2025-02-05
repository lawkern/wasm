compile:
	mkdir -p ./build
	$(CC) -g ./src/compiler.c -o ./build/wasmc
	$(CC) -g ./src/interpreter.c -o ./build/wasmi

run:
	./build/wasmc
	mv index.wasm ./web/
	./build/wasmi
