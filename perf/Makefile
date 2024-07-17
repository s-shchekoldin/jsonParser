
TARGET = perfJson
LDFLAGS = -g -O3 -I../ ../json.cc

ifdef rapidjson
    LDFLAGS += -DTEST_RAPIDJSON
endif

all:
	g++ --version
	
	@echo "\tNative Code Test:"
	g++ $(LDFLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	taskset -c 0 ./$(TARGET)
	
	@echo "\tProfile Code Test:"
	g++ -fprofile-generate=gcda $(LDFLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	./$(TARGET)
	g++ -fprofile-use=gcda $(LDFLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	taskset -c 0 ./$(TARGET)
	
	@echo "\tValgrind Native Code:"
	g++ -DREPEAT_COUT=1000000 $(LDFLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(TARGET)
	
	@echo "\tValgrind Profile Code:"
	g++ -DREPEAT_COUT=1000000 -fprofile-generate=gcda $(LDFLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	./$(TARGET)
	g++ -DREPEAT_COUT=1000000 -fprofile-use=gcda $(LDFLAGS) $(shell find ./ -name '*.cc') -I./ -o $(TARGET)
	valgrind --tool=cachegrind --cache-sim=yes --branch-sim=yes ./$(TARGET)

clean:
	rm -f $(TARGET) cachegrind.out.*
