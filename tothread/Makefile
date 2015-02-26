TARGET = tlua2

$(TARGET):$(TARGET).c
	gcc -g -o $@ $< -I/usr/local/include/ -L/usr/local/lib/ -llua  -lm -ldl

test:
	./$(TARGET)

clean:
	rm -r $(TARGET)

