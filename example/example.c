#include <stdio.h>
#include "stylice.h"

int main() {
	table instance;

	printf("\nDefault Style: No Header\n");
	if (table_Init(&instance, styleDefault, false) == false) {
		table_AddRow(&instance, "Serial No\tTitle\n");
		table_AddRow(&instance, "01\tThis should be very long\n");
		table_AddRow(&instance, "02\tShould be shorter\n");
		table_AddRow(&instance, "03\tShort\n");
		table_Print(&instance);
	}

	printf("\nDefault Style: Header\n");
	if (table_Init(&instance, styleDefault, true) == false) {
		table_AddRow(&instance, "ID\tLocation\tPopulation\tTest\n");
		table_AddRow(&instance, "01\tKarachi, PK\t15M\tYes\n");
		table_AddRow(&instance, "02\tLondon, UK\t9M\tYes\n");
		table_AddRow(&instance, "03\tLos Angeles, US\t4M\tYes\n");
		table_AddRow(&instance, "04\tBerlin, DE\t3.6M\tNo\n");
		table_AddRow(&instance, "05\tToronto, CA\t3M\tYes\n");
		table_Print(&instance);
	}

	printf("\nCompact Style: No Header\n");
	if (table_Init(&instance, styleCompact, false) == false) {
		table_AddRow(&instance, "A\tquick\tbrown\tfox\n");
		table_AddRow(&instance, "jumps\tover a\tlazy\tdog\n");
		table_Print(&instance);
	}

	printf("\nCompact Style: Header\n");
	if (table_Init(&instance, styleCompact, true) == false) {
		table_AddRow(&instance, "#\tTask\tTime\n");
		table_AddRow(&instance, "01\tWake up!\t0630\n");
		table_Print(&instance);
	}

	getch();
	return 0;
}