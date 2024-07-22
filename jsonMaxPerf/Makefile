
TEST_TARGET = jsonParserTest
PERF_TARGET = jsonParserPerf
FLAGS = -g -O3

all: output version native profile valgrind

output:
	g++ $(FLAGS) -Wall -Wextra -Werror -Werror=pedantic json.cc test.cc -o $(TEST_TARGET)
	./$(TEST_TARGET) > output.txt
	cat output.txt

version:
	g++ --version

native:
	@echo "\tNative Code Test:"
	g++ $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	taskset -c 0 ./$(PERF_TARGET)

profile:
	@echo "\tProfile Code Test:"
	g++ -fprofile-generate=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	./$(PERF_TARGET)
	g++ -fprofile-use=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	taskset -c 0 ./$(PERF_TARGET)

valgrind:
	@echo "\tValgrind Native Code:"
	g++ -DREPEAT_COUNT=1000000 $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(PERF_TARGET)
	
	@echo "\tValgrind Profile Code:"
	g++ -DREPEAT_COUNT=1000000 -fprofile-generate=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	./$(PERF_TARGET)
	g++ -DREPEAT_COUNT=1000000 -fprofile-use=gcda $(FLAGS) json.cc perf.cc -I./ -o $(PERF_TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(PERF_TARGET)

clean:
	rm -f $(TEST_TARGET) $(PERF_TARGET) cachegrind.out.*
