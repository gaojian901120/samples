#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdint.h>

int main() {
  struct in6_addr ipv6;
  struct in_addr ipv4;
  char *addr1, *addr2, *addr3;
  uint16_t *p16;
  uint32_t p32;
  int i;

  memset(&ipv6, 0, sizeof(ipv6));
  memset(&ipv4, 0, sizeof(ipv4));
  addr1 = strdup("2a01:198:603:0:396e:4789:8e99:890f");
  addr2 = strdup("2a01:198:603:0::");
  addr3 = strdup("88.88.88.88");

  if(inet_pton(AF_INET6, addr1, &ipv6)) {
    p16 = (uint16_t *)&(ipv6.s6_addr16);
    for (i=0; i<8; i++) {
      p16[i] = ntohs(p16[i]);
      printf("%d\n", p16[i]);
    }
  }
  printf("========\n");
  if(inet_pton(AF_INET6, addr2, &ipv6)) {
    p16 = (uint16_t *)&(ipv6.s6_addr16);
    for (i=0; i<8; i++) {
      p16[i] = ntohs(p16[i]);
      printf("%d\n", p16[i]);
    }
  }
  printf("========\n");
  if(inet_pton(AF_INET, addr3, &ipv4)) {
    p32 = ntohl(ipv4.s_addr);
    printf("%d\n", p32);
  }

  return 1;
}