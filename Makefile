all:
	nvcc main.cu -o main
	./main
	rm main

