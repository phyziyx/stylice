#include "stylice.h"
#include <stdio.h>
#include <conio.h>

int main() {
	table instance;

	printf("\nDefault Style: No Header\n");
	if (table_Init(&instance, styleDefault, false) == true) {
		table_AddRow(&instance, "Serial No\tTitle");
		table_AddRow(&instance, "01\tThis should be very long");
		table_AddRow(&instance, "02\tShould be shorter");
		table_AddRow(&instance, "03\tShort");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
		table_Delete(&instance);
	}

	printf("\nDefault Style: Header\n");
	if (table_Init(&instance, styleDefault, true) == true) {
		table_AddRow(&instance, "ID\tLocation\tPopulation\tTest");
		table_AddRow(&instance, "01\tKarachi, PK\t15M\tYes");
		table_AddRow(&instance, "02\tLondon, UK\t9M\tYes");
		table_AddRow(&instance, "03\tLos Angeles, US\t4M\tYes");
		table_AddRow(&instance, "04\tBerlin, DE\t3.6M\tNo");
		table_AddRow(&instance, "05\tToronto, CA\t3M\tYes");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
		table_Delete(&instance);
	}

	printf("\nCompact Style: No Header\n");
	if (table_Init(&instance, styleCompact, false) == true) {
		table_AddRow(&instance, "##\tTask\tTime");
		table_AddRow(&instance, "01\tWake up!\t0630");
		table_AddRow(&instance, "03\tWrite Code!\t0730");
		table_AddRow(&instance, "04\tSleep!\t2200");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
		table_Delete(&instance);
	}

	printf("\nCompact Style: Header\n");
	if (table_Init(&instance, styleCompact, true) == true) {
		table_AddRow(&instance, "##\tTask\tTime");
		table_AddRow(&instance, "01\tWake up!\t0630");
		table_AddRow(&instance, "03\tWrite Code!\t0730");
		table_AddRow(&instance, "04\tSleep!\t2200");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
		table_Delete(&instance);
	}

	printf("\nWindows Style: Header\n");
	if (table_Init(&instance, styleWindows, true) == true) {
		table_AddRow(&instance, "##\tTask\tTime");
		table_AddRow(&instance, "01\tWake up!\t0630");
		table_AddRow(&instance, "03\tWrite Code!\t0730");
		table_AddRow(&instance, "04\tSleep!\t2200");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
		table_Delete(&instance);
	}

	printf("\nWindows Style: No Header\n");
	if (table_Init(&instance, styleWindows, false) == true) {
		table_AddRow(&instance, "##\tTask\tTime");
		table_AddRow(&instance, "01\tWake up!\t0630");
		table_AddRow(&instance, "03\tWrite Code!\t0730");
		table_AddRow(&instance, "04\tSleep!\t2200");
		table_Print(&instance);
		printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
		table_Delete(&instance);
	}

	getch();
	return 0;
}