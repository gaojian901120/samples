# Makefile for httpd
CC=gcc
CFLAGS=-Wl,-rpath,/usr/local/libevent/lib/ -L/usr/local/libevent/lib/ -levent -I/usr/local/libevent/include/ -O2 -g

httpd: httpd.c
	$(CC) -o httpd httpd.c $(CFLAGS)
	@echo ""
	@echo "httpd build complete."
	@echo ""	

clean: httpd
	rm -f httpd
