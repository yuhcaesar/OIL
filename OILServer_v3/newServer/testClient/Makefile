target:=operate
objects:=./src/operate.o

CXXFLAGS += -std=gnu++11

$(target):$(objects)
	$(CXX) -o $(target) $(objects)

clean:
	-@rm $(target)
	-@rm $(objects)
