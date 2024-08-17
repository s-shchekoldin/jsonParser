
TEST_TARGET = jsonParserTest
PERF_TARGET = jsonParserPerf
FLAGS = -g -O3 -march=native
GCC = g++

all: output version native profile

output:
	$(GCC) $(FLAGS) -Wall -Wextra -Werror -Werror=pedantic json.cc test.cc -o $(TEST_TARGET)
	./$(TEST_TARGET) > output.txt
	cat output.txt

version:
	$(GCC) --version

native:
	@echo "\tNative Code Test:"
	$(GCC) $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	taskset -c 0 ./$(PERF_TARGET)

profile:
	@echo "\tProfile Code Test:"
	$(GCC) -fprofile-generate=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	./$(PERF_TARGET)
	$(GCC) -fprofile-use=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	taskset -c 0 ./$(PERF_TARGET)

valgrind:
	@echo "\tValgrind Native Code:"
	$(GCC) -DREPEAT_COUNT=1000000 $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(PERF_TARGET)
	
	@echo "\tValgrind Profile Code:"
	$(GCC) -DREPEAT_COUNT=1000000 -fprofile-generate=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	./$(PERF_TARGET)
	$(GCC) -DREPEAT_COUNT=1000000 -fprofile-use=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(PERF_TARGET)

clean:
	rm -f $(TEST_TARGET) $(PERF_TARGET) cachegrind.out.*
