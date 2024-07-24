
TARGET = perfJson
FLAGS = -g -O3
GCC = g++

all: version native profile

version:
	$(GCC) --version

native:
	@echo "\tNative Code Test:"
	$(GCC) $(FLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	taskset -c 0 ./$(TARGET)

profile:
	@echo "\tProfile Code Test:"
	$(GCC) -fprofile-generate=gcda $(FLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	./$(TARGET)
	$(GCC) -fprofile-use=gcda $(FLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	taskset -c 0 ./$(TARGET)

valgrind:
	@echo "\tValgrind Native Code:"
	$(GCC) -DREPEAT_COUNT=1000000 $(FLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(TARGET)
	
	@echo "\tValgrind Profile Code:"
	$(GCC) -DREPEAT_COUNT=1000000 -fprofile-generate=gcda $(FLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	./$(TARGET)
	$(GCC) -DREPEAT_COUNT=1000000 -fprofile-use=gcda $(FLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(TARGET)

clean:
	rm -f $(TARGET) cachegrind.out.*
