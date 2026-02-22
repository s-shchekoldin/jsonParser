
TARGET = jsonRust

rust-r:
	rustc -C debuginfo=0 -C opt-level=3 main.rs -o $(TARGET)

rust-d:
	rustc main.rs -o $(TARGET)

clean:
	rm -f $(TARGET)

