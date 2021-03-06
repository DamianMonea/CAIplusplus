all:
	nvcc -I/home/damian/anaconda2/include/python2.7 -w -std=c++11 CAI++.cu -o CAI++
	#python util.py &
	./CAI++
	rm CAI++
	#pkill python

build:
	nvcc -I/home/damian/anaconda2/include/python2.7 -w CAI++.cu -o CAI++

open:
	code CAI++.cu
	code Layers.h
	code NeuralNetwork.h
	code Neuron.h
	code Objects.h

rot:
	nvcc -W rotate.cu -o rotate

