all:
	g++ src/* -o Ejecutable.exe -Iinclude -Iinclude/freetype2 -Llib -lglfw3 -lopengl32 -lgdi32 -O2