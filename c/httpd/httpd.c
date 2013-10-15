#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

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
        fprintf(stderr, "Error: Unable to listen on %s:%d\n\n", HOST, PORT);
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
    /*  header  */  
    evhttp_add_header(req->output_headers, "Content-Type", "text/plain");  
    evhttp_add_header(req->output_headers, "Connection", "keep-alive");  
    evhttp_add_header(req->output_headers, "Cache-Control", "no-cache");  
    evhttp_add_header(req->output_headers, "Author", "D.J.");  
    
    if(http_input_opt != NULL && http_input_name != NULL && strlen(http_input_name) < 300){  
        /*  GET Method,OUT The Queue  */  
        if(strcmp(http_input_opt,"put") == 0){  
            int buffer_data_len = EVBUFFER_LENGTH(req->input_buffer);  
            if(buffer_data_len > 0){ /* POST METHOD */  
                char *input_value_data = (char *) EVBUFFER_DATA(req->input_buffer); /* Submited Data */  
                fprintf(stderr,"%s \n",input_value_data);  
            }else if(http_input_data != NULL){  
                fprintf(stderr,"%s \n",http_input_data);  
            }  
        }else if(strcmp(http_input_opt,"get") == 0){  
        }  
    }  
  
    /*  Response the client  */  
    evhttp_send_reply(req, HTTP_OK, "OK", buf);  
  
    evbuffer_add_printf(buf, "%s", "HTTP_AUTH_FAILED");  
  
    /*  Release the memory  */  
    evhttp_clear_headers(&http_query);  
           
    evbuffer_free(buf);      
}
