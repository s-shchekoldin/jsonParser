
TARGET = jsonParser

FLAGS = -g -O3 -Wall -Wextra -Werror -Werror=pedantic

all:
	g++ $(FLAGS) json.cc main.cc -o $(TARGET) -DDEBUG_MODE2

clean:
	rm -f $(TARGET)
