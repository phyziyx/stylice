#ifndef __STYLICE_H__
#define __STYLICE_H__

#include <stdbool.h>

enum tableStyle {
	styleDefault = 0,
	styleMax
};

typedef struct tableData {
	int ColumnsLen[16];
	// int RowCount;
	enum tableStyle Style;
	char Rows[2048];
} table;

bool table_Init(table *self, enum tableStyle style);
void table_AddRow(table *self, const char *format);
void table_Print(table *self);

#endif