#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

int main (void) {
	const char *s_1 = "99";
	const char *s_2 = "Ricardo Faria da Costa";
	const char *s_3 = "01";
	char str[100];

	int i;

	strcat(str, s_1);
	strcat(str, s_2);
	strcat(str, s_3);

	char *string = str+1;

	printf("%s\n", string);

	unsigned char md5_res[MD5_DIGEST_LENGTH];
	MD5(string, strlen(string), md5_res);
	for(i = 0; i < MD5_DIGEST_LENGTH; i++)
		printf("%02x", md5_res[i]);
	putchar("\n");

	printf("\n");

	unsigned char sha_res[SHA_DIGEST_LENGTH];
	SHA1(string, strlen(string), sha_res);
	for(i = 0; i < SHA_DIGEST_LENGTH; i++)
		printf("%02x", sha_res[i]);
	putchar("\n");

	printf("\n");

	unsigned char *sha_256 = SHA256(string, strlen(string), 0);
	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", sha_256[i]);
	putchar('\n');

	return 0;
}
