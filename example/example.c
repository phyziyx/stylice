#include "stylice.h"

int main() {
	table instance;

	if (table_Init(&instance, styleDefault) == false) {
		table_AddRow(&instance, "Serial No\tTitle\n");
		table_AddRow(&instance, "01\tThis should be very long\n");
		table_AddRow(&instance, "02\tShould be shorter\n");
		table_AddRow(&instance, "03\tShort\n");
		table_Print(&instance);
	}

	if (table_Init(&instance, styleDefault) == false) {
		table_AddRow(&instance, "ID\tLocation\tPopulation\tTest\n");
		table_AddRow(&instance, "01\tKarachi, PK\t15M\tYes\n");
		table_AddRow(&instance, "02\tLondon, UK\t9M\tYes\n");
		table_AddRow(&instance, "03\tToronto, CA\t3M\tYes\n");
		table_AddRow(&instance, "04\tLos Angeles, US\t4M\tYes\n");
		table_AddRow(&instance, "05\tBerlin, DE\t3.6M\tNo\n");
		table_Print(&instance);
	}

	getch();
	return 0;
}