# Makefile for httpd
CC=gcc
CFLAGS=-Wall -L/usr/local/libevent/lib/ -levent -I/usr/local/libevent/include/ -O2 -g

#cat > /etc/ld.so.conf.d/libevent-x86_64.conf <<EOF
#    /usr/local/libevent/lib/
#EOF

httpd: httpd.c
	@if [ ! -f /etc/ld.so.conf.d/libevent-x86_64.conf ]; then \
		echo '/usr/local/libevent/lib/' > /etc/ld.so.conf.d/libevent-x86_64.conf; \
	fi
	$(CC) -o httpd httpd.c $(CFLAGS)
	@echo ""
	@echo "httpd build complete."
	@echo ""	

clean: httpd
	rm -f httpd
