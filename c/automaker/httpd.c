#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <err.h>
#include <event.h>
#include <evhttp.h>

#include "httpd.h"

void http_handle(struct evhttp_request *req, void *arg);

int main() {
    struct evhttp *httpd;
    event_init();
    httpd = evhttp_start(HOST,PORT);
    if(httpd == NULL) {
        fprintf(stderr, "Error: Unable to listen on %s:%d\n\n");
        exit(1);
    }
    evhttp_set_timeout(httpd,2000);
    evhttp_set_gencb(httpd, http_handle, NULL);
    event_dispatch();
    evhttp_free(httpd);
    
    return 0;
}
void http_handle(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf;
    buf = evbuffer_new();
    char *decode_uri = strdup((char *) evhttp_request_uri(req));
    struct evkeyvalq http_query;
    evhttp_parse_query(decode_uri, &http_query);
    free(decode_uri);

    const char *http_input_opt = evhttp_find_header(&http_query, "opt"); /* Operation Type */  
    const char *http_input_name = evhttp_find_header(&http_query, "name"); /* Queue Name */  
    const char *http_input_data = evhttp_find_header(&http_query, "data"); /* Data With GET */ 
    
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
    evbuffer_free(buf);
    fprintf(stderr,data);
}
