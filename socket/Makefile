all: server client

server: server.cpp
	g++ $^ -o $@

client: client.cpp
	g++ $^ -o $@

.PHONY: clean run_server run_client

clean:
	rm -f server client

run_server: server
	./server &

run_client: client
	./client
