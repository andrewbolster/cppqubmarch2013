#include <stdio.h>

void writeData(FILE * fp) {
	fprintf(fp,"abc def 123\n");
	fprintf(fp,"abc DEF ghi\n");
	fprintf(fp,"abc 456 ghi\n");
	fprintf(fp,"789 def GHI\n");
}

int main() {
	const char * command1 = "egrep [A-Z]{3}";
	const char * command2 = "egrep [0-9]{3}";
	const char * command3 = "egrep ghi$";

	FILE * fp1 = popen(command1, "w");
	FILE * fp2 = popen(command2, "w");
	FILE * fp3 = popen(command3, "w");

	printf("### About to send input to '%s' ###\n", command1);
	writeData(fp1);
	pclose(fp1);

	printf("### About to send input to '%s' ###\n", command2);
	writeData(fp2);
	pclose(fp2);

	printf("### About to send input to '%s' ###\n", command3);
	writeData(fp3);
	pclose(fp3);
}
