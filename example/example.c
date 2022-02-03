#include <stdio.h>
#include "stylice.h"

int main() {
	table instance;

	printf("\nDefault Style: No Header\n");
	if (table_Init(&instance, styleDefault, false) == false) {
		table_AddRow(&instance, "Serial No\tTitle");
		table_AddRow(&instance, "01\tThis should be very long");
		table_AddRow(&instance, "02\tShould be shorter");
		table_AddRow(&instance, "03\tShort");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
	}

	printf("\nDefault Style: Header\n");
	if (table_Init(&instance, styleDefault, true) == false) {
		table_AddRow(&instance, "ID\tLocation\tPopulation\tTest");
		table_AddRow(&instance, "01\tKarachi, PK\t15M\tYes");
		table_AddRow(&instance, "02\tLondon, UK\t9M\tYes");
		table_AddRow(&instance, "03\tLos Angeles, US\t4M\tYes");
		table_AddRow(&instance, "04\tBerlin, DE\t3.6M\tNo");
		table_AddRow(&instance, "05\tToronto, CA\t3M\tYes");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
	}

	printf("\nCompact Style: No Header\n");
	if (table_Init(&instance, styleCompact, false) == false) {
		table_AddRow(&instance, "A\tquick\tbrown\tfox");
		table_AddRow(&instance, "jumps\tover a\tlazy\tdog");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
	}

	printf("\nCompact Style: Header\n");
	if (table_Init(&instance, styleCompact, true) == false) {
		table_AddRow(&instance, "#\tTask\tTime");
		table_AddRow(&instance, "01\tWake up!\t0630");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
	}

	getch();
	return 0;
}